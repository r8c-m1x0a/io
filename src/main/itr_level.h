#pragma once

#include <cstdint>

/// @brief ITRレジスタの割込レベル設定。
enum class ITR_LEVEL : uint8_t {
  DISABLED = 0,
  LEVEL_1 = 1,
  LEVEL_2 = 2,
};

