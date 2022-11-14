// Copyright 2022 Henrich Fergian (@Henrich Fergian)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* Set 0 if debouncing isn't needed */
// #define DEBOUNCE 5

// Force the usage of PIO1 peripheral, by default the WS2812 implementation uses the PIO0 peripheral
// #define WS2812_PIO_USE_PIO1


// use rp2040 default i2c config: i2c1 driver, sda=gp2, scl=gp3

// #undef I2C_DRIVER
// #define I2C_DRIVER I2CD1
// #undef I2C1_SCL_PIN
// #define I2C1_SCL_PIN <scl_pin>
// #undef I2C1_SDA_PIN
// #define I2C1_SDA_PIN <sda_pin>

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
