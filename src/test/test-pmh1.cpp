#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(Pmh1Test, Pmh1) {
    uint8_t *pU8 = (uint8_t *)malloc(sizeof(io_t));
    io_t *pIo = (io_t *)pU8;
    memset(pU8, 0, sizeof(io_t));

    pIo->pm1.set(pm1_t().with_b4_func(PM1_B4_FUNC::IO_AN4_TRCIOB).with_b5_func(PM1_B5_FUNC::RXD0).with_b6_func(PM1_B6_FUNC::TRJO).with_b7_func(PM1_B7_FUNC::TRCCLK));
    EXPECT_EQ(0b11100100, pU8[0xC9 - IO_START_ADDR]);

    pIo->pm1.set(pm1_t().with_b4_func(PM1_B4_FUNC::INT0).with_b5_func(PM1_B5_FUNC::TRJIO).with_b6_func(PM1_B6_FUNC::CLK0).with_b7_func(PM1_B7_FUNC::IO_AN7_IVCMP1));
    EXPECT_EQ(0b00011011, pU8[0xC9 - IO_START_ADDR]);

    pIo->pm1.set(pm1_t().with_b4_func(PM1_B4_FUNC::IO_AN4_TRCIOB).with_b5_func(PM1_B5_FUNC::IO_VCOUT1).with_b6_func(PM1_B6_FUNC::IO_IVREF1).with_b7_func(PM1_B7_FUNC::IO_AN7_IVCMP1));
    EXPECT_EQ(0b00000000, pU8[0xC9 - IO_START_ADDR]);

    free(pU8);
}
