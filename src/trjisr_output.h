#pragma once

#include <cstdint>

/// @file
/// @brief TRJISRレジスタのoutput。
enum class TRJISR_OUTPUT : uint8_t {
  TRCIOD = 0,
  TRCIOC = 1,
  TRCIOB = 2,
  TRCIOA = 3,
};

