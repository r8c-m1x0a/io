#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(MstcrTest, Mstcr) {
    mstcr_t mstcr(0x5A);
    EXPECT_EQ(0x5A, mstcr.as_uint8);

    mstcr.as_uint8 = 0;
    mstcr.activating_timer_rj2(false);
    EXPECT_EQ(0b00000001, mstcr.as_uint8);
    mstcr.activating_timer_rj2(true);
    EXPECT_EQ(0b00000000, mstcr.as_uint8);

    mstcr.set(mstcr_t(0).activating_timer_rj2(false));
    EXPECT_EQ(0b00000001, mstcr.as_uint8);
    mstcr.set(mstcr_t().clone().activating_timer_rj2(true));
    EXPECT_EQ(0b00000000, mstcr.as_uint8);

    mstcr.as_uint8 = 0;
    mstcr.activating_timer_rb2(false);
    EXPECT_EQ(0b00000010, mstcr.as_uint8);
    mstcr.activating_timer_rb2(true);
    EXPECT_EQ(0b00000000, mstcr.as_uint8);

    mstcr.set(mstcr_t(0).activating_timer_rb2(false));
    EXPECT_EQ(0b00000010, mstcr.as_uint8);
    mstcr.set(mstcr_t().clone().activating_timer_rb2(true));
    EXPECT_EQ(0b00000000, mstcr.as_uint8);

    mstcr.as_uint8 = 0;
    mstcr.activating_ad(false);
    EXPECT_EQ(0b00010000, mstcr.as_uint8);
    mstcr.activating_ad(true);
    EXPECT_EQ(0b00000000, mstcr.as_uint8);

    mstcr.set(mstcr_t(0).activating_ad(false));
    EXPECT_EQ(0b00010000, mstcr.as_uint8);
    mstcr.set(mstcr_t().clone().activating_ad(true));
    EXPECT_EQ(0b00000000, mstcr.as_uint8);

    mstcr.as_uint8 = 0;
    mstcr.activating_timer_rc(false);
    EXPECT_EQ(0b00100000, mstcr.as_uint8);
    mstcr.activating_timer_rc(true);
    EXPECT_EQ(0b00000000, mstcr.as_uint8);

    mstcr.set(mstcr_t(0).activating_timer_rc(false));
    EXPECT_EQ(0b00100000, mstcr.as_uint8);
    mstcr.set(mstcr_t().clone().activating_timer_rc(true));
    EXPECT_EQ(0b00000000, mstcr.as_uint8);

    mstcr.as_uint8 = 0;
    mstcr.activating_uart(false);
    EXPECT_EQ(0b01000000, mstcr.as_uint8);
    mstcr.activating_uart(true);
    EXPECT_EQ(0b00000000, mstcr.as_uint8);

    mstcr.set(mstcr_t(0).activating_uart(false));
    EXPECT_EQ(0b01000000, mstcr.as_uint8);
    mstcr.set(mstcr_t().clone().activating_uart(true));
    EXPECT_EQ(0b00000000, mstcr.as_uint8);

    uint8_t *pU8 = (uint8_t *)malloc(sizeof(io_t));
    io_t *pIo = (io_t *)pU8;
    memset(pU8, 0, sizeof(io_t));
    pIo->mstcr.bits.is_uart_standby = true;
    EXPECT_EQ(0b01000000, pU8[0x12 - IO_START_ADDR]);
    free(pU8);
}
