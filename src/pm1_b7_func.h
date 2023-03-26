#pragma once

#include <cstdint>

/// @file
/// @brief PM1レジスタのb7定義。
enum class PM1_B7_FUNC : uint8_t {
  IO_AN7_IVCMP1 = 0,
  INT1 = 1,
  TRJIO = 2,
  TRCCLK = 3
};

