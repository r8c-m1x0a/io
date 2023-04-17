#pragma once

#include <cstdint>

/// @file
/// @brief ISCR0レジスタのエッジ設定。
enum class ISCR0_EDGE : uint8_t {
  FALLING = 0,
  RISING = 1,
  NOT_SET = 2,
  BOTH = 3,
};

