#pragma once

#include <cstdint>

/// @brief VD1LSレジスタの検出電圧設定。
enum class VD1LS_DETECT_LEVEL : uint8_t {
  V_2_35 = 0,
  V_2_65 = 1,
  V_2_95 = 2,
  V_3_25 = 3,
  V_3_55 = 4,
  V_3_85 = 5,
  V_4_15 = 6,
  V_4_45 = 7,
};

