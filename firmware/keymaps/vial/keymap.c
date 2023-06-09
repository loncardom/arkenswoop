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
#include QMK_KEYBOARD_H

#define LED_INTENSITY 25

void keyboard_post_init_user(void) {
    // Initialize RGB to static black
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLACK);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

void housekeeping_task_user(void) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0:
            // Default layer
            rgblight_setrgb_at(RGB_BLACK, 0);
            break;
        case 1:
            // Symbols
            rgblight_setrgb_at(0, 0, LED_INTENSITY, 0);
            break;
        case 2:
            // French macros
            rgblight_setrgb_at(0, LED_INTENSITY, 0, 0);
            break;
        case 3:
            // Nav
            rgblight_setrgb_at(LED_INTENSITY, 0, 0, 0);
            break;
        case 4:
            // Numpad
            rgblight_setrgb_at(LED_INTENSITY, 0, LED_INTENSITY, 0);
            break;
    }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [3] =   { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [4] =   { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    //                  Encoder 1                                     Encoder 2
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3(
    KC_Q,         KC_W,         KC_E,         KC_R,            KC_T,            KC_Y,        KC_U,         LT(2, KC_I),  KC_O,   KC_P,
    LALT_T(KC_A), LSFT_T(KC_S), LGUI_T(KC_D), LCTL_T(KC_F),    LT(1, KC_G),     LT(1, KC_H), LCTL_T(KC_J), LGUI_T(KC_K), KC_L,   KC_SCLN,
    KC_Z,         KC_X,         KC_C,         KC_V,            KC_B,            KC_N,        KC_M,         KC_COMM,      KC_DOT, KC_SLASH,
                                KC_NO,        LT(3, KC_ESC),   KC_SPACE,        KC_BSPACE,   LT(3, KC_ENTER), KC_NO
  ),

  [1] = LAYOUT_split_3x5_3(
    KC_NO,   LSFT(KC_2), LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_BSLASH),       LSFT(KC_COMMA), LSFT(KC_MINUS), KC_EQUAL,   LSFT(KC_3), KC_NO,
    KC_NO,   LSFT(KC_4), LSFT(KC_9),    LSFT(KC_0),    KC_GRAVE,              KC_MINUS,       LSFT(KC_QUOTE), KC_QUOTE,   LSFT(KC_8), LSFT(KC_EQUAL),
    KC_NO,   LSFT(KC_6), KC_LBRC,       KC_RBRC,       LSFT(KC_GRAVE),        LSFT(KC_DOT),   LSFT(KC_7),     LSFT(KC_5), LSFT(KC_1), KC_BSLASH,
                         KC_NO,         KC_TRNS,       KC_TRNS,               KC_TRNS, KC_TRNS, KC_NO
  ),

  [2] = LAYOUT_split_3x5_3(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                      KC_NO,   KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_NO
  ),

  [3] = LAYOUT_split_3x5_3(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F12,
    KC_LALT, KC_LSFT, KC_LGUI, KC_LCTL, KC_F6,      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_F14,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_MPLY, KC_VOLU, KC_VOLD, KC_MUTE,  KC_F15,
                      KC_NO,   KC_TRNS, KC_TRNS,    KC_DEL,  KC_TAB,  KC_NO
  ),

  [4] = LAYOUT_split_3x5_3(
    KC_NO,   KC_NO,   KC_NO,   KC_K,    KC_NO,       KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_J,    KC_NO,       KC_MINS, KC_4,    KC_5,    KC_6,    KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_DOT,  KC_1,    KC_2,    KC_3,    KC_NO,
                      KC_NO,   LSFT(KC_G), KC_TRNS,     KC_TRNS, KC_0,    KC_NO
  ),
};

