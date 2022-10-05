#pragma once
#include <string>

class Button
{
public:
	Button();
	void SetName(const std::string& name);
	std::string GetName() const;
	void IncCntr();
	uint32_t GetCntr() const;

private:
	std::string name_;
	uint32_t pressed_cntr_;
};

