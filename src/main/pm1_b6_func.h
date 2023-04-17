#pragma once

#include <cstdint>

/// @file
/// @brief PM1レジスタのb6定義。
enum class PM1_B6_FUNC : uint8_t {
  IO_IVREF1 = 0,
  CLK0 = 1,
  TRJO = 2,
  TRCIOB = 3
};

