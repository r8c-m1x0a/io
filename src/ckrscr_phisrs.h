#pragma once

#include <cstdint>

/// @file
/// @brief CKRSCRレジスタのクロック設定。
enum class CKRSCR_PHISRS : uint8_t {
  USE_PHISSEL = 0,
  NO_DIV = 1,
};

