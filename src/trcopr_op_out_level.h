#pragma once

#include <cstdint>

/// @file
/// @brief TRCOPRレジスタの
enum class TRCOPR_OP_OUT_LEVEL : uint8_t {
  HI_IMP_WHEN_PULL_DOWN,
  HI_IMP_WHEN_PULL_UP,
  LOW_WHILE_OUT_PERIOD,
  HI_WHILE_OUT_PERIOD,
};

