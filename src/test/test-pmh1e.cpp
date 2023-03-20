#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(Pmh1eTest, Pmh1e) {
    uint8_t *pU8 = (uint8_t *)malloc(sizeof(io_t));
    io_t *pIo = (io_t *)pU8;
    memset(pU8, 0, sizeof(io_t));

    pIo->pmh1e.set(pmh1e_t().with_b4_trciob(true).with_b5_vcout1(false));
    EXPECT_EQ(0b00000001, pU8[0xD1 - IO_START_ADDR]);

    pIo->pmh1e.set(pmh1e_t().with_b4_trciob(false).with_b5_vcout1(true));
    EXPECT_EQ(0b00000100, pU8[0xD1 - IO_START_ADDR]);
    free(pU8);
}
