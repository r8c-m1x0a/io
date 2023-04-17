#pragma once

#include <cstdint>

/// @file
/// @brief WCMPRレジスタの
enum class WCMPR_COND : uint8_t {
  CMP_LESS_THAN_REF_OR_DISABLED = 0,
  CMP_GREATER_THAN_REF = 1,
};

