#pragma once

#include <cstdint>
#include "r8c-m1xa-io.h"

/// @file

static void busy_wait(uint32_t cnt) {
    while (0 < cnt) {
      asm("nop");
      --cnt;
    }
}

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
    busy_wait(ms * nops_per_ms());
  }

private:
  T prop;
};

/// @brief 内部クロック20MHzの場合のパラメータ。
struct InternalClock20M {
  SCKCR_PHISSEL div;
};

/// @brief クロックソースに内部OSCを使用して20MHzとする。
template<>
class Clock<InternalClock20M> {
public:
  Clock(InternalClock20M _prop): prop(_prop) {}
  Clock(): prop(InternalClock20M { SCKCR_PHISSEL::DIV_1 }) {}

  void init(volatile io_t* pIo) {
    // クロック関係レジスタ・プロテクト解除
    pIo->prcr.bits.p0_enabled = true;

    // 高速オンチップオシレーターへ切り替え(20MHz)
    pIo->ococr.bits.is_hosc_enabled = true;
    pIo->sckcr.set(pIo->sckcr.clone().with_clk_src(SCKCR_HSCKSEL::ON_CHIP_CLK_SRC).with_cpu_clk_div(this->prop.div));
    pIo->ckstpr.bits.base_clk = CKSTPR_SCKSEL::HIGH_SPEED;
  }

  uint32_t nops_per_ms() {
    uint16_t divider = (1 << uint8_t(this->prop.div));
    return 600 / divider;
  }

  void busy_wait_ms(uint16_t ms) {
    busy_wait(ms * nops_per_ms());
  }

private:
  InternalClock20M prop;
};
