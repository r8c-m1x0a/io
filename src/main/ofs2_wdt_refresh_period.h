#pragma once

#include <cstdint>

/// @file
/// @brief OFS2レジスタの
enum class OFS2_WDT_REFRESH_PERIOD : uint8_t {
  P25 = 0,
  P50 = 1,
  P75 = 2,
  P100 = 3,
};

