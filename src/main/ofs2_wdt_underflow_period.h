#pragma once

#include <cstdint>

/// @file
/// @brief OFS2レジスタの
enum class OFS2_WDT_UNDERFLOW_PERIOD : uint8_t {
  L03FF = 0,
  L0FFF = 1,
  L1FFF = 2,
  L3FFF = 3,
};

