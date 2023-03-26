#pragma once

#include <cstdint>

/// @file
/// @brief TRCMRレジスタのTRCGR。
enum class TRCMR_TRCGR : uint8_t {
  OUT_CMP_OR_IN_CAPT = 0,
  BUF_OR_TRCGR_BUF = 1,
};

