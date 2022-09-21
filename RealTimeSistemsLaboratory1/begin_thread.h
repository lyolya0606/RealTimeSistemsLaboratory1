#pragma once
#include <process.h>
#include <Windows.h>
#include <iostream>

#define PRIORITY_COUNT 9

int get_priority_type_thread(int priority);
int choose_priority_thread(void);
unsigned int __stdcall mythread(void* data);
void begin_thread_index(void);