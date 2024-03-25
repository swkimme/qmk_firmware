// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


enum layers_names { _BASE, _GAME, _NUM, _FUN, _SPE, _NAV };

#define NUM MO(_NUM)
#define FUN MO(_FUN)
#define SPE MO(_SPE)
#define NAV MO(_NAV)

#define SPC_NAV LT(_NAV, KC_SPC)
#define ESC_ALT MT(MOD_LALT, KC_ESC)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define NUM_TAB LT(_NUM, KC_TAB)

#define SWITCH S(C(KC_TAB))

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J LSFT_T(KC_J)
#define HOME_K LCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_QUOT LGUI_T(KC_QUOT)


const uint16_t PROGMEM combo_bracket_v_round_l[] = {KC_R, HOME_F, COMBO_END};
const uint16_t PROGMEM combo_bracket_v_round_r[] = {KC_U, HOME_J, COMBO_END};
const uint16_t PROGMEM combo_bracket_v_square_l[] = {KC_E, HOME_D, COMBO_END};
const uint16_t PROGMEM combo_bracket_v_square_r[] = {KC_I, HOME_K, COMBO_END};
const uint16_t PROGMEM combo_bracket_v_curly_l[] = {KC_W, HOME_S, COMBO_END};
const uint16_t PROGMEM combo_bracket_v_curly_r[] = {KC_O, HOME_L, COMBO_END};
const uint16_t PROGMEM combo_bracket_v_angled_l[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_bracket_v_angled_r[] = {KC_Y, KC_H, COMBO_END};

const uint16_t PROGMEM combo_cc[] = {HOME_D, KC_C, COMBO_END};
const uint16_t PROGMEM combo_cv[] = {HOME_F, KC_V, COMBO_END};
const uint16_t PROGMEM combo_cx[] = {HOME_S, KC_X, COMBO_END};
const uint16_t PROGMEM combo_cb[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM combo_semicolon[] = {KC_DOT, KC_QUES, COMBO_END};
const uint16_t PROGMEM combo_colon[] = {HOME_L, HOME_QUOT, COMBO_END};

const uint16_t PROGMEM combo_capsword[] = {HOME_D, HOME_J, HOME_F, HOME_K, COMBO_END};
const uint16_t PROGMEM combo_tog_num_word[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_tog_num_word2[] = {KC_1, KC_2, KC_3, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_bracket_v_round_l, KC_LPRN),
    COMBO(combo_bracket_v_round_r, KC_RPRN),
    COMBO(combo_bracket_v_square_l, KC_LBRC),
    COMBO(combo_bracket_v_square_r, KC_RBRC),
    COMBO(combo_bracket_v_curly_l, S(KC_LBRC)),
    COMBO(combo_bracket_v_curly_r, S(KC_RBRC)),
    COMBO(combo_bracket_v_angled_l, S(KC_COMM)),
    COMBO(combo_bracket_v_angled_r, S(KC_DOT)),
    COMBO(combo_cc, C(KC_C)),
    COMBO(combo_cv, C(KC_V)),
    COMBO(combo_cx, C(KC_X)),
    COMBO(combo_cb, C(KC_B)),
    COMBO(combo_semicolon, KC_SCLN),
    COMBO(combo_colon, KC_COLN),
    COMBO(combo_capsword, QK_CAPS_WORD_TOGGLE),
    COMBO(combo_tog_num_word, TG(NUM)),
    COMBO(combo_tog_num_word2, TG(NUM)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     XXXXXXX,  XXXXXXX,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        HOME_A,   HOME_S,   HOME_D,   HOME_F,   KC_G,     XXXXXXX,  XXXXXXX,  KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_QUOT,
        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_QUES,
        XXXXXXX,  XXXXXXX,  KC_ESC,   KC_LCTL,  NUM_TAB,  XXXXXXX,  XXXXXXX,  SFT_ENT,  SPC_NAV,  KC_BSPC,  FUN,      TT(_GAME)
    ),
    [_GAME] = LAYOUT(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_ENT,
        KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_RSFT,
        KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_SPC,   KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   _______
    ),
    [_NUM] = LAYOUT(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
        XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_PLUS,  XXXXXXX,  XXXXXXX,  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_UNDS,
        KC_0,     KC_4,     KC_5,     KC_6,     KC_EQL,   XXXXXXX,  XXXXXXX,  KC_ASTR,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_MINS,
        SWITCH,   KC_7,     KC_8,     KC_9,     KC_BSLS,  XXXXXXX,  XXXXXXX,  KC_GRV,   KC_AMPR,  KC_COMM,  KC_DOT,   KC_SLSH,
        _______,  _______,  _______,  SPE,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX
    ),
    [_FUN] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_F10,   KC_F1,    KC_F2,    KC_F3,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_F11,   KC_F4,    KC_F5,    KC_F6,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_F12,   KC_F7,    KC_F8,    KC_F9,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),
    [_SPE] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),
    [_NAV] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,
        XXXXXXX,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    )
};
