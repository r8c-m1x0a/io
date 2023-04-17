#pragma once

#include <cstdint>

/// @file
/// @brief TRBIOCレジスタのedge。
enum class TRBIOC_EDGE : uint8_t {
  FALLING = 0,
  RISING = 1,
};

