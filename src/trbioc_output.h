#pragma once

#include <cstdint>

/// @file
/// @brief TRBIOCレジスタのoutput。
enum class TRBIOC_OUTPUT : uint8_t {
  WAVEFORM = 0,
  FIXED_VALUE = 1,
};

