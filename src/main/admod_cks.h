#pragma once

#include <cstdint>

/// @file
/// @brief ADMODレジスタのクロック設定。
enum class ADMOD_CKS : uint8_t {
  F_8 = 0,
  F_4 = 1,
  F_2 = 2,
  F_1 = 3,
  F_AD = 4,
};

