#pragma once

#include <cstdint>

/// @file
/// @brief VCACレジスタのエッジ設定。
enum class VCAC_EDGE : uint8_t {
  ONE_WAY_EDGE = 0,
  TWO_WAY_EDGE = 1,
};

