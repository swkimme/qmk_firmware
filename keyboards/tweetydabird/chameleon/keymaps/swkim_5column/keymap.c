// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef OS_DETECTION_ENABLE
#    include "os_detection.h"
#endif

#define DICT_MODS (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI))

enum layers_names { _BASE, _GAME, _NUM, _FUN, _SPE, _NAV };

enum custom_keycodes {
    DICT  = QK_USER, /* Hold: Left Ctrl + Win (GUI); release on key up */
    CXC_X = QK_USER_1, /* BASE X: HID KC_X; lets XC dict combo use CXC_* without delaying other combos on KC_X */
    CXC_C = QK_USER_2, /* BASE C: HID KC_C */
    /* OS-aware shortcuts: pick Windows vs macOS (Ctrl/Cmd swapped) chord at runtime */
    P_TAB,  /* previous tab */
    N_TAB,  /* next tab */
    P_DESK, /* previous desktop / space */
    N_DESK, /* next desktop / space */
    CAPTURE, /* region screenshot */
};

#define NUM MO(_NUM)
#define FUN MO(_FUN)
#define SPE MO(_SPE)
#define NAV MO(_NAV)

#define SPC_NAV LT(_NAV, KC_SPC)
#define ESC_ALT MT(MOD_LALT, KC_ESC)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define NUM_TAB LT(_NUM, KC_TAB)
/* Left thumb: tap = Caps Lock (macOS maps Caps Lock to 한/영), hold = Ctrl (Windows) / Cmd (macOS, handled in process_record_user) */
#define THMB_L LCTL_T(KC_CAPS)

#define SWITCH S(C(KC_TAB))
#define SWITCH2 S(C(KC_TAB))
#define BROWSER_BACK A(S(G(KC_O)))
#define BROWSER_FORWARD A(S(G(KC_P)))

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

const uint16_t PROGMEM combo_cc[] = {HOME_D, CXC_C, COMBO_END};
const uint16_t PROGMEM combo_cv[] = {HOME_F, KC_V, COMBO_END};
const uint16_t PROGMEM combo_cx[] = {HOME_S, CXC_X, COMBO_END};
const uint16_t PROGMEM combo_cb[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM combo_semicolon[] = {KC_DOT, KC_QUES, COMBO_END};
const uint16_t PROGMEM combo_colon[] = {HOME_L, HOME_QUOT, COMBO_END};
const uint16_t PROGMEM combo_colon_num[] = {KC_CIRC, KC_MINS, COMBO_END};
const uint16_t PROGMEM combo_back[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_forward[] = {KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM combo_capsword[] = {HOME_J, KC_G, KC_H, HOME_F, COMBO_END};
const uint16_t PROGMEM combo_tog_num_word[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_tog_num_word2[] = {KC_1, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo_capture[] = {KC_Q, KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_xc_dict[] = {CXC_X, CXC_C, COMBO_END};
const uint16_t PROGMEM combo_xz_ent[] = {KC_Z, CXC_X, COMBO_END};

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
    COMBO(combo_colon_num, KC_COLN),
    COMBO(combo_back, BROWSER_BACK),
    COMBO(combo_forward, BROWSER_FORWARD),
    //COMBO(combo_capsword, QK_CAPS_WORD_TOGGLE),
    COMBO(combo_capsword, KC_CAPS),
    COMBO(combo_tog_num_word, TG(NUM)),
    COMBO(combo_tog_num_word2, TG(NUM)),
    COMBO(combo_capture, CAPTURE),
    COMBO(combo_xc_dict, DICT),
    COMBO(combo_xz_ent, KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_ortho_4x12(
        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       XXXXXXX,    XXXXXXX,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
        HOME_A,     HOME_S,     HOME_D,     HOME_F,     KC_G,       XXXXXXX,    XXXXXXX,    KC_H,       HOME_J,     HOME_K,     HOME_L,     HOME_QUOT,
        KC_Z,       CXC_X,      CXC_C,      KC_V,       KC_B,       XXXXXXX,    XXXXXXX,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_QUES,
        XXXXXXX,    XXXXXXX,    ESC_ALT,    THMB_L,     NUM_TAB,    XXXXXXX,    XXXXXXX,    SFT_ENT,    SPC_NAV,    KC_BSPC,    FUN,        TT(_GAME)
    ),
    [_GAME] = LAYOUT_ortho_4x12(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_ENT,
        KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_RSFT,
        KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_SPC,     KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     _______
    ),
    [_NUM] = LAYOUT_ortho_4x12(
        XXXXXXX,    KC_1,       KC_2,       KC_3,       KC_PLUS,    XXXXXXX,    XXXXXXX,    KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_UNDS,
        KC_0,       KC_4,       KC_5,       KC_6,       KC_EQL,     XXXXXXX,    XXXXXXX,    KC_ASTR,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_MINS,
        SWITCH,     KC_7,       KC_8,       KC_9,       KC_BSLS,    XXXXXXX,    XXXXXXX,    KC_GRV,     KC_AMPR,    KC_COMM,    KC_DOT,     KC_SLSH,
        _______,    _______,    _______,    SPE,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX
    ),
    [_FUN] = LAYOUT_ortho_4x12(
        KC_F10,     KC_F1,      KC_F2,      KC_F3,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_F11,     KC_F4,      KC_F5,      KC_F6,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_F12,     KC_F7,      KC_F8,      KC_F9,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_SPE] = LAYOUT_ortho_4x12(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    QK_BOOT,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_NAV] = LAYOUT_ortho_4x12(
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    P_DESK,     KC_UP,      N_DESK,     XXXXXXX,
        _______,    _______,    _______,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RGHT,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    P_TAB,      SWITCH2,    N_TAB,      XXXXXXX,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    )
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    (void)index;
    /* Solo CXC_X / CXC_C wait max of these when the key is only part of incomplete combos that include it. */
    if (combo->keys == combo_xc_dict) {
        return 32;
    }
    if (combo->keys == combo_cx) {
        return 26;
    }
    if (combo->keys == combo_cc) {
        return 26;
    }
    if (combo->keys == combo_xz_ent) {
        return 32;
    }
    return COMBO_TERM;
}

/* Only the left thumb resolves to hold as soon as another key is pressed,
 * so quick rolls like thumb+key apply the modifier. Home row mods are excluded. */
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return keycode == THMB_L;
}

static bool host_is_mac(void) {
#ifdef OS_DETECTION_ENABLE
    switch (detected_host_os()) {
        case OS_MACOS:
        case OS_IOS:
            return true;
        default:
            return false;
    }
#else
    return false;
#endif
}

/* No OS-level Ctrl<->Cmd swap: the firmware sends the real per-OS chord.
 * macOS uses Cmd (G) for app shortcuts and Ctrl (C) for spaces. */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* Left thumb: tap = Caps Lock (한/영 on macOS), hold = Ctrl (Windows) / Cmd (macOS).
         * Handled here (return false on hold) to bypass BILATERAL_COMBINATIONS, so a
         * fast thumb+key roll (e.g. thumb+T) applies the modifier immediately (Ctrl+T). */
        case THMB_L:
            if (record->tap.count == 0) { /* hold (incl. hold-on-other-key-press) */
                uint8_t mod = host_is_mac() ? MOD_BIT(KC_LGUI) : MOD_BIT(KC_LCTL);
                if (record->event.pressed) {
                    register_mods(mod);
                } else {
                    unregister_mods(mod);
                }
                return false;
            }
            return true; /* tap => KC_CAPS */
        /* Home-row D: keep the normal mod-tap path (bilateral protection). Only remap
         * the hold modifier to Cmd on macOS. */
        case LCTL_T(KC_D):
            if (host_is_mac() && record->tap.count == 0) {
                if (record->event.pressed) {
                    register_mods(MOD_BIT(KC_LGUI));
                } else {
                    unregister_mods(MOD_BIT(KC_LGUI));
                }
                return false;
            }
            return true;
        case CAPTURE:
            if (record->event.pressed) {
                /* macOS region capture ⌘⇧4; Windows region capture Win+Shift+S */
                tap_code16(host_is_mac() ? G(S(KC_4)) : G(S(KC_S)));
            }
            return false;
        case P_TAB:
            if (record->event.pressed) {
                /* macOS previous tab ⌘⇧[; Windows Ctrl+PgUp */
                tap_code16(host_is_mac() ? G(S(KC_LBRC)) : C(KC_PGUP));
            }
            return false;
        case N_TAB:
            if (record->event.pressed) {
                /* macOS next tab ⌘⇧]; Windows Ctrl+PgDn */
                tap_code16(host_is_mac() ? G(S(KC_RBRC)) : C(KC_PGDN));
            }
            return false;
        case P_DESK:
            if (record->event.pressed) {
                /* macOS previous space Ctrl+Left; Windows Win+Ctrl+Left */
                tap_code16(host_is_mac() ? C(KC_LEFT) : G(C(KC_LEFT)));
            }
            return false;
        case N_DESK:
            if (record->event.pressed) {
                /* macOS next space Ctrl+Right; Windows Win+Ctrl+Right */
                tap_code16(host_is_mac() ? C(KC_RIGHT) : G(C(KC_RIGHT)));
            }
            return false;
        case DICT:
            if (record->event.pressed) {
                register_mods(DICT_MODS);
            } else {
                unregister_mods(DICT_MODS);
            }
            return false;
        case CXC_X:
            if (record->event.pressed) {
                register_code(KC_X);
            } else {
                unregister_code(KC_X);
            }
            return false;
        case CXC_C:
            if (record->event.pressed) {
                register_code(KC_C);
            } else {
                unregister_code(KC_C);
            }
            return false;
        default:
            return true;
    }
}
