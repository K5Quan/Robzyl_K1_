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
#ifndef APP_CHFRSCANNER_H
#define APP_CHFRSCANNER_H

#include <stdbool.h>
#include <stdint.h>

// scan direction, if not equal SCAN_OFF indicates 
// that we are in a process of scanning channels/frequencies
extern int8_t            gScanStateDir;
extern bool              gScanKeepResult;
extern bool              gScanPauseMode;

#ifdef ENABLE_SCAN_RANGES
extern uint32_t          gScanRangeStart;
extern uint32_t          gScanRangeStop;
#endif

void CHFRSCANNER_Found(void);
void CHFRSCANNER_Stop(void);
void CHFRSCANNER_Start(const bool storeBackupSettings, const int8_t scan_direction);
void CHFRSCANNER_ContinueScanning(void);

#if defined(ENABLE_FEAT_F4HWN_RESUME_STATE) || defined(ENABLE_SCAN_RANGES)
    void CHFRSCANNER_ScanRange(void);
#endif

#ifdef ENABLE_FEAT_F4HWN
    extern uint32_t lastFoundFrqOrChan;
    extern uint32_t lastFoundFrqOrChanOld;
#endif

#endif