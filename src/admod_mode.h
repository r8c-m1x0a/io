#pragma once

#include <cstdint>

/// @brief ADMODレジスタのモード設定。
enum class ADMOD_MODE : uint8_t {
  ONE_SHOT = 0,
  REPEAT = 1,
  SINGLE_SWEEP = 2,
  REPEAT_SWEEP = 3,
};

