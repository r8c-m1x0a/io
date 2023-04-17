#pragma once

#include <cstdint>

/// @brief WDTCレジスタの分周比設定。
enum class WDTC_DIV : uint8_t {
  DIV_2 = 0,
  DIV_16 = 1,
  DIV_128 = 2,
  DIV_LO_16 = 3,
};

