#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬
     * │ 7 │ 8 │ 9 │
     * ├───┼───┼───┼
     * │ 4 │ 5 │ 6 │ 
     */
    [0] = LAYOUT_2x3(
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6

    )
};
