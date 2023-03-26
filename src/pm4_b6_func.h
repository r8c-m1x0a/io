#pragma once

#include <cstdint>

/// @file
/// @brief PM4レジスタのb6機能。
enum class PM4_B6_FUNC : uint8_t {
  IO_OR_XIN_VCOUT1 = 0,
  RXD0_OR_TRJIO = 1,
  TXD0 = 2,
  INT1 = 3,
};
