#pragma once

#include <cstdint>

/// @file
/// @brief TRCMRレジスタのmode2。
enum class TRCMR_MODE2 : uint8_t {
  PWM2 = 0,
  TIMER_OR_PWM = 1,
};

