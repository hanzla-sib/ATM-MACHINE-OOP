#include "KEYPAD.h"

void KEYPAD::setkeyinput(int k)
{
	keyinput = k;
}

int KEYPAD::getkeyinput()
{
	return keyinput;
}
