#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(U0c0Test, U0c0) {
    uint8_t *pU8 = (uint8_t *)malloc(sizeof(IO_t));
    IO_t *pIo = (IO_t *)pU8;
    memset(pU8, 0, sizeof(IO_t));

    pIo->u0c0.set(u0c0_t(0).with_clk_div(U0C0_CLK::DIV1));
    EXPECT_EQ(0b00000000, pU8[0x84 - IO_START_ADR]);
    pIo->u0c0.bits.clk_div = U0C0_CLK::DIV32;
    EXPECT_EQ(0b00000010, pU8[0x84 - IO_START_ADR]);

    free(pU8);
}
