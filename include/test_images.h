// Session 6 — baked-in test images for on-device vision (no camera needed).
//
// This is a PLACEHOLDER. Generate the real thing from actual pictures with:
//     pip install pillow
//     python tools/image_to_header.py person.jpg empty.jpg -o include/test_images.h
//
// That script overwrites this file with grayscale arrays named like
//     const uint8_t person_96[96*96] = { ... };
// at 48/96/160 px, so you can feed one to run_classifier() and time it.
//
// A tiny 4x4 example so this header is valid C on its own:
#pragma once
#include <stdint.h>

const uint8_t example_4[4 * 4] = {
    0,   255, 0,   255,
    255, 0,   255, 0,
    0,   255, 0,   255,
    255, 0,   255, 0,
};
