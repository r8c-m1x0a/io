#pragma once

#include <cstdint>

/// @file
/// @brief PM4レジスタのb5機能。
enum class PM4_B5_FUNC : uint8_t {
  IO = 0,
  INT0 = 1,
  ADTRG = 2,
};

