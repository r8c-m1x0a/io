#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(CkstprTest, Ckstpr) {
    uint8_t *pU8 = (uint8_t *)malloc(sizeof(io_t));
    io_t *pIo = (io_t *)pU8;
    memset(pU8, 0, sizeof(io_t));
    pIo->ckstpr.bits.base_clk = CKSTPR_SCKSEL::HIGH_SPEED;
    EXPECT_EQ(0b10000000, pU8[0x24 - IO_START_ADDR]);
    pIo->ckstpr.bits.base_clk = CKSTPR_SCKSEL::LOW_SPEED;
    EXPECT_EQ(0b00000000, pU8[0x24 - IO_START_ADDR]);

    free(pU8);
}
