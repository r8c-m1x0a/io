#pragma once

#include <cstdint>

/// @file
/// @brief TRJMRレジスタのop mode。
enum class TRJMR_OP_MODE : uint8_t {
  TIMER = 0,
  PULSE_OUT = 1,
  EVENT_COUNTER = 2,
  MEASURE_PULSE_WIDTH = 3,
  MEASURE_PULSE_PERIOD = 4,
};

