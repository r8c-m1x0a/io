#pragma once

#include <cstdint>

/// @file
/// @brief PRCRレジスタのunlock register設定。
enum class PRCR_UNLOCK_REG : uint8_t {
  LOCKED = 0,
  UNLOCKED = 1
};
