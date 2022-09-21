#include "wait.h"

unsigned int __stdcall do_work(void* data) {
  std::cout << "Doing some work..." << std::endl;
  Sleep(2000);
  std::cout << "Main thread is still waiting..." << std::endl;
  Sleep(8000);
  std::cout << "Done!" << std::endl;
  return 0;
}


void begin_wait(void) {
  HANDLE myThread = (HANDLE)_beginthreadex(0, 0, do_work, 0, 0, 0);

  WaitForSingleObject(myThread, INFINITE);

  CloseHandle(myThread);
}