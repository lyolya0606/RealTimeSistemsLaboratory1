#include "begin_thread.h"

void begin_thread_index(void) {
  std::cout << "Enter amount of threads:";
  int threadCount;
  std::cin >> threadCount;

  HANDLE* myThreads = new HANDLE[threadCount];

  for (int i = 0; i < threadCount; i++) {
    myThreads[i] = (HANDLE)_beginthreadex(0, 0, &mythread, 0, CREATE_SUSPENDED, 0);
  }

  if (myThreads == NULL) {
    throw new std::exception("Could't create thread");
  }

  for (int i = 0; i < threadCount; i++) {
    if (myThreads[i] != 0) {
      SetThreadPriority(myThreads[i], choose_priority_thread());
    }
  }

  for (int i = 0; i < threadCount; i++) {
    std::cout << "Thread " << i << "; Priority is " << GetThreadPriority(myThreads[i]) << std::endl;
  }

  for (int i = 0; i < threadCount; i++) {
    ResumeThread(myThreads[i]);
  }

  WaitForMultipleObjects(threadCount, myThreads, true, INFINITE);

  for (int i = 0; i < threadCount; i++) {
    CloseHandle(myThreads[i]);
  }
}

unsigned int __stdcall mythread(void* data) {
  std::cout << GetCurrentThreadId() << std::endl;
  return 0;
}

int choose_priority_thread(void) {
  int priority = THREAD_PRIORITY_NORMAL;

  std::cout << "Choose priority" << std::endl;
  std::cout << "1 - THREAD_MODE_BACKGROUND_BEGIN" << std::endl;
  std::cout << "2 - THREAD_MODE_BACKGROUND_END" << std::endl;
  std::cout << "3 - THREAD_PRIORITY_ABOVE_NORMAL" << std::endl;
  std::cout << "4 - THREAD_PRIORITY_BELOW_NORMAL" << std::endl;
  std::cout << "5 - THREAD_PRIORITY_HIGHEST" << std::endl;
  std::cout << "6 - THREAD_PRIORITY_IDLE" << std::endl;
  std::cout << "7 - THREAD_PRIORITY_LOWEST" << std::endl;
  std::cout << "8 - THREAD_PRIORITY_NORMAL" << std::endl;
  std::cout << "9 - THREAD_PRIORITY_TIME_CRITICAL" << std::endl;
  std::cout << "Enter number: ";
  std::cin >> priority;
  return get_priority_type_thread(priority);
}

int get_priority_type_thread(int priority) {
  switch (priority) {
  case 1:
    return THREAD_MODE_BACKGROUND_BEGIN;
    break;
  case 2:
    return THREAD_MODE_BACKGROUND_END;
    break;
  case 3:
    return THREAD_PRIORITY_ABOVE_NORMAL;
    break;
  case 4:
    return THREAD_PRIORITY_BELOW_NORMAL;
    break;
  case 5:
    return THREAD_PRIORITY_HIGHEST;
    break;
  case 6:
    return THREAD_PRIORITY_IDLE;
    break;
  case 7:
    return THREAD_PRIORITY_LOWEST;
    break;
  case 8:
    return THREAD_PRIORITY_NORMAL;
    break;
  case 9:
    return THREAD_PRIORITY_TIME_CRITICAL;
    break;
  default:
    throw new std::exception("Nonexisting priority");
  }
}