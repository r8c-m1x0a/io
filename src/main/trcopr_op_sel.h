#pragma once

#include <cstdint>

/// @file
/// @brief TRCOPRレジスタのOP_SEL。
enum class TRCOPR_OP_SEL : uint8_t {
  B1 = 0,
  INT1 = 1,
  BOTH0 = 2,
  BOTH1 = 3,
};

