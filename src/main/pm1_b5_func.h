#pragma once

#include <cstdint>

/// @file
/// @brief PM1レジスタのB5選択。
enum class PM1_B5_FUNC : uint8_t {
  IO_VCOUT1 = 0,
  RXD0 = 1,
  TRJIO = 2,
  INT1 = 3,
};

