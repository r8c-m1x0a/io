#pragma once

#include <cstdint>
#include "r8c-m1xa-io.h"

/// @file

/// @brief クロック制御。
/// @tparam T クロックソース
template<class T>
class Clock {
public:
  Clock(T _prop) : prop(_prop) {}

  /// @brief 初期化を実行。
  /// @param pIo IOへのポインタ。
  void init(volatile io_t* pIo);

  /// @brief NOP命令何回実行で1msになるかを返します。
  /// @return NOP命令何回実行で1msになるか。
  uint32_t nops_per_ms();

  /// @brief ビジーウェイトする。
  /// @param ミリ秒。
  void busy_wait_ms(uint16_t ms) {
    uint32_t cnt = ms * nops_per_ms();
    while (0 < cnt) {
      asm("nop");
      --cnt;
    }
  }

private:
  T prop;
};

/// @brief 内部クロック20MHzの場合のパラメータ。
struct InternalClock20M {
  SCKCR_PHISSEL div;
};
