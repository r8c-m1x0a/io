#pragma once

#include <cstdint>

/// @file
/// @brief U0MRレジスタのsmd定義。
/// @author S.Hanai ruimo.uno@gmail.com
/// @date 2023/3/22
enum class U0MR_SMD : uint8_t {
  DISABLED = 0,
  SYNC = 1,
  BIT_LEN7 = 4,
  BIT_LEN8 = 5,
  BIT_LEN9 = 6
};
