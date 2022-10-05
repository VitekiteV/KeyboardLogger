#include <Windows.h>
#include "LoggerFunctions.h"
#include <future>
#include <iostream>

int main()
{
	SetKeyboardHook();
	SetMouseHook();

	DWORD thread_id = GetCurrentThreadId();
	//auto msg_proc = std::async(std::launch::async, &MsgProc, std::ref(end_flag));
	auto menu_proc = std::async(std::launch::async, &Menu, std::ref(thread_id));
	//Menu(end_flag);
	MsgProc();
	menu_proc.wait();
	//UnsetHook(keyboard_hook);

	return 0;
}