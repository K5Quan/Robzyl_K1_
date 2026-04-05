/* Copyright 2023 fagci
 * https://github.com/fagci
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */
#include "app/chFrScanner.h"
#include "audio.h"
#include "functions.h"
#include "misc.h"
#include "settings.h"
#include "ui/inputbox.h"
#include "ui/ui.h"

void COMMON_KeypadLockToggle() 
{

    if (gScreenToDisplay != DISPLAY_MENU &&
        gCurrentFunction != FUNCTION_TRANSMIT)
    {   // toggle the keyboad lock

        #ifdef ENABLE_VOICE
            gAnotherVoiceID = gEeprom.KEY_LOCK ? VOICE_ID_UNLOCK : VOICE_ID_LOCK;
        #endif

        gEeprom.KEY_LOCK = !gEeprom.KEY_LOCK;

        gRequestSaveSettings = true;
    }
}

void COMMON_SwitchVFOs()
{
#ifdef ENABLE_SCAN_RANGES    
    gScanRangeStart = 0;
#endif
    gEeprom.TX_VFO ^= 1;

    if (gInputBoxIndex > 0) {
        gInputBoxIndex = 0;
        gHasVfoBackup = false;
    }

    if (gEeprom.CROSS_BAND_RX_TX != CROSS_BAND_OFF)
        gEeprom.CROSS_BAND_RX_TX = gEeprom.TX_VFO + 1;
    if (gEeprom.DUAL_WATCH != DUAL_WATCH_OFF)
        gEeprom.DUAL_WATCH = gEeprom.TX_VFO + 1;

    gRequestSaveSettings  = 1;
    gFlagReconfigureVfos  = true;
    gScheduleDualWatch = true;

    gRequestDisplayScreen = DISPLAY_MAIN;
}

void COMMON_SwitchVFOMode()
{
#ifdef ENABLE_NOAA
    if (gEeprom.VFO_OPEN && !IS_NOAA_CHANNEL(gTxVfo->CHANNEL_SAVE))
#else
    if (gEeprom.VFO_OPEN)
#endif
    {
        if (gInputBoxIndex > 0) {
            gInputBoxIndex = 0;
            gHasVfoBackup = false;
        }

        if (IS_MR_CHANNEL(gTxVfo->CHANNEL_SAVE))
        {   // swap to frequency mode
            gEeprom.ScreenChannel[gEeprom.TX_VFO] = gEeprom.FreqChannel[gEeprom.TX_VFO];
            #ifdef ENABLE_VOICE
                gAnotherVoiceID        = VOICE_ID_FREQUENCY_MODE;
            #endif
            gRequestSaveVFO            = true;
            gVfoConfigureMode          = VFO_CONFIGURE_RELOAD;
            return;
        }

        uint16_t Channel = RADIO_FindNextChannel(gEeprom.MrChannel[gEeprom.TX_VFO], 1, false, 0);
        if (Channel != 0xFFFF)
        {   // swap to channel mode
            gEeprom.ScreenChannel[gEeprom.TX_VFO] = Channel;
            #ifdef ENABLE_VOICE
                AUDIO_SetVoiceID(0, VOICE_ID_CHANNEL_MODE);
                AUDIO_SetDigitVoice(1, Channel + 1);
                gAnotherVoiceID = (VOICE_ID_t)0xFE;
            #endif
            gRequestSaveVFO     = true;
            gVfoConfigureMode   = VFO_CONFIGURE_RELOAD;
            return;
        }
    }
}