// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

// More lighting options in quantum/rgblight/rgblight.h
#ifdef RGBLIGHT_ENABLE
#    define WS2812_DI_PIN D3
#    define RGBLED_NUM 2
#    define RGBLED_SPLIT {1,1}
// Disabling some of these is a good way to save flash space.
#endif
#pragma once

#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4
#define TAPPING_TERM 100
// #define RETRO_TAPPING
//
//
#define SPLIT_WPM_ENABLE
// Disabled to save space
#define NO_ACTION_ONESHOT  // 332
#define NO_ACTION_MACRO    // 0
#define NO_ACTION_FUNCTION // 0
#define DISABLE_LEADER     // 0
