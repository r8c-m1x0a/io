#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(SckcrTest, Sckcr) {
    uint8_t *pU8 = (uint8_t *)malloc(sizeof(io_t));
    io_t *pIo = (io_t *)pU8;
    memset(pU8, 0, sizeof(io_t));
    pIo->sckcr.set(sckcr_t().with_cpu_clk_div(SCKCR_PHISSEL::DIV_32).with_wait_mode(false).with_clk_src(SCKCR_HSCKSEL::ON_CHIP_CLK_SRC));
    EXPECT_EQ(0b01000101, pU8[0x22 - IO_START_ADDR]);

    pIo->sckcr.set(sckcr_t().with_cpu_clk_div(SCKCR_PHISSEL::DIV_1).with_wait_mode(true).with_clk_src(SCKCR_HSCKSEL::EXT_CLK_SRC));
    EXPECT_EQ(0b00100000, pU8[0x22 - IO_START_ADDR]);

    free(pU8);
}
