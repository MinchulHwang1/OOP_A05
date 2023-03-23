//driver.cpp

/* -- this is a FILEHEADER COMMENT --
	NAME	: driver
	PURPOSE : This program takes the contents entered into the object and initializes it with Constructor.
			  The constructor has confirmed that it can be overloaded, and outputs accordingly.
			  User can get information from printed screen, and set the preset in radio.
			  If the input data member is out of the specified range, an appropriate value is output,
			  and the memory allocated by the destructor is deleted when the file loading is finished.
*/
#include "AmFmRadio.h"
#include "PioneerCarRadio.h"
#include <iostream>


int main() {

	PioneerCarRadio Jazzy(false);
	int num = kZeroValue;
	char getChar;

	while (num != kBreakValue) {
		
		num = Jazzy.CurrentStatus();
		getChar = getch();
		Jazzy.ProcessUserKeyStroke(getChar);
		if (Jazzy.GetExit() == true)
			break;
	}

	return 0;
}