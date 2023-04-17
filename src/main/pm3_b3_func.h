#pragma once

#include <cstdint>

/// @file
/// @brief PM3レジスタのb3機能。
enum class PM3_B3_FUNC : uint8_t {
  IO_OR_IVCMP3 = 0,
  TRCCLK = 1,
  INT3 = 2,
};
