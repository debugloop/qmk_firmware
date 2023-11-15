/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers{
    BASE,
    MS1,
    MS2,
    FN,
    LED_H,
    LED_S,
    LED_V,
    LED_SPD,
    UM,
};

enum custom_keycodes {
    RGB_MODE_FANCY = SAFE_RANGE,
    RGB_MODE_HEAT,
    RGB_MODE_CYCLE,
};


// custom keys shorthands
#define RGB_M_F RGB_MODE_FANCY
#define RGB_M_H RGB_MODE_HEAT
#define RGB_M_C RGB_MODE_CYCLE

// special handling keys
#define KC__ESC LT(FN, KC_ESC)
#define KC__CAP LT(UM, KC_ESC)

#define KC__F1 LT(LED_H, KC_F1)
#define KC__F2 LT(LED_S, KC_F2)
#define KC__F3 LT(LED_V, KC_F3)
#define KC__F4 LT(LED_SPD, KC_F4)

// UM layer keys
#define KC__AE RALT(KC_Q)
#define KC__OE RALT(KC_P)
#define KC__UE RALT(KC_Y)
#define KC__SS RALT(KC_S)
#define KC__EUR RALT(KC_5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_82(
        KC__ESC,   KC__F1,   KC__F2,   KC__F3,   KC__F4,    KC_F5,    KC_F6,    KC_F7,  KC_PSCR,  KC_MPLY,  KC_MNXT,  KC_MUTE,   KC_F20,   KC_DEL,             KC_F20,
         KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  KC_MINS,   KC_EQL,  KC_BSPC,            KC_PGUP,
         KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC__CAP,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_QUOT,             KC_ENT,            KC_HOME,
        KC_LSFT,               KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,            KC_RSFT,    KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                 KC_SPC,                                KC_RALT,   TT(FN),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
    [FN] = LAYOUT_ansi_82(
         KC_ESC,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_WH_U,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BTN2,            KC_WH_D,
        KC_CAPS,  _______,  _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  _______,  _______,            KC_BTN1,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  KC_WH_U,
        QK_BOOT,  _______,  _______,                                KC_BTN1,                                _______, TO(BASE),  _______,  KC_WH_L,  KC_WH_D,  KC_WH_R),
    [LED_H] = LAYOUT_ansi_82(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_M_C,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  RGB_M_P,  XXXXXXX,  RGB_M_F,  XXXXXXX,  RGB_M_H,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,            XXXXXXX,  XXXXXXX,  RGB_M_C,  XXXXXXX,  RGB_M_B,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                RGB_MOD,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),
    [LED_S] = LAYOUT_ansi_82(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_M_C,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  RGB_M_P,  XXXXXXX,  RGB_M_F,  XXXXXXX,  RGB_M_H,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,            XXXXXXX,  XXXXXXX,  RGB_M_C,  XXXXXXX,  RGB_M_B,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                RGB_MOD,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),
    [LED_V] = LAYOUT_ansi_82(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_M_C,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  RGB_M_P,  XXXXXXX,  RGB_M_F,  XXXXXXX,  RGB_M_H,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,            XXXXXXX,  XXXXXXX,  RGB_M_C,  XXXXXXX,  RGB_M_B,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                RGB_MOD,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),
    [LED_SPD] = LAYOUT_ansi_82(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_M_C,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  RGB_M_P,  XXXXXXX,  RGB_M_F,  XXXXXXX,  RGB_M_H,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,            XXXXXXX,  XXXXXXX,  RGB_M_C,  XXXXXXX,  RGB_M_B,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                RGB_MOD,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),
    [UM] = LAYOUT_ansi_82(
         KC_ESC,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  KC__EUR,  _______,  _______,  _______,   KC__UE,  _______,   KC__OE,  _______,  _______,  _______,  _______,            _______,
        _______,   KC__AE,   KC__SS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                 KC_SPC,                                _______,  XXXXXXX,  _______,  _______,  _______,  _______),
};

const uint16_t PROGMEM encoder_map[][1][2] = {
    [BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FN] =  { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [LED_H] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [LED_S] = { ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [LED_V] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [LED_SPD] = { ENCODER_CCW_CW(RGB_SPD, RGB_SPI) },
    [UM] =  { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_MODE_FANCY:
            rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
            return false;
        case RGB_MODE_HEAT:
            rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
            return false;
        case RGB_MODE_CYCLE:
            rgb_matrix_mode(RGB_MATRIX_CYCLE_ALL);
            return false;
        default:
            return true;   // Process all other keycodes normally
    }
}

// overrides
const key_override_t home_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_HOME, KC_END);
const key_override_t **key_overrides = (const key_override_t *[]){
    &home_key_override,
    NULL // Null terminate the array of overrides!
};


bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        if (active) {
            rgb_matrix_enable();
        } else {
            rgb_matrix_disable();
        }
    }
    return false;
}

void set_context_leds(void) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
        case BASE:
            if (rgb_matrix_is_enabled()) {
                rgb_matrix_enable();
            } else {
                rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case FN:
            if (rgb_matrix_is_enabled()) {
                rgb_matrix_enable();
            } else {
                rgb_matrix_set_color_all(0, 0, 0);
            }
            for (int i = 0; i <= 12; i++) {
                rgb_matrix_set_color(i, 255, 255, 255); // f keys
            }
            for (int i = 0; i < 4; i++) {
                rgb_matrix_set_color(51+i, 255, 255, 255); // h j k l
            }
            rgb_matrix_set_color(29, 255, 255, 255); // pgup
            rgb_matrix_set_color(43, 255, 255, 255); // backslash
            rgb_matrix_set_color(44, 255, 255, 255); // pgdn
            rgb_matrix_set_color(45, 255, 255, 255); // caps
            rgb_matrix_set_color(57, 255, 255, 255); // enter
            rgb_matrix_set_color(71, 255, 255, 255); // up
            rgb_matrix_set_color(72, 255, 0, 0); // rctrl
            rgb_matrix_set_color(75, 255, 255, 255); // space
            rgb_matrix_set_color(77, 255, 255, 255); // fn
            for (int i = 0; i < 3; i++) {
                rgb_matrix_set_color(79+i, 255, 255, 255); // left down right
            }
            break;
        case LED_H:
        case LED_S:
        case LED_V:
        case LED_SPD:
            /* if (rgb_matrix_is_enabled()) { */
            /*     rgb_matrix_enable(); */
            /* } else { */
            /*     rgb_matrix_set_color_all(0, 0, 0); */
            /* } */
            /* rgb_matrix_set_color(75, 255, 255, 255); */
            /* break; */
        default:
            break;
    }
    /* if (host_keyboard_led_state().caps_lock) { */
    /*     rgb_matrix_set_color(45, 255, 255, 255); */
    /* } else { */
    /*     rgb_matrix_set_color(45, 0, 0, 0); */
    /* } */
}

extern void rgb_matrix_update_pwm_buffers(void);

bool rgb_matrix_indicators_kb(void) {
    set_context_leds();
    return true;
}

void rgb_matrix_indicators_none_kb(void) {
    rgb_matrix_indicators_kb();
    rgb_matrix_update_pwm_buffers();
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);

    if (rgb_matrix_is_enabled()) {
        return res;
    }

    if (res) {
        set_context_leds();
        rgb_matrix_update_pwm_buffers();
    }

    return res;
}
