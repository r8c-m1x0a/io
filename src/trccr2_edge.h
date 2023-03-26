#pragma once
#include "trccr2_edge.h"

/// @file
/// @brief TRCCR2レジスタのEDGE。
enum class TRCCR2_EDGE : uint8_t {
  DISABLED = 0,
  RISING = 1,
  FALLING = 2,
  BOTH = 3,
};

