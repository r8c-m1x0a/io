#pragma once

#include <cstdint>

/// @file
/// @brief TRCIOR1レジスタのTRCGRC_CTRL
enum class TRCIOR1_TRCGRC_CTRL : uint8_t {
  OUT_COMP_TRCIOA_DISABLED = 0,
  OUT_COMP_TRCIOA_LOW_LEVEL = 1,
  OUT_COMP_TRCIOA_HIGH_LEVEL = 2,
  OUT_COMP_TRCIOA_TOGGLE = 3,
  OUT_COMP_TRCIOC_DISABLED = 8, 
  OUT_COMP_TRCIOC_LOW_LEVEL = 9, 
  OUT_COMP_TRCIOC_HIGH_LEVEL = 10, 
  OUT_COMP_TRCIOC_TOGGLE = 11, 
  IN_CAPT_TRCIOC_RISING_EDGE = 12,
  IN_CAPT_TRCIOC_FALING_EDGE = 13,
  IN_CAPT_TRCIOC_BOTH_EDGE = 14,
};
