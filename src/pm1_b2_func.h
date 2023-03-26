#pragma once

#include <cstdint>

/// @file
/// @brief  PM1レジスタのb2定義。
enum class PM1_B2_FUNC : uint8_t {
  IO_OR_AD = 0,
  TRCIOB = 1,
  KI2 = 2,
};

