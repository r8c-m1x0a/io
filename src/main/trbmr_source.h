#pragma once

#include <cstdint>

/// @file
/// @brief TRBMRレジスタのsource。
enum class TRBMR_SOURCE : uint8_t {
  F1 = 0,
  F8 = 1,
  TIMER_RJ2_UNDERFLOW = 2,
  F2 = 3,
  F4 = 4,
  F32 = 5,
  F64 = 6,
  F128 = 7,
};

