#pragma once

#include <cstdint>

/// @file
/// @brief SCKCRレジスタのCPUクロック分周設定。
enum class SCKCR_PHISSEL : uint8_t {
  /// @brief 分周なし。
  DIV_1 = 0,
  /// @brief 2分周。
  DIV_2 = 1,
  /// @brief 4分周。
  DIV_4 = 2,
  /// @brief 8分周。
  DIV_8 = 3,
  /// @brief 16分周。
  DIV_16 = 4,
  /// @brief 32分周。
  DIV_32 = 5,
};
