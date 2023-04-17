#pragma once

#include <cstdint>

/// @file
/// @brief EXCKCRレジスタのピン選択。
enum class EXCKCR_CKPT : uint8_t {
  P4_6_IO_P4_7_IO = 0,
  P4_6_XIN_P4_7_IO = 1,
  P4_6_IO_P4_7_SCO = 2,
  P4_6_XIN_P4_7_XOUT = 3,
};

