#pragma once

#include <cstdint>

/// @file
/// @brief VW1Cレジスタの電圧状況。
enum class VW1C_VDET1 : uint8_t {
  VCC_LT_VDET1 = 0,
  VCC_GE_VDET1 = 1,
};

