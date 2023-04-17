#pragma once

#include <cstdint>

/// @file
/// @brief PM3レジスタのb5機能。
enum class PM3_B5_FUNC : uint8_t {
  IO = 0,
  TRCIOD = 1,
  KI2 = 2,
  VCOUT3 = 3,
};

