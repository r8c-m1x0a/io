#pragma once

#include <cstdint>

/// @file
/// @brief CKRSCRレジスタのクロック選択。
enum class CKRSCR_RS : uint8_t {
  USE_SYSTEM_CLK = 0,
  USE_HSCK = 1,
};

