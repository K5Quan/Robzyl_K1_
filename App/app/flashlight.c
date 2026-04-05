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
#ifdef ENABLE_FLASHLIGHT

#include "driver/gpio.h"
#include "app/flashlight.h"
#include <stdbool.h>

static inline void Flashlight_TurnOn(){ GPIO_SetOutputPin(GPIO_PIN_FLASHLIGHT); }
static inline void Flashlight_TurnOff(){ GPIO_ResetOutputPin(GPIO_PIN_FLASHLIGHT); }
static inline void Flashlight_Toggle(){ GPIO_TogglePin(GPIO_PIN_FLASHLIGHT); }

#if !defined(ENABLE_FEAT_F4HWN) || defined(ENABLE_FEAT_F4HWN_RESCUE_OPS)
    enum FlashlightMode_t  gFlashLightState;

    void FlashlightTimeSlice()
    {
        if (gFlashLightState == FLASHLIGHT_BLINK && (gFlashLightBlinkCounter & 15u) == 0) {
            Flashlight_Toggle();
            return;
        }

        if (gFlashLightState == FLASHLIGHT_SOS) {
            const uint16_t u = 15;
            static uint8_t c;
            static uint16_t next;

            if (gFlashLightBlinkCounter - next > 7 * u) {
                c = 0;
                next = gFlashLightBlinkCounter + 1;
                return;
            }

            if (gFlashLightBlinkCounter == next) {
                if (c==0) {
                    Flashlight_TurnOff();
                } else {
                    Flashlight_Toggle();
                }

                if (c >= 18) {
                    next = gFlashLightBlinkCounter + 7 * u;
                    c = 0;
                } else if(c==7 || c==9 || c==11) {
                    next = gFlashLightBlinkCounter + 3 * u;
                } else {
                    next = gFlashLightBlinkCounter + u;
                }
                c++;
            }
        }
    }

    void ACTION_FlashLight(void)
    {
        // switch (gFlashLightState) {
        //     case FLASHLIGHT_OFF:
        //         Flashlight_TurnOn();
        //         break;
        //     case FLASHLIGHT_ON:
        //     case FLASHLIGHT_BLINK:
        //         break;
        //     case FLASHLIGHT_SOS:
        //     default:
        //         Flashlight_TurnOff();
        // }

        if(gFlashLightState == FLASHLIGHT_OFF) {
            Flashlight_TurnOn();
        }
        else if (gFlashLightState == FLASHLIGHT_SOS) {
            Flashlight_TurnOff();
        }

        gFlashLightState = (gFlashLightState + 1) % 4;
    }
#else
    void ACTION_FlashLight(void)
    {
        static bool gFlashLightState = false;

        if(gFlashLightState)
        {
            Flashlight_TurnOff();
        }
        else
        {
            Flashlight_TurnOn();
        }

        gFlashLightState = (gFlashLightState) ? false : true;
    }
#endif
#endif
