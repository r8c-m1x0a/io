#pragma once

#include <cstdint>

/// @file
/// @brief PM1レジスタのb1定義。
enum class PM1_B1_FUNC : uint8_t {
  IO_OR_AD = 0,
  TRCIOA_TRCTRG = 1,
  KI1 = 2,
};

