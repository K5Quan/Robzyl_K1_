BK4819_RX_TurnOn();
RADIO_ConfigureChannel();
UI_DisplayStatus();
Measure(); 
UpdateNoiseOff();
UpdateGlitch();
UpdateListening();
APP_RunSpectrum();
LoadActiveScanFrequencies();

boot
UI_DisplayReleaseKeys()
UI_DisplayMain();

SETTINGS_FetchChannelName();
BOARD_gMR_fetchChannel();
NextAppMode();
NextScanStep();
DrawF();