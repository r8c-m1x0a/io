#pragma once

#include <cstdint>

/// @file
/// @brief U0C0レジスタのclk定義。
enum class U0C0_CLK : uint8_t {
  /// @brief 分周なし。
  DIV1 = 0,
  /// @brief 1/8分周。
  DIV8 = 1,
  /// @brief  1/32分周。
  DIV32 = 2
};
