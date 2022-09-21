#pragma once
#include <process.h>
#include <Windows.h>
#include <iostream>

unsigned int __stdcall do_work(void* data);
void begin_wait(void);