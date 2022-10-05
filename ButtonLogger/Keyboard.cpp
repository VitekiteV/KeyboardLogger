#include "Keyboard.h"

Keyboard::Keyboard()
{
	buttons_[0].SetName("ESC");
	buttons_[1].SetName("F1");
	buttons_[2].SetName("F2");
	buttons_[3].SetName("F3");
	buttons_[4].SetName("F4");
	buttons_[5].SetName("F5");
	buttons_[6].SetName("F6");
	buttons_[7].SetName("F7");
	buttons_[8].SetName("F8");
	buttons_[9].SetName("F9");
	buttons_[10].SetName("F10");
	buttons_[11].SetName("F11");
	buttons_[12].SetName("F12");
	buttons_[13].SetName("Print Screen");
	buttons_[14].SetName("Scroll Lock");
	buttons_[15].SetName("Pause/Break");
	buttons_[16].SetName("` ~");
	buttons_[17].SetName("1 !");
	buttons_[18].SetName("2 @");
	buttons_[19].SetName("3 #");
	buttons_[20].SetName("4 $");
	buttons_[21].SetName("5 %");
	buttons_[22].SetName("6 ^");
	buttons_[23].SetName("7 &");
	buttons_[24].SetName("8 *");
	buttons_[25].SetName("9 (");
	buttons_[26].SetName("0 )");
	buttons_[27].SetName("- _");
	buttons_[28].SetName("= +");
	buttons_[29].SetName("BACKSLASH |");
	buttons_[30].SetName("Backspace");
	buttons_[31].SetName("Tab");
	buttons_[32].SetName("Q");
	buttons_[33].SetName("W");
	buttons_[34].SetName("E");
	buttons_[35].SetName("R");
	buttons_[36].SetName("T");
	buttons_[37].SetName("Y");
	buttons_[38].SetName("U");
	buttons_[39].SetName("I");
	buttons_[40].SetName("O");
	buttons_[41].SetName("P");
	buttons_[42].SetName("[ {");
	buttons_[43].SetName("] }");
	buttons_[44].SetName("Caps Lock");
	buttons_[45].SetName("A");
	buttons_[46].SetName("S");
	buttons_[47].SetName("D");
	buttons_[48].SetName("F");
	buttons_[49].SetName("G");
	buttons_[50].SetName("H");
	buttons_[51].SetName("J");
	buttons_[52].SetName("K");
	buttons_[53].SetName("L");
	buttons_[54].SetName("; :");
	buttons_[55].SetName("'");
	buttons_[56].SetName("Enter");
	buttons_[57].SetName("Left Shift");
	buttons_[58].SetName("Z");
	buttons_[59].SetName("X");
	buttons_[60].SetName("C");
	buttons_[61].SetName("V");
	buttons_[62].SetName("B");
	buttons_[63].SetName("N");
	buttons_[64].SetName("M");
	buttons_[65].SetName(", <");
	buttons_[66].SetName(". >");
	buttons_[67].SetName("/ ?");
	buttons_[68].SetName("Right Shift");
	buttons_[69].SetName("Left Ctrl");
	buttons_[70].SetName("Left Windows");
	buttons_[71].SetName("Left Alt");
	buttons_[72].SetName("Space");
	buttons_[73].SetName("Right Alt");
	buttons_[74].SetName("Right Windows");
	buttons_[75].SetName("Applications");
	buttons_[76].SetName("Right Ctrl");
	buttons_[77].SetName("Insert");
	buttons_[78].SetName("Home");
	buttons_[79].SetName("Page Up");
	buttons_[80].SetName("Delete");
	buttons_[81].SetName("End");
	buttons_[82].SetName("Page Down");
	buttons_[83].SetName("Up Arrow");
	buttons_[84].SetName("Left Arrow");
	buttons_[85].SetName("Down Arrow");
	buttons_[86].SetName("Right Arrow");
	buttons_[87].SetName("Num Lock");
	buttons_[88].SetName("NumPad /");
	buttons_[89].SetName("NumPad *");
	buttons_[90].SetName("NumPad -");
	buttons_[91].SetName("NumPad 7");
	buttons_[92].SetName("NumPad 8");
	buttons_[93].SetName("NumPad 9");
	buttons_[94].SetName("NumPad 4");
	buttons_[95].SetName("NumPad 5");
	buttons_[96].SetName("NumPad 6");
	buttons_[97].SetName("NumPad +");
	buttons_[98].SetName("NumPad 1");
	buttons_[99].SetName("NumPad 2");
	buttons_[100].SetName("NumPad 3");
	buttons_[101].SetName("NumPad 0");
	buttons_[102].SetName("NumPad .");
}

void Keyboard::IncKeyCntr(int index)
{
	if (index >= 0 && index <= 102)
		buttons_[index].IncCntr();
}

std::array<Button, 103> Keyboard::GetButtons()
{
	return buttons_;
}