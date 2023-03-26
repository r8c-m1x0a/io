#pragma once

#include <cstdint>

/// @file
/// @brief PM1レジスタのb0機能。
enum class PM1_B0_FUNC : uint8_t {
  IO_OR_AD = 0,
  TRCIOD = 1,
  KI0 = 2,
};

