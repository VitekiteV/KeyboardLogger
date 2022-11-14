#define _CRT_SECURE_NO_WARNINGS
#include "LoggerFunctions.h"
#include <Windows.h>
#include <iostream>
#include <array>
#include <fstream>
#include "Keyboard.h"
#include "Button.h"
#include <iomanip>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

static std::array<int, 5> mouse_keys = { 0 };
static Keyboard keyboard;


void SetMouseHook()
{
	if (!mouse_hook)
	{
		mouse_hook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, NULL, 0);
		std::cout << "mouse hook is setted\n";
	}
}

void SetKeyboardHook()
{
	if (!keyboard_hook)
	{
		keyboard_hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
		std::cout << "kb hook is setted\n";
	}
}

void UnsetHook(HHOOK& hook)
{
	if (hook)
	{
		UnhookWindowsHookEx(hook);
		std::cout << "hook is unsetted\n";
	}
	else
		std::cout << "hook is not unsetted\n";
	hook = nullptr;
}

LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		if (wParam == WM_LBUTTONUP)
			SaveMouseKey(0);
		else if (wParam == WM_RBUTTONUP)
			SaveMouseKey(1);
		else if (wParam == WM_XBUTTONUP)
		{
			auto lparam_struct = *(reinterpret_cast<tagMSLLHOOKSTRUCT*>(lParam));
			int key_code = static_cast<int>(GET_XBUTTON_WPARAM(lparam_struct.mouseData));
			SaveMouseKey(1 + key_code);
		}
		else if (wParam == WM_MBUTTONUP)
			SaveMouseKey(4);
	}

	return CallNextHookEx(mouse_hook, nCode, wParam, lParam);
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
		{
			auto lparam_struct = *(reinterpret_cast<tagKBDLLHOOKSTRUCT*>(lParam));
			int key_code = static_cast<int>(lparam_struct.vkCode);
			SaveKeyboardKey(key_code);
		}
	}

	return CallNextHookEx(keyboard_hook, nCode, wParam, lParam);
}


void SaveMouseKey(const int num)
{
	if (num >= 0 && num <=4)
		++mouse_keys[num];
}

void ReadMouseReg()
{
	std::cout << "==================\n";
	std::cout << "Mouse buttons presssed:\nleft - " << mouse_keys[0] << "\nright - " << mouse_keys[1] <<
				 "\nback - " << mouse_keys[2] << "\nforward - " << mouse_keys[3] << "\nwheel - " << mouse_keys[4];
	std::cout << "\n==================\n";
}


void SaveKeyboardKey(const int vk_code)
{
	if (vk_code == 0x1B)
		keyboard.IncKeyCntr(0);
	else if (vk_code == 0x70)
		keyboard.IncKeyCntr(1);
	else if (vk_code == 0x71)
		keyboard.IncKeyCntr(2);
	else if (vk_code == 0x72)
		keyboard.IncKeyCntr(3);
	else if (vk_code == 0x73)
		keyboard.IncKeyCntr(4);
	else if (vk_code == 0x74)
		keyboard.IncKeyCntr(5);
	else if (vk_code == 0x75)
		keyboard.IncKeyCntr(6);
	else if (vk_code == 0x76)
		keyboard.IncKeyCntr(7);
	else if (vk_code == 0x77)
		keyboard.IncKeyCntr(8);
	else if (vk_code == 0x78)
		keyboard.IncKeyCntr(9);
	else if (vk_code == 0x79)
		keyboard.IncKeyCntr(10);
	else if (vk_code == 0x7A)
		keyboard.IncKeyCntr(11);
	else if (vk_code == 0x7B)
		keyboard.IncKeyCntr(12);
	else if (vk_code == 0x2C)
		keyboard.IncKeyCntr(13);
	else if (vk_code == 0x91)
		keyboard.IncKeyCntr(14);
	else if (vk_code == 0x13)
		keyboard.IncKeyCntr(15);
	else if (vk_code == 0xC0)
		keyboard.IncKeyCntr(16);
	else if (vk_code == 0x31)
		keyboard.IncKeyCntr(17);
	else if (vk_code == 0x32)
		keyboard.IncKeyCntr(18);
	else if (vk_code == 0x33)
		keyboard.IncKeyCntr(19);
	else if (vk_code == 0x34)
		keyboard.IncKeyCntr(20);
	else if (vk_code == 0x35)
		keyboard.IncKeyCntr(21);
	else if (vk_code == 0x36)
		keyboard.IncKeyCntr(22);
	else if (vk_code == 0x37)
		keyboard.IncKeyCntr(23);
	else if (vk_code == 0x38)
		keyboard.IncKeyCntr(24);
	else if (vk_code == 0x39)
		keyboard.IncKeyCntr(25);
	else if (vk_code == 0x30)
		keyboard.IncKeyCntr(26);
	else if (vk_code == 0xBD)
		keyboard.IncKeyCntr(27);
	else if (vk_code == 0xBB)
		keyboard.IncKeyCntr(28);
	else if (vk_code == 0xDC)
		keyboard.IncKeyCntr(29);
	else if (vk_code == 0x08)
		keyboard.IncKeyCntr(30);
	else if (vk_code == 0x09)
		keyboard.IncKeyCntr(31);
	else if (vk_code == 0x51)
		keyboard.IncKeyCntr(32);
	else if (vk_code == 0x57)
		keyboard.IncKeyCntr(33);
	else if (vk_code == 0x45)
		keyboard.IncKeyCntr(34);
	else if (vk_code == 0x52)
		keyboard.IncKeyCntr(35);
	else if (vk_code == 0x54)
		keyboard.IncKeyCntr(36);
	else if (vk_code == 0x59)
		keyboard.IncKeyCntr(37);
	else if (vk_code == 0x55)
		keyboard.IncKeyCntr(38);
	else if (vk_code == 0x49)
		keyboard.IncKeyCntr(39);
	else if (vk_code == 0x4F)
		keyboard.IncKeyCntr(40);
	else if (vk_code == 0x50)
		keyboard.IncKeyCntr(41);
	else if (vk_code == 0xDB)
		keyboard.IncKeyCntr(42);
	else if (vk_code == 0xDD)
		keyboard.IncKeyCntr(43);
	else if (vk_code == 0x14)
		keyboard.IncKeyCntr(44);
	else if (vk_code == 0x41)
		keyboard.IncKeyCntr(45);
	else if (vk_code == 0x53)
		keyboard.IncKeyCntr(46);
	else if (vk_code == 0x44)
		keyboard.IncKeyCntr(47);
	else if (vk_code == 0x46)
		keyboard.IncKeyCntr(48);
	else if (vk_code == 0x47)
		keyboard.IncKeyCntr(49);
	else if (vk_code == 0x48)
		keyboard.IncKeyCntr(50);
	else if (vk_code == 0x4A)
		keyboard.IncKeyCntr(51);
	else if (vk_code == 0x4B)
		keyboard.IncKeyCntr(52);
	else if (vk_code == 0x4C)
		keyboard.IncKeyCntr(53);
	else if (vk_code == 0xBA)
		keyboard.IncKeyCntr(54);
	else if (vk_code == 0xDE)
		keyboard.IncKeyCntr(55);
	else if (vk_code == 0x0D)
		keyboard.IncKeyCntr(56);
	else if (vk_code == 0xA0)
		keyboard.IncKeyCntr(57);
	else if (vk_code == 0x5A)
		keyboard.IncKeyCntr(58);
	else if (vk_code == 0x58)
		keyboard.IncKeyCntr(59);
	else if (vk_code == 0x43)
		keyboard.IncKeyCntr(60);
	else if (vk_code == 0x56)
		keyboard.IncKeyCntr(61);
	else if (vk_code == 0x42)
		keyboard.IncKeyCntr(62);
	else if (vk_code == 0x4E)
		keyboard.IncKeyCntr(63);
	else if (vk_code == 0x4D)
		keyboard.IncKeyCntr(64);
	else if (vk_code == 0xBC)
		keyboard.IncKeyCntr(65);
	else if (vk_code == 0xBE)
		keyboard.IncKeyCntr(66);
	else if (vk_code == 0xBF)
		keyboard.IncKeyCntr(67);
	else if (vk_code == 0xA1)
		keyboard.IncKeyCntr(68);
	else if (vk_code == 0xA2)
		keyboard.IncKeyCntr(69);
	else if (vk_code == 0x5B)
		keyboard.IncKeyCntr(70);
	else if (vk_code == 0xA4)
		keyboard.IncKeyCntr(71);
	else if (vk_code == 0x20)
		keyboard.IncKeyCntr(72);
	else if (vk_code == 0xA5)
		keyboard.IncKeyCntr(73);
	else if (vk_code == 0x5C)
		keyboard.IncKeyCntr(74);
	else if (vk_code == 0x5D)
		keyboard.IncKeyCntr(75);
	else if (vk_code == 0xA3)
		keyboard.IncKeyCntr(76);
	else if (vk_code == 0x2D)
		keyboard.IncKeyCntr(77);
	else if (vk_code == 0x24)
		keyboard.IncKeyCntr(78);
	else if (vk_code == 0x21)
		keyboard.IncKeyCntr(79);
	else if (vk_code == 0x2E)
		keyboard.IncKeyCntr(80);
	else if (vk_code == 0x23)
		keyboard.IncKeyCntr(81);
	else if (vk_code == 0x22)
		keyboard.IncKeyCntr(82);
	else if (vk_code == 0x26)
		keyboard.IncKeyCntr(83);
	else if (vk_code == 0x25)
		keyboard.IncKeyCntr(84);
	else if (vk_code == 0x28)
		keyboard.IncKeyCntr(85);
	else if (vk_code == 0x27)
		keyboard.IncKeyCntr(86);
	else if (vk_code == 0x90)
		keyboard.IncKeyCntr(87);
	else if (vk_code == 0x6F)
		keyboard.IncKeyCntr(88);
	else if (vk_code == 0x6A)
		keyboard.IncKeyCntr(89);
	else if (vk_code == 0x6D)
		keyboard.IncKeyCntr(90);
	else if (vk_code == 0x67)
		keyboard.IncKeyCntr(91);
	else if (vk_code == 0x68)
		keyboard.IncKeyCntr(92);
	else if (vk_code == 0x69)
		keyboard.IncKeyCntr(93);
	else if (vk_code == 0x64)
		keyboard.IncKeyCntr(94);
	else if (vk_code == 0x65)
		keyboard.IncKeyCntr(95);
	else if (vk_code == 0x66)
		keyboard.IncKeyCntr(96);
	else if (vk_code == 0x6B)
		keyboard.IncKeyCntr(97);
	else if (vk_code == 0x61)
		keyboard.IncKeyCntr(98);
	else if (vk_code == 0x62)
		keyboard.IncKeyCntr(99);
	else if (vk_code == 0x63)
		keyboard.IncKeyCntr(100);
	else if (vk_code == 0x60)
		keyboard.IncKeyCntr(101);
	else if (vk_code == 0x6E)
		keyboard.IncKeyCntr(102);
}

void ReadKeyboardReg()
{
	std::cout << "==================\n";
	std::cout << "Keyboard buttons presssed:";
	auto buttons = keyboard.GetButtons();
	for (const auto& button : buttons)
		std::cout << "\n" << std::setw(13) << button.GetName() << "\t" << std::setw(6) << button.GetCntr();
	std::cout << "\n==================\n";
}

void SaveStatistic(std::tm* tm_struct)
{
	const fs::path stat_dir("statistics");
	if (!fs::exists(stat_dir))
		fs::create_directory(stat_dir);

	std::string file_name = "statistics/" + std::to_string(tm_struct->tm_mday) + "." + std::to_string(tm_struct->tm_mon+1) + "." + std::to_string(tm_struct->tm_year+1900) + ".txt";
	std::fstream file(file_name, std::ios_base::out, std::ios_base::trunc);
	file << "Mouse buttons:\n\nleft\t" << mouse_keys[0] << "\nright\t" << mouse_keys[1] <<
		"\nback\t" << mouse_keys[2] << "\nforward\t" << mouse_keys[3] << "\nwheel\t" << mouse_keys[4] << "\n\n\n" <<
		"Keyboard buttons:\n";
	auto buttons = keyboard.GetButtons();
	for (const auto& button : buttons)
		file << "\n" << std::setw(13) << button.GetName() << "\t" << std::setw(6) << button.GetCntr();
	file.close();
}

void Menu(const DWORD& thread_id)
{
	std::time_t local_time = time(nullptr);
	std::tm* tm_struct = localtime(&local_time);
	//std::cout << tm_struct->tm_mday << " " << tm_struct->tm_mon + 1 << " " << tm_struct->tm_year + 1900 << "\n";

	while (true)
	{
		std::cout << "==================\n";
		std::cout << "Menu:\n0 - quit\n1 - read mouse register\n2 - read keyboard register\n3 - save statistic in the file\n";
		int val = 0;
		std::cin >> val;
		if (val == 0)
		{
			if (!PostThreadMessageA(thread_id, WM_QUIT, 0, 0))
				std::cout << "failed to quit loop\n";
			break;
		}
		else if (val == 1)
			ReadMouseReg();
		else if (val == 2)
			ReadKeyboardReg();
		else if (val == 3)
			SaveStatistic(tm_struct);
	}
}

void MsgProc()
{
	MSG message;
	BOOL bRet;

	while ((bRet = GetMessage(&message, NULL, 0, 0)) != 0)
	{
		if (bRet == -1)
		{
			break;
		}
		else
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}
	UnsetHook(keyboard_hook);
	UnsetHook(mouse_hook);
}