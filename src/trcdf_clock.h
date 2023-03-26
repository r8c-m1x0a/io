#pragma once

#include <stdint>

/// @file
/// @brief TRCDFレジスタのCLOCK。
enum class TRCDF_CLOCK : uint8_t {
  F32 = 0,
  F8 = 1,
  F1 = 2,
  COUNT = 3,
};

