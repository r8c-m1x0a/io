#pragma once

#include <cstdint>

/// @file
/// @brief VW1Cレジスタの検出状況。
enum class VW1C_V_CHG_DETECT : uint8_t {
  NOT_DETECTED = 0,
  DETECTED_VDET1 = 1,
};

