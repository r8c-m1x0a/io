#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(U0mrTest, U0mr) {
    uint8_t *pU8 = (uint8_t *)malloc(sizeof(IO_t));
    IO_t *pIo = (IO_t *)pU8;
    memset(pU8, 0, sizeof(IO_t));
    pIo->u0mr.set(u0mr_t().with_smd(U0MR_SMD::DISABLED).with_stps(U0MR_STPS::STOP_BIT_1));
    EXPECT_EQ(0b00000000, pU8[0x80 - IO_START_ADR]);

    pIo->u0mr.set(u0mr_t().with_smd(U0MR_SMD::BIT_LEN8).with_stps(U0MR_STPS::STOP_BIT_2));
    EXPECT_EQ(0b00010101, pU8[0x80 - IO_START_ADR]);

    free(pU8);
}
