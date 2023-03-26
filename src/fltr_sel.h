#pragma once

#include <cstdint>

/// @file
/// @brief FLTRレジスタの設定。
enum class FLTR_SEL : uint8_t {
  NO_FILTER = 0,
  F1 = 1,
  F8 = 2,
  F32 = 3,
};

