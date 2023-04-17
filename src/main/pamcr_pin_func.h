#pragma once

#include <cstdint>

/// @file
/// @brief PAMCRレジスタのピンアサイン定義。
enum class PAMCR_PIN_FUNC : uint8_t {
  AS_IO = 0,
  AS_RESET = 1,
};

