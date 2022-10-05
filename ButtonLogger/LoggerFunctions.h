#pragma once
#include <Windows.h>

static HHOOK mouse_hook;
static HHOOK keyboard_hook;

void SetMouseHook();
void SetKeyboardHook();
void UnsetHook(HHOOK& hook);
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam,  LPARAM lParam);
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

void SaveMouseKey(const int num);
void ReadMouseReg();

void SaveKeyboardKey(const int vk_code);
void ReadKeyboardReg();

void SaveStatistic();

void Menu(const DWORD& thread_id);
void MsgProc();