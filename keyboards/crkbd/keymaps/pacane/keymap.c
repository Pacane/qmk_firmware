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
#include <stdio.h>

enum layer_names {
  _CLMK,
  _QWERTY,
  _LOW,
  _UP,
  _ADJ,
  _WIN,
  _SYM,
  _FUN,
  _FR,
  _BRKT,
};
#define HOME_Q LCTL_T(KC_Q)
#define HOME_W LALT_T(KC_W)
#define HOME_F LGUI_T(KC_F)
#define HOME_P LSFT_T(KC_P)
#define HOME_B LT(_FR, KC_B)

#define HOME_J LT(_FR, KC_J)
#define HOME_L RSFT_T(KC_L)
#define HOME_U RGUI_T(KC_U)
#define HOME_Y LALT_T(KC_Y)
#define HOME_SCLN RCTL_T(KC_SCLN)

#define HOME_A LCTL_T(KC_A)
#define HOME_R RALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LSFT_T(KC_T)
#define HOME_G LT(_FR, KC_G)

#define HOME_M LT(_FR, KC_M)
#define HOME_N RSFT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)

#define HOMEQ_A LCTL_T(KC_A)
#define HOMEQ_S LALT_T(KC_S)
#define HOMEQ_D LGUI_T(KC_D)
#define HOMEQ_F LSFT_T(KC_F)
#define HOMEQ_G LT(_FR, KC_G)

#define HOMEQ_H LT(_FR, KC_H)
#define HOMEQ_J LSFT_T(KC_J)
#define HOMEQ_K LGUI_T(KC_K)
#define HOMEQ_L LALT_T(KC_L)
#define HOMEQ_SCLN LCTL_T(KC_SCLN)

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
#define T_UP LT(_UP, KC_BSPC)
#define T_LOW LT(_LOW, KC_ESC)
#define T_SYM LT(_SYM, KC_ENT)
#define T_BRKT LT(_BRKT, KC_COMM)

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

#define L_SQ_BKT RALT(KC_LBRC)
#define R_SQ_BKT RALT(KC_RBRC)

#define L_CL_BKT RALT(KC_QUOT)
#define R_CL_BKT RALT(KC_BSLS)

#define L_CHEV KC_BSLS
#define R_CHEV S(KC_BSLS)

#define PLUS S(KC_EQL)
#define PIPE S(KC_GRV)
#define UNDSCR S(KC_MINS)
#define MULTPL S(KC_8)
#define AT RALT(KC_2)

enum custom_keycodes {
    PASSWD = SAFE_RANGE,
    CCED,
    EGRAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CLMK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MEH_ESC,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,     KC_Y,   KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  HOME_A, HOME_R,  HOME_S,  HOME_T,  HOME_G,                       HOME_M,  HOME_N,  HOME_E,   HOME_I, HOME_O,  RSFT_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_TAB, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    T_BRKT,   KC_DOT, KC_SLSH, KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         T_FUN,   T_LOW,   KC_SPC,     T_SYM,   T_UP,    RALT_T(KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),
  [_LOW] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB,  XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,  KC_MPRV,                     U_UND,   U_PST,   U_CPY,   U_CUT,    U_RDO,   KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    MO(_WIN), XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_MPLY,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, XXXXXXX, XXXXXXX, KC_RBRC, XXXXXXX,  KC_MNXT,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,   XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   LALT(KC_ENT), MO(_ADJ), _______
                                      //`--------------------------'  `--------------------------'
  ),
  [_UP] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,  S(KC_1), S(KC_2),S(KC_3), S(KC_4), S(KC_5),                      S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, PIPE,    L_CHEV, L_SQ_BKT,L_CL_BKT,KC_LPRN,                      KC_RPRN, R_CL_BKT,R_SQ_BKT,R_CHEV,  KC_HOME, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           AT, UNDSCR,  KC_EQL, KC_MINS, PLUS,    MULTPL,                       KC_PAUS, KC_F12,  KC_INS,  KC_DEL,  KC_END , KC_PGDN,
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
      RGB_HUI, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       PASSWD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
     XXXXXXX, S(KC_3), KC_7,    KC_8,    KC_9,    PLUS,                         XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, S(KC_8), KC_4,    KC_5,    KC_6,    KC_MINS,                      XXXXXXX, KC_LSFT, KC_LGUI,  KC_LALT, KC_LCTL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, S(KC_5), KC_1,    KC_2,    KC_3,    KC_EQL,                       XXXXXXX, XXXXXXX, XXXXXXX,  KC_DOT,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______,  KC_0,  KC_SPC,     _______,  KC_BSPC,  RALT_T(KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),
  [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    TO(_CLMK), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_F10,   KC_F7,   KC_F8,  KC_F9, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  TO(_QWERTY), _______, _______, _______, _______, _______,                       KC_F11,   KC_F4,   KC_F5,  KC_F6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+-------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_F12,   KC_F1,   KC_F2,  KC_F3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  [_FR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, EGRAV,   TREMA,   KC_LBRC, KC_QUOT,
  //|--------+--------+--------+--------+-------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, CCED,    XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MEH_ESC, KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,      KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, HOMEQ_A,HOMEQ_S, HOMEQ_D, HOMEQ_F, HOMEQ_G,                      HOMEQ_H, HOMEQ_J, HOMEQ_K,  HOMEQ_L,HOMEQ_SCLN,RSFT_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LCTL_TAB, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,   LALT_T(KC_ESC),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         T_FUN,   T_LOW,   KC_SPC,     T_SYM,   T_UP,    RALT_T(KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),
   [_BRKT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN,  XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, L_CHEV,  R_CHEV,  L_CL_BKT,R_CL_BKT, XXXXXXX,                     HOMEQ_H, HOMEQ_J, HOMEQ_K, HOMEQ_L, HOMEQ_SCLN,RSFT_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, L_SQ_BKT,R_SQ_BKT, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         T_FUN,   T_LOW,   KC_SPC,     T_SYM,   T_UP,    RALT_T(KC_DEL)
                                      //`--------------------------'  `--------------------------'
      // L_CHEV, L_SQ_BKT,L_CL_BKT,KC_LPRN,                      KC_RPRN, R_CL_BKT,R_SQ_BKT,R_CHEV,
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PASSWD:
        if (record->event.pressed) {
            SEND_STRING("motdepasse1234");
        }         break;
    case CCED:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_RBRC)"c");
        }         break;
    case EGRAV:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_QUOT)"e");
        }         break;
    }
    return true;
};

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_ALPHAS_MODS);
    rgb_matrix_sethsv(HSV_PURPLE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOW:
        rgb_matrix_sethsv(HSV_BLUE);
        break;
    case _UP:
        rgb_matrix_sethsv(HSV_CYAN);
        break;
    case _ADJ:
        rgb_matrix_sethsv(HSV_YELLOW);
        break;
    case _SYM:
        rgb_matrix_sethsv(HSV_RED);
        break;
    case _FUN:
        rgb_matrix_sethsv(HSV_ORANGE);
        break;
    case _WIN:
        rgb_matrix_sethsv(HSV_TEAL);
        break;
    case _QWERTY:
        rgb_matrix_sethsv(HSV_PINK);
        break;
    default: //  for any other layers, or the default layer
        rgb_matrix_sethsv(HSV_PURPLE);
        break;
    }
    return state;
}


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
    case _LOW:
            oled_write_P(PSTR("Lower\n"), false);
        break;
    case _UP:
            oled_write_P(PSTR("Raise\n"), false);
        break;
    case _ADJ:
            oled_write_P(PSTR("Adjust\n"), false);
        break;
    case _SYM:
            oled_write_P(PSTR("Symbols\n"), false);
        break;
    case _FUN:
            oled_write_P(PSTR("Functions\n"), false);
        break;
    case _WIN:
            oled_write_P(PSTR("Windows\n"), false);
        break;
    case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
        break;
    default: //  for any other layers, or the default layer
            oled_write_P(PSTR("Colemak\n"), false);
        break;
    }

    return false;
}
#endif
