// Copyright 2023 Massdrop, Inc.
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_1800_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, KC_DEL,           KC_HOME, KC_END,  KC_PGUP, KC_PGDN,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          MO(2),   KC_PSLS, KC_PAST, KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,            KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             MO(1),   RCTL_T(KC_APP), KC_LEFT, KC_DOWN, KC_RGHT,          KC_P0,   KC_PDOT
    ),
    [1] = LAYOUT_1800_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,           _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_NUM,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP,          _______, _______, _______, _______,
        _______, _______, KC_RALT,                   _______,                            _______, KC_LALT,          KC_HOME, KC_PGDN, KC_END,           _______, _______
    ),
    [2] = LAYOUT_1800_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,           KC_MPLY, KC_MSTP, KC_VOLU, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MPRV, KC_MNXT, KC_VOLD, KC_SCRL,
        _______, RGB_TOG, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, DT_DOWN,
        _______, RGB_MOD, RGB_VAD, RGB_SPD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, DT_UP,
        _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,QK_BOOT, NK_TOGG, _______, _______, _______, _______, _______,          _______,          _______, _______, _______, DT_PRNT,
        _______, _______, _______,                   EE_CLR,                             _______, _______,           _______, _______, _______,          _______, _______
    )
};
