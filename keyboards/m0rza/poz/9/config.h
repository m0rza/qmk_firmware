// Copyright 2022 cdelcristo (@cdelcristo)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

// #include "config_common.h"

// #define VENDOR_ID       0x4D44  //MorzaDesigns
// #define PRODUCT_ID      0x0009 
// #define DEVICE_VER      0x0002

#define WS2812_DI_PIN F4
#define RGBLIGHT_LED_COUNT 3
#define RGBLIGHT_LAYERS
// #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #define RGB_MATRIX_KEYPRESSES
// #define ENABLE_RGB_MATRIX_BREATHING
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE


/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
