#pragma once

#include <cstdint>

/// @file
/// @brief エッジ指定。
enum class CMP_ITR_EDGE: uint8_t {
  LOWER = 0,
  HIGHER = 1,
  BOTH = 2,
};
