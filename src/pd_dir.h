#pragma once

#include <cstdint>

/// @file
/// @brief PDレジスタの入出力定義。
enum class PD_DIR : uint8_t {
  IN = 0,
  OUT = 1,
};

