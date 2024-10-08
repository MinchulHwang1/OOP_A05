// PioneerCarRadio.h
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "AmFmRadio.h"
#include <iostream>
using namespace std;

#ifndef _PIONEERCARRADIO_H
#define _PIONEERCARRADIO_H
#define kZeroIndex		0
#define kOneIndex		1
#define kTwoIndex		2
#define kThreeIndex		3
#define kFourIndex		4
#define kBreakValue		1


/*
	-* CLASS COMMENT *-
	NAME    : PioneerCarRadio
	PURPOSE : This class creates an object that
			  proceeds with the program according to the number pressed by the user in the menu.
			  The methods are inherited from parent class
*/
class PioneerCarRadio : public AmFmRadio {
	/* ====================================== */
	/*              PRIVATE                   */
	/* ====================================== */
private :
	char getChar;							///< To save character which is gotten from user to choose menu
	bool on;								///< To store the status of radio power
	int volume;								///< To store the volume
	float current_station;					///< To get current station
	char band[kBandName];					///< To store the band name
	bool exit;
	
public :
	/* ====================================== */
	/*              PUBLIC                    */
	/* ====================================== */
	PioneerCarRadio(bool on);				///< Constructor with bool parameters
	~PioneerCarRadio();						///< DIstructor of object

	void ShowCurrentSettings(void);			///< This method can show current status.
	int CurrentStatus(void);				///< It can check current radio status
	void ProcessUserKeyStroke(char getChar);		///< This method can divide a character of keystrokes

	char GetChar(void);						///< Accessor - to get char from user as keystroke
	float GetCurrent_Station(void);			///< Accessor - to get current station from AmFmRadio class
	char * GetBandName(void);				///< Accessor - to get band name from AmFmRadio class
	bool GetExit(void);						///< Accessor - to get bool value which can figure out break
};


#endif _PIONEERCARRADIO_H