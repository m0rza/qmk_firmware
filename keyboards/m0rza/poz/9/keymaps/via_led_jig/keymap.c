#include QMK_KEYBOARD_H
#include "features/mouse_turbo_click.h"

enum custom_keycodes {
  TURBO = SAFE_RANGE,
  // Other custom keys...
};

// // 224x64
// led_config_t g_led_config = { {
//   // Key Matrix to LED Index
//   { NO_LED, NO_LED, NO_LED },
//   { 0, 1, 2 },
//   { NO_LED, NO_LED, NO_LED },
// }, {
//   // LED Index to Physical Position
//     { 0, 32}, { 112, 32}, { 224,32 },
//     { 112, 64},
// }, {
//   // LED Index to Flag
//   4, 4, 4, 4
// } };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬
     *  4 │ 5 │ 6 │
     * ├───┼───┼───┼
     * │ 1 │ 2 │ 3 │ 
     * ├───┼───┼───┼
     * │ 1 │ 2 │ 3 │
     */
    [0] = LAYOUT_3x3(
        KC_P7,   KC_P8,   QK_BOOT,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3

    ),
    [1] = LAYOUT_3x3(
        _______,   _______,   _______,
        _______,   _______,   _______,
        _______,   _______,   _______

    ),
    [2] = LAYOUT_3x3(
        _______,   _______,   _______,
        _______,   _______,   _______,
        _______,   _______,   _______

    ),
    [3] = LAYOUT_3x3(
        _______,   _______,   _______,
        _______,   _______,   _______,
        _______,   _______,   _______

    )
};


const rgblight_segment_t PROGMEM layer_1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_RED}
);
const rgblight_segment_t PROGMEM layer_2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_CYAN}
);
const rgblight_segment_t PROGMEM layer_3[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM layer_4[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_1,    // Overrides caps lock layer
    layer_2,    // Overrides other layers
    layer_3,    // Overrides other layers
    layer_4     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 0));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    return state;
}
// jiggler
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_mouse_turbo_click(keycode, record, TURBO)) { return false; }
  // Your macros ...

  return true;
}