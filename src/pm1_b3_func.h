#pragma once

#include <cstdint>

/// @file
/// @brief PM1レジスタのb3定義。
enum class PM1_B3_FUNC : uint8_t {
  IO_OR_AD = 0,
  TRCIOC = 1,
  KI3 = 2,
  TRBO = 3,
};

