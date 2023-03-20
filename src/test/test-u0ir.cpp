#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(U0irTest, U0ir) {
    uint8_t *pU8 = (uint8_t *)malloc(sizeof(io_t));
    io_t *pIo = (io_t *)pU8;
    memset(pU8, 0, sizeof(io_t));

    pIo->u0ir.bits.is_rx_itr_enabled = true;
    EXPECT_EQ(0b00000100, pU8[0x88 - IO_START_ADDR]);
    pIo->u0ir.bits.is_rx_itr_enabled = false;
    EXPECT_EQ(0b00000000, pU8[0x88 - IO_START_ADDR]);

    pIo->u0ir.bits.is_tx_itr_enabled = true;
    EXPECT_EQ(0b00001000, pU8[0x88 - IO_START_ADDR]);
    pIo->u0ir.bits.is_tx_itr_enabled = false;
    EXPECT_EQ(0b00000000, pU8[0x88 - IO_START_ADDR]);

    pIo->u0ir.bits.is_tx_itr_requested = true;
    EXPECT_EQ(0b10000000, pU8[0x88 - IO_START_ADDR]);
    pIo->u0ir.bits.is_tx_itr_requested = false;
    EXPECT_EQ(0b00000000, pU8[0x88 - IO_START_ADDR]);

    pIo->u0ir.bits.is_rx_itr_requested = true;
    EXPECT_EQ(0b01000000, pU8[0x88 - IO_START_ADDR]);
    pIo->u0ir.bits.is_rx_itr_requested = false;
    EXPECT_EQ(0b00000000, pU8[0x88 - IO_START_ADDR]);

    pIo->u0ir.set(u0ir_t().with_rx_itr_enabled(false).with_tx_itr_enabled(true));
    EXPECT_EQ(0b00001000, pU8[0x88 - IO_START_ADDR]);

    pIo->u0ir.set(u0ir_t().with_rx_itr_enabled(true).with_tx_itr_enabled(false));
    EXPECT_EQ(0b00000100, pU8[0x88 - IO_START_ADDR]);

    free(pU8);
}
