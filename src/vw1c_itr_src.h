#pragma once

#include <cstdint>

/// @file
/// @brief VW1Cレジスタの割込ソース。
enum class VW1C_ITR_SRC : uint8_t {
  VCC_GE_VDET1 = 0,
  VCC_LE_VDET1 = 1,
};

