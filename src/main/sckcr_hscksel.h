#pragma once

#include <cstdint>

/// @file
/// @brief SCKCRレジスタのクロック選択。
enum class SCKCR_HSCKSEL : uint8_t {
  EXT_CLK_SRC = 0,
  ON_CHIP_CLK_SRC = 1
};

