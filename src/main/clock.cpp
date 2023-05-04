#include<cstdint>

#include "r8c-m1xa-io.h"
#include "clock.h"

template<>
void Clock<InternalClock20M>::init(volatile io_t* pIo) {
  // クロック関係レジスタ・プロテクト解除
  pIo->prcr.bits.p0_enabled = true;

  // 高速オンチップオシレーターへ切り替え(20MHz)
  pIo->ococr.bits.is_hosc_enabled = true;
  pIo->sckcr.set(pIo->sckcr.clone().with_clk_src(SCKCR_HSCKSEL::ON_CHIP_CLK_SRC).with_cpu_clk_div(this->prop.div));
  pIo->ckstpr.bits.base_clk = CKSTPR_SCKSEL::HIGH_SPEED;
}

template<>
uint32_t Clock<InternalClock20M>::nops_per_ms() {
  uint16_t divider = (1 << uint8_t(this->prop.div));
  return 600 / divider;
}
