#pragma once

#include <cstdint>

/// @file
/// @brief ADINSELレジスタのAD選択。
enum class ADINSEL_ADGSEL : uint8_t {
  AN0_1 = 0,
  AN2_3 = 1,
  AN4_7 = 2,
};

