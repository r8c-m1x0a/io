#pragma once

#include <cstdint>

/// @file
/// @brief PM1レジスタのB4選択。
enum class PM1_B4_FUNC : uint8_t {
  IO_AN4_TRCIOB = 0,
  TXD0 = 1,
  RXD0 = 2,
  INT0 = 3,
};

