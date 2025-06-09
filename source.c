#include QMK_KEYBOARD_H

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_Q, // reads as C(ustom) + KC_A, but you may give any name here
    CKC_W,
    CKC_E,
    CKC_R,
    CKC_U,
    CKC_I,
    CKC_O,
    CKC_P,
    SMTD_KEYCODES_END,
};

#include "sm_td.h"

// Layer names for clarity
enum layers {
    _BASE = 0,
    _LAYER1 = 1,
    _LAYER2 = 2,
    _LAYER3 = 3,
    _LAYER4 = 4,
    _LAYER5 = 5
};

#ifdef LAYOUT_split_3x6_3_ex2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_TAB, CKC_Q, CKC_W, CKC_E, CKC_R, KC_T, LSFT(KC_9),    LSFT(KC_0), KC_Y, CKC_U, CKC_I, CKC_O, CKC_P, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      LCTL(KC_S),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LBRC,    KC_RBRC,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
         MO(1),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                            MO(2), KC_BSPC, ALL_T(KC_ESC),     KC_ENT, KC_SPC,   MO(3)
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAYER1] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_EQL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_LCTL,    KC_RCTL,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_NO, KC_NO, KC_NO, LCA(KC_F), KC_NO, KC_LALT,  KC_RALT, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_NO, KC_NO, LCA(KC_C), KC_NO, KC_NO,           LCA(KC_LEFT), LCA(KC_DOWN), LCA(KC_UP), LCA(KC_RIGHT), KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_TRNS,  KC_SPC,     LCA(KC_ENT), LCAG(KC_LEFT), LCAG(KC_RIGHT)
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAYER2] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      KC_TRNS, KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,    KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAYER3] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_TRNS,  KC_SPC,     KC_ENT, KC_TRNS, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAYER4] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAYER5] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  )
};
#else
// Standard layout without extra keys would go here
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Add standard 3x6_3 layout here if needed
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    // your code here

   return true;
}

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_Q, KC_Q, KC_LEFT_ALT)
        SMTD_MT(CKC_W, KC_W, KC_LEFT_SHIFT)
        SMTD_MT(CKC_E, KC_E, KC_LEFT_CTRL)
        SMTD_MT(CKC_R, KC_R, KC_LEFT_GUI)
        SMTD_MT(CKC_P, KC_P, KC_LEFT_ALT)
        SMTD_MT(CKC_O, KC_O, KC_LEFT_SHIFT)
        SMTD_MT(CKC_I, KC_I, KC_LEFT_CTRL)
        SMTD_MT(CKC_U, KC_U, KC_LEFT_GUI)
    }
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_BASE]   = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
  [_LAYER1] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
  [_LAYER2] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
  [_LAYER3] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
  [_LAYER4] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
  [_LAYER5] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

