#pragma once

#include <cstdint>

/// @file
/// @brief PM4レジスタのb2機能。
enum class PM4_B2_FUNC : uint8_t {
  IO = 0,
  TRBO = 1,
  TXD0 = 2,
  KI3 = 3,
};

