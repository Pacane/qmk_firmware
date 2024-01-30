/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define HOME_A LCTL_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LSFT_T(KC_T)

#define HOME_N RSFT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)

#define MEH_ESC MEH_T(KC_ESC)
#define LCTL_TAB LCTL_T(KC_TAB)
#define RSFT_QUOT RSFT_T(KC_QUOT)
#define TREMA S(KC_RBRC)

#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

#define T_FUN LT(_FUN, KC_LGUI)

#define WS1 LSA(KC_1)
#define WS2 LSA(KC_2)
#define WS3 LSA(KC_3)
#define WS4 LSA(KC_4)
#define WS5 LSA(KC_5)
#define WS6 LSA(KC_6)
#define WS7 LSA(KC_7)
#define WS8 LSA(KC_8)
#define WS9 LSA(KC_9)
#define WS0 LSA(KC_0)

#define WSL LSA(KC_H)
#define WSD LSA(KC_J)
#define WSU LSA(KC_K)
#define WSR LSA(KC_L)

#define T_FLOAT LSA(KC_T)
#define W_SWAP LSA(KC_ENT)
#define L_CYCLE LSA(KC_SPC)

#define RGBU RGB_MODE_FORWARD

enum layer_names {
  _CLMK,
  _LOW,
  _UP,
  _ADJ,
  _WIN,
  _SYM,
  _FUN,
};

#define L_SQ_BKT RALT(KC_LBRC)
#define R_SQ_BKT RALT(KC_RBRC)

#define L_CL_BKT RALT(KC_QUOT)
#define R_CL_BKT RALT(KC_BSLS)

#define L_CHEV KC_BSLS
#define R_CHEV S(KC_BSLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CLMK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MEH_ESC,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,     KC_Y,   KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  HOME_A, HOME_R,  HOME_S,  HOME_T,  KC_G,                         KC_M,    HOME_N,  HOME_E,   HOME_I, HOME_O,  RSFT_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_TAB, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM,  KC_DOT, KC_SLSH, LALT_T(KC_ESC),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        T_FUN,  MO(_LOW), KC_SPC,     LT(_SYM, KC_ENT),   LT(_UP, KC_BSPC),  RALT_T(KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),
  [_LOW] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB,  XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,  KC_MPRV,                     U_UND,   U_PST,   U_CPY,   U_CUT,    U_RDO,   KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    MO(_WIN), XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_MPLY,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, XXXXXXX, XXXXXXX, KC_RBRC, XXXXXXX,  KC_MNXT,                     KC_LBRC, TREMA,   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, MO(_ADJ), _______
                                      //`--------------------------'  `--------------------------'
  ),
  [_UP] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, L_CHEV, L_SQ_BKT,L_CL_BKT,KC_LPRN,                      KC_RPRN, R_CL_BKT,R_CL_BKT,R_CHEV,  KC_HOME, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_MINS, KC_EQL, S(KC_MINS), S(KC_8), S(KC_GRV),                 KC_PAUS, KC_F12,  KC_INS,  KC_DEL,  KC_END , KC_PGDN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, MO(_ADJ), _______,   _______, _______, KC_RALT
                                      //`--------------------------'  `-------------------------
  ),
  [_ADJ] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, RGBU,    XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_HUI, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  [_WIN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, WS1,     WS2,     WS3,     WS4,     WS5,                          WS6,     WS7,     WS8,     WS9,     WS0,     XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, T_FLOAT, XXXXXXX,                      WSL,     WSD,     WSU,     WSR,     XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI, _______, L_CYCLE,    W_SWAP, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,                      XXXXXXX, KC_LSFT, KC_LGUI,  KC_LALT, KC_LCTL,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______,  KC_0,  KC_SPC,     _______,  KC_BSPC,  RALT_T(KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),
  [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, _______, _______, _______,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+-------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PAUS,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
};
