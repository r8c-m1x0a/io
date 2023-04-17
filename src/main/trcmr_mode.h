#pragma once

#include <cstdint>

/// @file
/// @brief TRCMRレジスタのmode。
enum class TRCMR_MODE : uint8_t {
  TIMER = 0,
  PWM = 1,
};

