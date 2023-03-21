#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(Ilvl8Test, Ilvl8) {
    uint8_t *pU8 = (uint8_t *)malloc(sizeof(io_t));
    io_t *pIo = (io_t *)pU8;
    memset(pU8, 0, sizeof(io_t));
    pIo->ilvl8.set_uart_tx(ITR_LEVEL::LEVEL_1);
    EXPECT_EQ(0b00010000, pU8[0x48 - IO_START_ADDR]);

    pIo->ilvl8.set_uart_tx(ITR_LEVEL::LEVEL_2);
    EXPECT_EQ(0b00100000, pU8[0x48 - IO_START_ADDR]);

    free(pU8);
}
