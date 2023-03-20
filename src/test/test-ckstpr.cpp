#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(CkstprTest, Ckstpr) {
    uint8_t *pU8 = (uint8_t *)malloc(sizeof(IO_t));
    IO_t *pIo = (IO_t *)pU8;
    memset(pU8, 0, sizeof(IO_t));
    pIo->ckstpr.bits.base_clk = CKSTPR_SCKSEL::HIGH_SPEED;
    EXPECT_EQ(0b10000000, pU8[0x24 - IO_START_ADR]);
    pIo->ckstpr.bits.base_clk = CKSTPR_SCKSEL::LOW_SPEED;
    EXPECT_EQ(0b00000000, pU8[0x24 - IO_START_ADR]);

    free(pU8);
}
