#pragma once

#include <cstdint>

/// @file
/// @brief PM3レジスタのb4機能。
enum class PM3_B4_FUNC : uint8_t {
  IO_OR_IVREF3 = 0,
  TRCIOC = 1,
  INT2 = 2,
};

