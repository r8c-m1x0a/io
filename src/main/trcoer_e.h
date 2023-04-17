#pragma once

#include <cstdint>

/// @file
/// @brief TRCOERレジスタのe。
enum class TRCOER_E : uint8_t {
  ENABLED = 0,
  DISABLED_OR_HIGH_IMP = 1,
};

