#pragma once

#include <cstdint>

/// @file
/// @brief ADMODレジスタのトリガ設定。
enum class ADMOD_TRIGGER : uint8_t {
  TIMER_RC = 0,
  CV_TRIGGER_TIMER_RC = 2,
  ADTRG = 3,
};

