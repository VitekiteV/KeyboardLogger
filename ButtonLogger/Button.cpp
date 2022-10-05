#include "Button.h"


Button::Button() : name_(""), pressed_cntr_(0) {}

void Button::SetName(const std::string & name)
{
	name_ = name;
}

std::string Button::GetName() const
{
	return name_;
}

void Button::IncCntr()
{
	++pressed_cntr_;
}

uint32_t Button::GetCntr() const
{
	return pressed_cntr_;
}