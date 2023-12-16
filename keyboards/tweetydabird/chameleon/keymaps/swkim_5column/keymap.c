// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


enum layers_names { _BASE, _NUM, _SPE, _NAV };

#define NUM MO(_NUM)
#define SPE MO(_SPE)
#define NAV MO(_NAV)
#define SPC_NAV LT(_NAV, KC_SPC)
#define ESC_ALT MT(MOD_LALT, KC_ESC)


// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J LSFT_T(KC_J)
#define HOME_K LCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_QUOT RGUI_T(KC_QUOT)


const uint16_t PROGMEM test_combo1[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_ESC),
    COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_ortho_4x12(
        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       XXXXXXX,    XXXXXXX,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
        HOME_A,     HOME_S,     HOME_D,     HOME_F,     KC_G,       XXXXXXX,    XXXXXXX,    KC_H,       HOME_J,     HOME_K,     HOME_L,     HOME_QUOT,
        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       XXXXXXX,    XXXXXXX,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    ESC_ALT,    KC_LCTL,    NUM,     KC_ENT,     SPC_NAV,     KC_BSPC,    SPE,    XXXXXXX,    XXXXXXX
    ),
    [_NUM] = LAYOUT_ortho_4x12(
        _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
        KC_0,       KC_4,       KC_5,       KC_6,       KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_MINS,    KC_PLUS,    KC_EQL,
        _______,    KC_7,       KC_8,       KC_9,       KC_LPRN,    KC_RPRN,    _______,    _______,    _______,    _______,    _______,    KC_BSLS,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_SPE] = LAYOUT_ortho_4x12(
        KC_F10,     KC_F1,      KC_F2,      KC_F3,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_F11,     KC_F4,      KC_F5,      KC_F6,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_F12,     KC_F7,      KC_F8,      KC_F9,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_NAV] = LAYOUT_ortho_4x12(
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_UP,      XXXXXXX,    XXXXXXX,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RGHT,    XXXXXXX,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    )
};
