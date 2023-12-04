// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


enum layers_names { _QWERTY, _NUMBER, _SPECIAL, _ARROW };

#define NUMBER MO(_NUMBER)
#define SPECIAL MO(_SPECIAL)
#define ARROW MO(_ARROW)
#define SPC_AR LT(_ARROW, KC_SPC)
#define ESC_ALT MT(MOD_LALT, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_ortho_4x12(
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       XXXXXXX,
        KC_LCTL,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    KC_LGUI,    ESC_ALT,    KC_LCTL,    NUMBER,     KC_ENT,     SPC_AR,     KC_BSPC,    SPECIAL,    XXXXXXX,    XXXXXXX
    ),
    [_NUMBER] = LAYOUT_ortho_4x12(
        KC_0,       KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
        KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_MINS,    KC_PLUS,    KC_EQL,
        _______,    _______,    KC_LBRC,    KC_RBRC,    KC_LPRN,    KC_RPRN,    _______,    _______,    _______,    _______,    _______,    KC_BSLS,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_SPECIAL] = LAYOUT_ortho_4x12(
        KC_F12,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_ARROW] = LAYOUT_ortho_4x12(
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_UP,      XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RGHT,    XXXXXXX,    XXXXXXX,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    )
};
