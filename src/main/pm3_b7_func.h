#pragma once

#include <cstdint>

/// @file
/// @brief PM3レジスタのb7機能。
enum class PM3_B7_FUNC : uint8_t {
  IO = 0,
  ADTRG = 1,
  TRJO = 2,
  TRCIOD = 3,
};

