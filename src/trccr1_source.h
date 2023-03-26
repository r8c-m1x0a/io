#pragma once

#include <cstdint>

/// @file
/// @brief TRCCR1レジスタのsource。
enum class TRCCR1_SOURCE : uint8_t {
  F1 = 0,
  F2 = 1,
  F4 = 2,
  F32 = 4,
  F8 = 3,
  FALLING_EDGE_TRCCLK = 5,
  HFOCO = 6,
};

