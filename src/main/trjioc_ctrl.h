#pragma once

#include <cstdint>

/// @file
/// @brief TRJIOCレジスタのctrl機能。
enum class TRJIOC_CTRL : uint8_t {
  ALWAYS = 0,
  DURING_INT2_HIGH = 1,
  TMR_RC = 2,
};

