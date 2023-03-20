#include "r8c-m1xa-io.h"

volatile io_t *pIo = reinterpret_cast<volatile io_t*>(IO_START_ADDR);
volatile ofs2_t *pOfs2 = reinterpret_cast<volatile ofs2_t*>(OFS2_ADDR);
volatile ofs_t *pOfs = reinterpret_cast<volatile ofs_t*>(OFS_ADDR);
