#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(Ilvl9Test, Ilvl9) {
    uint8_t *pU8 = (uint8_t *)malloc(sizeof(io_t));
    io_t *pIo = (io_t *)pU8;
    memset(pU8, 0, sizeof(io_t));
    pIo->ilvl9.set_uart_rx(ITR_LEVEL::LEVEL_1);
    EXPECT_EQ(0b00000001, pU8[0x49 - IO_START_ADDR]);

    pIo->ilvl9.set_uart_rx(ITR_LEVEL::LEVEL_2);
    EXPECT_EQ(0b00000010, pU8[0x49 - IO_START_ADDR]);

    free(pU8);
}
