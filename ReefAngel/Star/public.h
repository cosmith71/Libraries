// Star

DS1307RTC RTC;
RA_NokiaLCD LCD;
RA_JoystickClass Joystick;
RA_ATOALARMClass AlarmInput;

byte RANetSeq, RANetCRC;
byte RANetData[RANET_SIZE];
byte RANetStatus[RANET_SIZE];
unsigned long RANetlastmillis;

bool SDFound;

void ShowInterface();
void DrawStandardMain();
void StoreGraphData();
void CheckScreenSaver();
void DisplayFeedingMode();
void DisplayWaterChangeMode();
void PrepMenuScreen();
void DisplayMenu();
void DisplayMenuHeading();
void DisplayMenuEntry(char *text);
void ProcessButtonPress();
// Nested Menu Functions
#ifdef CUSTOM_MENU
void InitMenu(int ptr, byte qty);
void ProcessButtonPressCustom();
#else
void InitMenus();
void ProcessButtonPressMain();

#ifndef SIMPLE_MENU
void ProcessButtonPressSetup();
#ifndef RemoveAllLights
void ProcessButtonPressLights();
#endif  // RemoveAllLights
void ProcessButtonPressTemps();
#if defined SetupExtras || defined ATOSetup
void ProcessButtonPressTimeouts();
#endif  // if defined SetupExtras || defined ATOSetup

// Setup Screens
bool SetupOption(int &v, int &y, int rangemin, int rangemax, byte maxdigits,
		char* unit, char* subunit, char* title,
		char* prefix1, char* prefix2);
void SetupLightsOptionDisplay(bool bMetalHalide);
#endif  // SIMPLE_MENU
#endif  // CUSTOM_MENU

#if defined ORPEXPANSION
void SetupCalibrateORP();
#endif  // defined ORPEXPANSION
#if defined SALINITYEXPANSION
void ApplySalinityCompensation();
void StartSetupCalibrateSalinity();
void DisplaySetupCalibrateSalinity();
#endif  // defined SALINITYEXPANSION
#if defined PHEXPANSION
void StartSetupCalibrateChoicePHExp();
void DisplaySetupCalibrateChoicePHExp();
#endif  // defined PHEXPANSION
#if defined WATERLEVELEXPANSION || defined MULTIWATERLEVELEXPANSION
void SetupCalibrateWaterLevel();
#endif  // WATERLEVELEXPANSION || MULTIWATERLEVELEXPANSION
#if defined DateTimeSetup
#ifdef DATETIME24
void SetupDateTime24();
#else
void SetupDateTime();
#endif  // DATETIME24
#endif  // DateTimeSetup

#if !defined SIMPLE_MENU && !defined CUSTOM_MENU
#ifdef DosingPumpSetup
void SetupDosingPump();
#endif  // DosingPumpSetup
#endif  // !defined SIMPLE_MENU && !defined CUSTOM_MENU

void BuzzerOn(byte style=0);
void BuzzerOff();
