#pragma once

#include <cstdint>

/// @file
/// @brief TRCCR1レジスタのclear mode。
enum class TRCCR1_CLEAR_MODE : uint8_t {
  DISABLED = 0,
  CLEAR = 1,
};

