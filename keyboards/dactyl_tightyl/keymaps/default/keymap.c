// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/achordion.h"

// Layers
#define BASE 0
#define NO_HRM 1
#define SYM 2
#define NAV 3
#define NUM 4

// One shot mods
#define MRGUI OSM(MOD_RGUI)
#define MRALT OSM(MOD_RALT)
#define MRCTL OSM(MOD_RCTL)
#define MRSFT OSM(MOD_RSFT)

#define MLGUI OSM(MOD_LGUI)
#define MLALT OSM(MOD_LALT)
#define MLCTL OSM(MOD_LCTL)
#define MLSFT OSM(MOD_LSFT)

// Home row mods
#define HRM_Z LGUI_T(KC_Z)
#define HRM_S LALT_T(KC_S)
#define HRM_D LCTL_T(KC_D)
#define HRM_F LSFT_T(KC_F)

#define HRM_J RSFT_T(KC_J)
#define HRM_K RCTL_T(KC_K)
#define HRM_L LALT_T(KC_L)
#define HRM_SLS RGUI_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base
     * ,------,------,------,------,------,------,                          ,------,------,------,------,------,------,
     * | TAB  |   q  |   w  |   e  |   r  |   t  |                          |   y  |   u  |   i  |   o  |   p  | BSPC |
     * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
     * | CAPS |   a  | s(A) | d(C) | f(S) |   g  |                          |   h  | j(S) | k(C) | l(A) |   ;  |   '  |
     * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
     * | SHIFT| z(G) |   x  |   c  |   v  |   b  |                          |   n  |   m  |   ,  |   .  | /(G) | SHIFT|
     * '------'------+------+------+------+------'                          '------'------+------+------+------'------'
     *               | CTRL |  ALT |                                                      |  ALT | CTRL |
     *               '------'------+------,------,------,            ,------,------,------+------'------'
     *                             | NAV  | SPACE| META |            | ENTER| SPACE| SYM  |
     *                             '------'------'------'            '------'------'------'
     */

    [BASE] = LAYOUT(
         KC_TAB,   KC_Q,   KC_W,    KC_E,   KC_R,   KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
        KC_CAPS,   KC_A,  HRM_S,   HRM_D,  HRM_F,   KC_G,                        KC_H,   HRM_J,   HRM_K,   HRM_L, KC_SCLN, KC_QUOT,
        KC_LSFT,  HRM_Z,   KC_X,    KC_C,   KC_V,   KC_B,                        KC_N,    KC_M, KC_COMM,  KC_DOT, HRM_SLS, KC_RSFT,
                        KC_LCTL, KC_LALT,                                                       KC_RALT, KC_RCTL,
                                         TL_UPPR, KC_SPC, KC_LGUI,     KC_ENT, KC_SPC, TL_LOWR
    ),

    /* No HRM mods layer
     * ,------,------,------,------,------,------,                          ,------,------,------,------,------,------,
     * | ____ | ____ | ____ | ____ | ____ | ____ |                          | ____ | ____ | ____ | ____ | ____ | ____ |
     * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
     * | ____ | ____ |   s  |   d  |   f  | ____ |                          | ____ |   j  |   k  |   l  | ____ | ____ |
     * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
     * | ____ |   z  | ____ | ____ | ____ | ____ |                          | ____ | ____ | ____ | ____ |   /  | ____ |
     * '------'------+------+------+------+------'                          '------'------+------+------+------'------'
     *               | ____ | ____ |                                                      | ____ | ____ |
     *               '------'------+------,------,------,            ,------,------,------+------'------'
     *                             | ____ | ____ | ____ |            | ____ | ____ | ____ |
     *                             '------'------'------'            '------'------'------'
     */

    [NO_HRM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
        _______, _______,    KC_S,    KC_D,    KC_F, _______,                        _______,    KC_J,    KC_K,    KC_L, _______, _______,
        _______,    KC_Z, _______, _______, _______, _______,                        _______, _______, _______, _______, KC_SLSH, _______,
                          _______, _______,                                                            _______, _______,
                                            _______, _______, _______,      _______, _______, _______
    ),

    /* Symbol layer
     * ,------,------,------,------,------,------,                          ,------,------,------,------,------,------,
     * |   ~  |   +  |   &  |   *  |   (  |   {  |                          |   }  |   )  |   '  |   :  |   ;  | ____ |
     * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
     * |   `  |   =  |   $  |   %  |   ^  |   [  |                          |   ]  | SHIFT| CTRL |  ALT | META |   |  |
     * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
     * |   _  |   -  |   !  |   @  |   #  |   <  |                          |   >  |   "  | ____ | ____ | ____ |   \  |
     * '------'------+------+------+------'------'                          '------'------+------+------+------'------'
     *               | ____ | ____ |                                                      | ____ | ____ |
     *               '------'------+------,------,------,            ,------,------,------+------'------'
     *                             | ____ | ____ | ____ |            | ____ | ____ | ____ |
     *                             '------'------'------'            '------'------'------'
     */

     [SYM] = LAYOUT(
        KC_TILD, KC_PPLS, KC_AMPR, KC_ASTR, KC_LPRN, KC_LCBR,                     KC_RCBR, KC_RPRN, KC_QUOT, KC_COLN, KC_SCLN, _______,
         KC_GRV, KC_PEQL,  KC_DLR, KC_PERC, KC_CIRC, KC_LBRC,                     KC_RBRC,   MRSFT,   MRCTL,   MRALT,   MRGUI, KC_PIPE,
        KC_UNDS, KC_MINS, KC_EXLM,   KC_AT, KC_HASH,   KC_LT,                       KC_GT,  KC_DQT, _______, _______, _______, KC_BSLS,
                          _______, _______,                                                         _______, _______,
                                            _______, _______, _______,   _______, _______, _______
    ),

    /* Nav layer
     * ,------,------,------,------,------,------,                          ,------,------,------,------,------,------,
     * |  ESC |      | PREV | PAUSE| NEXT |  VL+ |                          | PGUP | HOME |  UP  |  END |      | ____ |
     * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
     * | ALTAB|  GUI |  ALT | CTRL | SHIFT|  VL- |                          | CLEFT| LEFT | DOWN | RIGHT| CRGHT|  DEL |
     * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
     * | PRTSC|      |      |      | STOP | MUTE |                          | PGDN | TABL |      |  TAB |      |  INS |
     * '------'------+------+------+------'------'                          '------'------+------+------+------'------'
     *               | ____ | ____ |                                                      | ____ | ____ |
     *               '------'------+------,------,------,            ,------,------,------+------'------'
     *                             | ____ | ____ | ____ |            | ____ | ____ | ____ |
     *                             '------'------'------'            '------'------'------'
     */

    [NAV] = LAYOUT(
         KC_ESC,   KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                     KC_PGUP,   KC_HOME,   KC_UP,  KC_END,      KC_NO, _______,
      A(KC_TAB),   MLGUI,   MLALT,   MLCTL,   MLSFT, KC_VOLD,                  C(KC_LEFT),   KC_LEFT, KC_DOWN, KC_RGHT, C(KC_RGHT),  KC_DEL,
        KC_PSCR,   KC_NO,   KC_NO,   KC_NO, KC_MSTP, KC_MUTE,                     KC_PGDN, S(KC_TAB),   KC_NO,  KC_TAB,      KC_NO,  KC_INS,
                          _______, _______,                                                         _______, _______,
                                            _______, _______, _______,   _______, _______, _______
    ),

    /* Num layer
     * ,------,------,------,------,------,------,                          ,------,------,------,------,------,------,
     * |      |      |  F7  |  F8  |  F9  |  F10 |                          |   +  |   7  |   8  |   9  |   *  | ____ |
     * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
     * | NLCK |      |  F4  |  F5  |  F6  |  F11 |                          |   =  |   4  |   5  |   6  |   ,  |  DEL |
     * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
     * | TG(1)|      |  F1  |  F2  |  F3  |  F12 |                          |   -  |   1  |   2  |   3  |   /  |  ENT |
     * '------'------+------+------+------'------'                          '------'------+------+------+------'------'
     *               | ____ | ____ |                                                      |   0  |   .  |
     *               '------'------+------,------,------,            ,------,------,------+------'------'
     *                             | ____ | ____ | ____ |            | ____ | ____ | ____ |
     *                             '------'------'------'            '------'------'------'
     */

    [NUM] = LAYOUT(
          KC_NO,   KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                     KC_PPLS,   KC_P7,   KC_P8,   KC_P9, KC_PAST, _______,
         KC_NUM,   KC_NO,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                     KC_PEQL,   KC_P4,   KC_P5,   KC_P6, KC_COMM,  KC_DEL,
          TG(1),   KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                     KC_PMNS,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PENT,
                          _______, _______,                                                           KC_P0, KC_PDOT,
                                            _______, _______, _______,   _______, _______, _______
    )
};

// Achordion
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    return true;
};

void housekeeping_task_user(void) {
    achordion_task();
};

uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
    // No timeout for shift and ctrl mod-tap keys
    if (QK_MOD_TAP_GET_MODS(tap_hold_keycode) & (MOD_LSFT | MOD_LCTL)) {
        return 0;
    }

    // No timeout for layer keys
    if (IS_QK_MOMENTARY(next_keycode)) {
        return 0;
    }

    // Default timeout
    return 200;
};
