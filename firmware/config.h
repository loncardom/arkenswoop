/* Copyright 2022 James White <jamesmnw@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#define MCU_LIATRIS

// OLED driver
#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X32
  #define OLED_TIMEOUT 30000
#endif

#ifdef MCU_LIATRIS
  // Liatris led configuration
  #undef RGB_DI_PIN
  #define RGB_DI_PIN 25
  #undef RGBLED_NUM
  #define RGBLED_NUM 2
  #undef RGBLED_SPLIT
  #define RGBLED_SPLIT {1, 1}

  // Use power indicator as caps lock indicator
  #define LED_CAPS_LOCK_PIN 24
  #define LED_PIN_ON_STATE 0
#else
  // RGB underglow and per key can not be used with the Liatris MCU if the MCU led is used
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLED_NUM 36
  #define RGBLED_SPLIT \
        { 18, 18 }
  #define RGBLIGHT_SPLIT
  #define RGBLIGHT_HUE_STEP 10
  #define RGBLIGHT_SAT_STEP 17
  #define RGBLIGHT_VAL_STEP 17
  #define RGBLIGHT_SLEEP
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Serial settings */
#define USE_SERIAL
/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D2

/* Config matrix */
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS { D4, C6, D7, E6 }
#define MATRIX_COL_PINS { B1, F7, F6, F5, F4 }

/* Encoders config */
#define ENCODERS_PAD_A { B4 }
#define ENCODERS_PAD_B { B5 }
#define ENCODERS_PAD_A_RIGHT { B5 }
#define ENCODERS_PAD_B_RIGHT { B4 }

