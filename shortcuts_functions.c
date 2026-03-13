BK4819_RX_TurnOn();
RADIO_ConfigureChannel();
UI_DisplayStatus();
Measure(); 
UpdateNoiseOff();
UpdateGlitch();
UpdateListening();

LoadActiveScanFrequencies();

boot
UI_DisplayReleaseKeys()
UI_DisplayMain();
