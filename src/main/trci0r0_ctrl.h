#pragma once

#include <cstdint>

/// @file
/// @brief TRCI0R0レジスタのctrl。
enum class TRCIOR0_CTRL : uint8_t {
  OUT_COMP_DISABLED = 0,
  OUT_COMP_LOW_LEVEL = 1,
  OUT_COMP_HIGH_LEVEL = 2,
  OUT_COMP_TOGGLE = 3,
  IN_CAPT_RISING_EDGE = 4,
  IN_CAPT_FALLING_EDGE = 5,
  IN_CAPT_BOTH_EDGE = 6,
};

