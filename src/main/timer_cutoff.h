#pragma once

#include <cstdint>

/// @file
/// @brief TIMERレジスタのcutoff。
enum class TIMER_CUTOFF : uint8_t {
  SUPPLIED = 0,
  CUT_OFF = 1,
};

