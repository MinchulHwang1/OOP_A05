#include"PioneerCarRadio.h"

PioneerCarRadio::PioneerCarRadio(bool on) : AmFmRadio(false) {
	getChar = 'x';
	on = false;
	this->on = on;
	
	volume = 0;
}

PioneerCarRadio::~PioneerCarRadio() {
	printf("PioneerCarRadio is destroyed\n");
}

char PioneerCarRadio::GetChar(void) {
	getChar = getch();
	return getChar;
}

void PioneerCarRadio::SetChar(char getChar) {
	this->getChar = getChar;
}

Freqs PioneerCarRadio::GetRememberStatus(void) {
	rememberStatus = AmFmRadio::GetRememberStatus();
	return rememberStatus;
}
float PioneerCarRadio::GetCurrent_Station(void) {
	current_station = AmFmRadio::GetCurrent_Station();
	return current_station;
}
char* PioneerCarRadio::GetBandName(void) {
	band = AmFmRadio::GetBandName();
	return band;
}
void PioneerCarRadio::ShowCurrentSettings(void) {
	printf("Volume: %d\n", volume);

	
	// AM, FM 출력방법 바꾸기, 전원끄고 밴드 바꿔도 바뀜 --> 해결해야함
	if (strcmp(GetBandName(), "AM") == 0) {
		printf("Current Station: %d %s\n", (int)GetCurrent_Station(), GetBandName());
	}
	else {
		printf("Current Station: %.1f %s\n", GetCurrent_Station(), GetBandName());
	}

	printf("AM Buttons:\n");
	for (int i = kZeroValue; i < kNumberOfArray-1; ++i) {
		printf("%d) %6d,  ", i + 1, GetButton(i).AMFreqs);
	}
	printf("%d) %6d", kNumberOfArray, GetButton(kNumberOfArray - 1).AMFreqs);
	printf("\nFM Buttons:\n");
	for (int j = kZeroValue; j < kNumberOfArray-1; ++j) {
		printf("%d) %6.1f,  ", j + 1, GetButton(j).FMFreqs);
	}
	printf("%d) %6.1f", kNumberOfArray, GetButton(kNumberOfArray - 1).FMFreqs);
}

int PioneerCarRadio::CurrentStatus(void) {
	
	if (on == false) {
		printf("Pioneer XS440\n");
		printf("Radio is off\n\n");
	}
	else {
		printf("Pioneer XS440\n");
		printf("Radio is on\n");
		ShowCurrentSettings();
		printf("\n\n");
	}

	GetChar();
	switch (getChar) {
	case 'x':
		return 1;
		
	case 'X' :
		return 1;
		
		 // do nothing mean show up nothing or current status?
	default :
		DivisionChar(getChar);
		return 0;
	}
	
}


void PioneerCarRadio::DivisionChar(char getChar) {
	switch (getChar) {
	case 'o':
		
		PowerToggle();
		on = IsRadioOn();

		break;

	case '+':
		if (on == true) {
			volume++;
			if (volume > 100) {
				volume = 100;
			}
			SetVolume(volume);
		}
		else
			SetVolume(volume);
		break;

	case '_':
		if (on == true) {
			volume--;
			if (volume < 0) {
				volume = 0;
			}
			SetVolume(volume);
		}
		else
			SetVolume(volume);
		break;

	case '=':
		if (on == true) {
			ScanUp();
		}
		break;

	case '-' :
		if (on == true) {
			ScanDown();
		}
		break;

	case 'b' :
		if(on == true)
			ToggleBand();
	
		break;

	case '1':
		if (on == true) {
			SelectPresetButton(0);
		}
		break;

	case '2' :
		if (on == true) {
			SelectPresetButton(1);
		}
		break;

	case '3' :
		if (on == true) {
			SelectPresetButton(2);
		}
		break;

	case '4' :
		if (on == true) {
			SelectPresetButton(3);
		}
		break;

	case '5' :
		if (on == true) {
			SelectPresetButton(4);
		}
		break;

	case '!' :
		if (on == true) {
			SetPresetButton(0);
		}
		break;

	case '@' :
		if (on == true) {
			SetPresetButton(1);
		}
		break;

	case '#' :
		if (on == true) {
			SetPresetButton(2);
		}
		break;

	case '$' :
		if (on == true) {
			SetPresetButton(3);
		}
		break;

	case '%' :
		if (on == true) {
			SetPresetButton(4);
		}
		break;

	default:
		break;
	}
}