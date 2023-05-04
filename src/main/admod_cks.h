#pragma once

#include <cstdint>

/// @file
/// @brief ADMODレジスタのクロック設定。
enum class ADMOD_CKS : uint8_t {
  F8 = 0,
  F4 = 1,
  F2 = 2,
  F1 = 3,
  Fad = 4,
};

