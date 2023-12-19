#pragma once

#define RGB_DISABLE_WHEN_USB_SUSPENDED
#undef RGB_MATRIX_DEFAULT_MODE //undefine default value
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 156
#define RGB_MATRIX_DEFAULT_SPD 128



#define ENABLE_RGB_MATRIX_ALPHAS_MODS //default enabled
// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT //default enabled
#define ENABLE_RGB_MATRIX_BREATHING //default enabled
// #define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL //default enabled
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL //default enabled
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL //default enabled
#undef ENABLE_RGB_MATRIX_CYCLE_ALL //default enabled
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT //default enabled
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN //default enabled
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON //default enabled
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN //default enabled
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL //default enabled
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL //default enabled
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL //default enabled
#undef ENABLE_RGB_MATRIX_DUAL_BEACON //default enabled
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON //default enabled
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS //default enabled
// #define ENABLE_RGB_MATRIX_RAINDROPS
// #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING //default enabled
#define ENABLE_RGB_MATRIX_HUE_PENDULUM //default enabled
#define ENABLE_RGB_MATRIX_HUE_WAVE //default enabled
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN //default enabled
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW //default enabled
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL //default enabled
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP //default enabled
// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #define ENABLE_RGB_MATRIX_SPLASH
// #define ENABLE_RGB_MATRIX_MULTISPLASH
// #define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
