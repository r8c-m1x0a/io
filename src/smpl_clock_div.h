#pragma once

#include <cstdint>

/// @file
/// @brief 分周比設定。
enum class SMPL_CLOCK_DIV : uint8_t {
  DIV_1 = 0,
  DIV_2 = 1,
  DIV_4 = 2,
  DIV_8 = 3,
};
