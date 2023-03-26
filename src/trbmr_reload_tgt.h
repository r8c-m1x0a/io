#pragma once

#include <cstdint>

/// @file
/// @brief TRBMRレジスタのreload target。
enum class TRBMR_RELOAD_TGT : uint8_t {
  REGISTER_AND_COUNTER = 0,
  REGISTER_ONLY = 1,
};

