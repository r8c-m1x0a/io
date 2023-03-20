#include <gtest/gtest.h>
#include "r8c-m1xa-io.h"

TEST(OcocrTest, Ococr) {
    uint8_t *pU8 = (uint8_t *)malloc(sizeof(IO_t));
    IO_t *pIo = (IO_t *)pU8;
    memset(pU8, 0, sizeof(IO_t));
    pIo->ococr.bits.is_hosc_enabled = true;
    EXPECT_EQ(0b00000001, pU8[0x21 - IO_START_ADR]);
    pIo->ococr.bits.is_hosc_enabled = false;
    EXPECT_EQ(0b00000000, pU8[0x21 - IO_START_ADR]);

    memset(pU8, 0, sizeof(IO_t));
    pIo->ococr.bits.is_losc_enabled = true;
    EXPECT_EQ(0b00000010, pU8[0x21 - IO_START_ADR]);
    pIo->ococr.bits.is_losc_enabled = false;
    EXPECT_EQ(0b00000000, pU8[0x21 - IO_START_ADR]);

    free(pU8);
}
