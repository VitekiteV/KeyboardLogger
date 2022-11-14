#include <Windows.h>
#include "LoggerFunctions.h"
#include <future>
#include <iostream>


int main()
{
	SetKeyboardHook();
	SetMouseHook();

	DWORD thread_id = GetCurrentThreadId();
	auto menu_proc = std::async(std::launch::async, &Menu, std::ref(thread_id));
	MsgProc();
	menu_proc.wait();

	return 0;
}