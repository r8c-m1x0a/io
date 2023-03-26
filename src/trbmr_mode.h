#pragma once

#include <cstdint>

/// @file
/// @brief TRBMRレジスタのmode。
enum class TRBMR_MODE : uint8_t {
  TIMER = 0,
  WAVEFORM = 1,
  ONE_SHOT = 2,
  WAIT_ONE_SHOT = 3,
};

