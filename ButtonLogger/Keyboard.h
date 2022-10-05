#pragma once
#include <array>
#include "Button.h"

class Keyboard
{
public:
	Keyboard();
	void IncKeyCntr(int index);
	std::array<Button, 103> GetButtons();

private:
	std::array<Button, 103> buttons_;
};

