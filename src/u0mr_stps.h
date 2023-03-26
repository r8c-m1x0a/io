#pragma once

#include <cstdint>

/// @file
/// @brief U0MRレジスタのストップビット定義。
enum class U0MR_STPS : uint8_t {
  /// @brief 1ストップビット。
  STOP_BIT_1 = 0,
  /// @brief  2ストップビット。
  STOP_BIT_2 = 1
};
