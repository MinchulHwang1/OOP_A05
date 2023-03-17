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

class PioneerCarRadio : public AmFmRadio {
private :
	char getChar;
	bool on;
	int volume;
	float current_station;
	char* band;
	Freqs	rememberStatus;
	;
public :
	PioneerCarRadio(bool on);
	~PioneerCarRadio();

	char GetChar(void);

	void SetChar(char getChar);

	int CurrentStatus(void);
	void DivisionChar(char getChar);
	//char* GetBandName(void);
	//void SetBaneName(char* band);
	void ShowCurrentSettings(void);


	float GetCurrent_Station(void);
	char * GetBandName(void);
	Freqs GetRememberStatus(void);
};


#endif _PIONEERCARRADIO_H