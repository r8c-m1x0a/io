#pragma once

#include <cstdint>

/// @file
/// @brief TRJMRレジスタのsource。
enum class TRJMR_SOURCE : uint8_t {
  F1 = 0,
  F8 = 1,
  FHOCO = 2,
  H2 = 3,
};
