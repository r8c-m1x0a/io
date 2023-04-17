#pragma once

#include <cstdint>

/// @file
/// @brief U0MRレジスタのパリティ定義
enum class U0MR_PARITY : uint8_t {
  /// @brief 奇数パリティ
  ODD = 0,
  /// @brief 偶数パリティ
  EVEN = 1,
  /// @brief パリティ無し
  NO = 2,
};
