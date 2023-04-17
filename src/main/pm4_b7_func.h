#pragma once

#include <cstdint>

/// @file
/// @brief PM4レジスタのb7機能。
enum class PM4_B7_FUNC : uint8_t {
  IO_OR_XOUT = 0,
  INT2 = 1,
};

