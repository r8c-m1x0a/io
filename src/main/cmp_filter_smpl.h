#pragma once

#include <cstdint>

/// @file
/// @brief CMPレジスタの
enum class CMP_FILTER_SMPL : uint8_t {
  NO_FILTER = 0,
  F1 = 1,
  F8 = 2,
  F32 = 3,
};

