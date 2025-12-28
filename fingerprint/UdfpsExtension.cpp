/*
 * Copyright (C) 2022-2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <compositionengine/UdfpsExtension.h>

#if __has_include(<display/drm/sde_drm.h>)
#include <display/drm/sde_drm.h>
#elif __has_include(<drm/sde_drm.h>)
#include <drm/sde_drm.h>
#endif

// Define FOD_PRESSED_LAYER_ZORDER if not present in headers
#ifndef FOD_PRESSED_LAYER_ZORDER
#define FOD_PRESSED_LAYER_ZORDER 0x41000031
#endif

uint32_t getUdfpsDimZOrder(uint32_t z) {
    return z;
}

uint32_t getUdfpsZOrder(uint32_t z, bool touched) {
    if (touched) {
        z |= FOD_PRESSED_LAYER_ZORDER;
    }
    return z;
}

uint64_t getUdfpsUsageBits(uint64_t usageBits, bool /* touched */) {
    return usageBits;
}
