#pragma once

#include <cstdint>

/// @file
/// @brief CKSTPRレジスタのクロック選択。
enum class CKSTPR_SCKSEL : uint8_t {
  LOW_SPEED = 0,
  HIGH_SPEED = 1
};

