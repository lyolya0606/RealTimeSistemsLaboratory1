#include "create_process.h"
#include <iostream>
#include <Windows.h>
#include <string>


void create_process() {
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  ZeroMemory(&si, sizeof(si));
  ZeroMemory(&pi, sizeof(pi));
  BOOL bCreateProcess = NULL;
  bCreateProcess = CreateProcess(
    L"C:\\gg\\Etxt Antiplagiat\\EtxtAntiplagiat.exe",
    NULL,
    NULL,
    NULL,
    false,
    choose_priority(),
    NULL,
    NULL,
    &si,
    &pi
  );

  if (!bCreateProcess) {
    std::cout << "Fail in process creation, Error No - " << GetLastError() << std::endl;
  } else {
    std::cout << "Create process success" << std::endl;

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
  }
}

int choose_priority(void) {

  std::cout << "Choose priority" << std::endl;
  std::cout << "1 - Low" << std::endl;
  std::cout << "2 - Below normal" << std::endl;
  std::cout << "3 - Normal" << std::endl;
  std::cout << "4 - Above normal" << std::endl;
  std::cout << "5 - High" << std::endl;
  std::cout << "6 - Realtime" << std::endl;
  std::cout << "Enter number: ";

  int priority;
  std::cin >> priority;

  return get_priority_type(priority);
}

int get_priority_type(int priority) {
  switch (priority) {
  case 1:
    return IDLE_PRIORITY_CLASS;
    break;
  case 2:
    return BELOW_NORMAL_PRIORITY_CLASS;
    break;
  case 3:
    return NORMAL_PRIORITY_CLASS;
    break;
  case 4:
    return ABOVE_NORMAL_PRIORITY_CLASS;
    break;
  case 5:
    return HIGH_PRIORITY_CLASS;
    break;
  case 6:
    return REALTIME_PRIORITY_CLASS;
    break;
  default:
    throw new std::exception("Nonexisting priority");
  }
}