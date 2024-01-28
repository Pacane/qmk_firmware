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

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LSFT_T(KC_T)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)


// Left-hand home row mods
#define HOME_Q LCTL_T(KC_Q)
#define HOME_W LALT_T(KC_W)
#define HOME_F LGUI_T(KC_F)
#define HOME_P LSFT_T(KC_P)

// Right-hand home row mods
#define HOME_L RSFT_T(KC_L)
#define HOME_U RGUI_T(KC_U)
#define HOME_Y LALT_T(KC_Y)
#define HOME_SC RCTL_T(KC_SCLN)

#define MEH_ESC MEH_T(KC_ESC)
#define LCTL_TAB LCTL_T(KC_TAB)
#define RSFT_QUOT RSFT_T(KC_QUOT)

enum layer_names {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _WINDOWS,
  _SSYM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MEH_ESC,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,     KC_Y,   KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  HOME_A, HOME_R,  HOME_S,  HOME_T,  KC_G,                         KC_M,    HOME_N,  HOME_E,   HOME_I, HOME_O,  RSFT_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_TAB, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM,  KC_DOT, KC_SLSH, LALT_T(KC_ESC),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LGUI,  MO(_LOWER), LT(_SSYM, KC_SPC),     KC_ENT,   LT(_RAISE, KC_BSPC),  RALT_T(KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),
  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB, XXXXXXX, XXXXXXX , KC_UP, XXXXXXX, KC_MPRV,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MO(_WINDOWS), XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, KC_MPLY,                       KC_H,    KC_J,    KC_K,    KC_L,    XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, KC_RBRC, XXXXXXX, KC_MNXT,                     KC_LBRC, S(KC_RBRC),XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,    LALT(KC_ENT),   MO(_ADJUST), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV, KC_1,   KC_2,     KC_3,   KC_4,    KC_5,                           KC_6,    KC_7,          KC_8,          KC_9 ,   KC_0,    KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, KC_BSLS, RALT(KC_LBRC), RALT(KC_QUOT), KC_LPRN,          KC_RPRN, RALT(KC_BSLS), RALT(KC_RBRC), S(KC_BSLS) ,  KC_HOME, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_MINS, KC_EQL, S(KC_MINS), S(KC_8), S(KC_GRV),                      KC_PAUS, KC_F12,       KC_INS,       KC_DEL,  KC_END , KC_PGDN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(_ADJUST), KC_BSPC,    _______, _______, KC_RALT
                                      //`--------------------------'  `-------------------------
  ),
  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, RGB_MODE_FORWARD, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,               KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_HUI, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______, _______,    _______, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),
  [_WINDOWS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, LSA(KC_1), LSA(KC_2), LSA(KC_3), LSA(KC_4), LSA(KC_5),   LSA(KC_6), LSA(KC_7), LSA(KC_8), LSA(KC_9) , LSA(KC_0), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSA(KC_T), KC_LCTL,                    LSA(KC_H), LSA(KC_J), LSA(KC_K), LSA(KC_L), XXXXXXX, KC_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   KC_LGUI, _______, LSA(KC_SPC),            _______, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),
  [_SSYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,                      XXXXXXX, HOME_N,  HOME_E,   HOME_I,  HOME_O,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI,  MO(_LOWER),  KC_SPC,     KC_ENT,   LT(_RAISE, KC_BSPC),  RALT_T(KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),
};
