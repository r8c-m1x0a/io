#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(U0c1Test, U0c1) {
    uint8_t *pU8 = (uint8_t *)malloc(sizeof(IO_t));
    IO_t *pIo = (IO_t *)pU8;
    memset(pU8, 0, sizeof(IO_t));

    pIo->u0c1.set(u0c1_t().with_tx_enabled(false).with_rx_enabled(true));
    EXPECT_EQ(0b00000100, pU8[0x85 - IO_START_ADR]);
    pIo->u0c1.set(u0c1_t().with_tx_enabled(true).with_rx_enabled(false));
    EXPECT_EQ(0b00000001, pU8[0x85 - IO_START_ADR]);

    pIo->u0c1.bits.is_tx_buf_empty = false;
    EXPECT_EQ(false, pIo->u0c1.bits.is_tx_buf_empty);

    pIo->u0c1.bits.is_tx_buf_empty = true;
    EXPECT_EQ(true, pIo->u0c1.bits.is_tx_buf_empty);

    free(pU8);
}
