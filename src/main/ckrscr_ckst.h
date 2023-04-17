#pragma once

#include <cstdint>

/// @file
/// @brief CKRSCRレジスタのWait設定。
enum class CKRSCR_CKST : uint8_t {
  WAIT_4 = 0,
  WAIT_16 = 1,
  WAIT_32 = 2,
  WAIT_64 = 3,
  WAIT_128 = 4,
  WAIT_256 = 5,
  WAIT_512 = 6,
  WAIT_1024 = 7,
  WAIT_2048 = 8,
  WAIT_4096 = 9,
  WAIT_8192 = 10,
  WAIT_16384 = 11,
  WAIT_32768 = 12,
  WAIT_65536 = 13,
  WAIT_131072 = 14,
  WAIT_262144 = 15,
};

