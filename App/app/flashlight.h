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
#ifndef APP_FLASHLIGHT_H
#define APP_FLASHLIGHT_H

#ifdef ENABLE_FLASHLIGHT

#include <stdint.h>

#if !defined(ENABLE_FEAT_F4HWN) || defined(ENABLE_FEAT_F4HWN_RESCUE_OPS)
    enum FlashlightMode_t {
        FLASHLIGHT_OFF = 0,
        FLASHLIGHT_ON,
        FLASHLIGHT_BLINK,
        FLASHLIGHT_SOS
    };

    extern enum FlashlightMode_t gFlashLightState;
    extern volatile uint16_t     gFlashLightBlinkCounter;

    void FlashlightTimeSlice(void);
#endif
void ACTION_FlashLight(void);

#endif

#endif