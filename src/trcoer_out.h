#pragma once

#include <stdint>

/// @file
/// @brief TRCOERレジスタのout
enum class TRCOER_OUT : uint8_t {
  DO_NOT_CHANGE = 0,
  SET = 1,
};

