// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _NAV,
    _MOUSE,
    _SYM,
    _NUM,
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_P RGUI_T(KC_P)

// Thumb keys (layers)
#define TH_SPC LT(_NAV, KC_SPC)
#define TH_TAB LT(_MOUSE, KC_TAB)
#define TH_ENT LT(_SYM, KC_ENT)
#define TH_BSPC LT(_NUM, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
* Empty
*  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
*  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
*  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
*  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
*                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
*/

/*
 * EMPTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */


/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   '  |      | 
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   P  |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |  ESC | SPC  | / TAB   /       \ ENT  \  | BSP | DEL  |      |      |
 *            |      |      |      |  NAV |/ MOUSE /         \ SYM  \ | NUM |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,                        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  XXXXXXX, KC_Q   ,   KC_W,     KC_E,       KC_R,       KC_T,                           KC_Y,       KC_U,       KC_I,       KC_O,       KC_QUOT,    XXXXXXX,
  XXXXXXX, HOME_A ,   HOME_S,   HOME_D,     HOME_F,     KC_G,                           KC_H,       HOME_J,     HOME_K,     HOME_L,     HOME_P,     XXXXXXX,
  XXXXXXX, KC_Z   ,   KC_X,     KC_C,       KC_V,       KC_B, KC_MUTE,      XXXXXXX,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX,
                 XXXXXXX,XXXXXXX,KC_ESC, TH_SPC, TH_TAB,                             TH_ENT,  TH_BSPC, KC_DEL, XXXXXXX, XXXXXXX
),
/*
 * NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | REDO | PASTE| COPY |  CUT | UNDO |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LGUI | LAlt | LCTR |LShift|      |-------.    ,-------| LEFT | DOWN | UP   | RIGHT| CAPS|      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|INSERT|HOME  |PGDOWN| PGUP | END  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \ENTER \  | BSPC | DEL  |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      LCTL(KC_Y), KC_PSTE, KC_COPY,  KC_CUT , KC_UNDO, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                         KC_LEFT, KC_DOWN,  KC_UP  , KC_RGHT, KC_CAPS, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, KC_INS , KC_HOME, KC_PGDN,  KC_PGUP, KC_END , XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_ENT,  KC_BSPC, KC_DEL, XXXXXXX, XXXXXXX
),
/*
 *  MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | REDO | PASTE| COPY |  CUT | UNDO |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LGUI | LAlt | LCTR |LShift|      |-------.    ,-------|      | LEFT | DOWN | UP   | RIGHT|      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |WHEELL|WHEELD|WHEELU|WHEELR|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \RIGHT \  | LEFT | MIDD |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_MOUSE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      LCTL(KC_Y), KC_PSTE, KC_COPY, KC_CUT , KC_UNDO, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                         MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       MS_BTN2, MS_BTN1, MS_BTN3, XXXXXXX, XXXXXXX
  ),
/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  `   |  ~   |  #   |  &   |   |  |                    |   ^  |   {  |   }  |   [  |  ]   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  !   |  _   |  :   |  =   |   $  |-------.    ,-------|   @  |   (  |   )  |   _  |  ;   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  %   |  ?   |  *   |  +   |   \  |-------|    |-------|   /  |   -  |   <  |   >  |  "   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_SYM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_GRV , KC_TILD, KC_HASH, KC_AMPR, KC_PIPE,                         KC_CIRC, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, XXXXXXX,
  XXXXXXX, KC_EXLM, KC_UNDS, KC_COLN, KC_EQL , KC_DLR ,                         KC_AT  , KC_LPRN, KC_RPRN, KC_UNDS, KC_SCLN, XXXXXXX,
  XXXXXXX, KC_PERC, KC_QUES, KC_ASTR, KC_PLUS, KC_BSLS, XXXXXXX,       XXXXXXX, KC_SLSH, KC_MINS, KC_LABK, KC_RABK, KC_DQUO, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
/*
 * NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   7  |   8  |   9  |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   4  |   5  |   6  |      |-------.    ,-------|      | SHIFT| CTRL | ALT  | SUPER|      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |   1  |   2  |   3  |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |  0   | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_NUM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_7   , KC_8   , KC_9   , XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_4   , KC_5   , KC_6   , XXXXXXX,                         XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,   
  XXXXXXX, XXXXXXX, KC_1   , KC_2   , KC_3   , XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, KC_0   , XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}


 