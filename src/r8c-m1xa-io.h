#pragma once

#include <cstdint>

#pragma pack(1)
enum class U0MR_SMD : unsigned {
  DISABLED = 0,
  SYNC = 1,
  BIT_LEN7 = 4,
  BIT_LEN8 = 5,
  BIT_LEN9 = 6
};

enum class U0MR_STPS : uint8_t {
  STOP_BIT_1 = 0,
  STOP_BIT_2 = 1
};

enum class U0MR_PARITY : uint8_t {
  ODD = 0,
  EVEN = 1,
  NO = 2,
};

typedef union u0mr_t {
  struct {
    unsigned int smd:3;
    bool use_ext_clk:1;
    unsigned int stps:1;
    bool is_even_parity:1;
    bool is_parity_enabled:1;
    unsigned int reserved0:1;
  } bits;
  uint8_t as_uint8;

  u0mr_t(uint8_t u = 0) {
    this->as_uint8 = u;
  }

  u0mr_t clone() volatile {
    return u0mr_t(this->as_uint8);
  }

  u0mr_t& with_smd(U0MR_SMD smd) {
    this->bits.smd = (uint8_t)smd;
    return *this;
  }

  void set_smd(U0MR_SMD smd) volatile {
    this->bits.smd = (uint8_t)smd;
  }

  u0mr_t& with_external_clk(bool ext) {
    this->bits.use_ext_clk = ext;
    return *this;
  }

  u0mr_t& with_stps(U0MR_STPS stps) {
    this->bits.stps = (uint8_t)stps;
    return *this;
  }

  void set_stps(U0MR_STPS stps) volatile {
    this->bits.stps = (uint8_t)stps;
  }

  u0mr_t& with_parity(U0MR_PARITY p) {
    this->bits.is_even_parity = p == U0MR_PARITY::EVEN;
    this->bits.is_parity_enabled = p != U0MR_PARITY::NO;
    return *this;
  }

  void set(const u0mr_t& u) volatile {
    this->as_uint8 = u.as_uint8;
  }
} u0mr_t;

enum class U0C0_CLK : uint8_t {
  DIV1 = 0,
  DIV8 = 1,
  DIV32 = 2
};

typedef union u0c0_t {
  struct {
    unsigned int clk_div:2;
    unsigned int reserved0:1;
    bool is_tx_reg_empty:1;
    bool is_rx_filter_enabled:1;
    bool is_open_drain:1;
    bool is_tx_clk_rising:1;
    bool is_msb_first:1;
  } bits;
  uint8_t as_uint8;

  u0c0_t(uint8_t u = 0) {
    this->as_uint8 = u;
  }

  u0c0_t& with_clk_div(U0C0_CLK div) {
    this->bits.clk_div = (uint8_t)div;
    return *this;
  }

  void set_clk_div(U0C0_CLK div) volatile {
    this->bits.clk_div = (uint8_t)div;
  }

  u0c0_t& with_rx_filter(bool e) {
    this->bits.is_rx_filter_enabled = e;
    return *this;
  }

  u0c0_t& with_open_drain(bool e) {
    this->bits.is_open_drain = e;
    return *this;
  }

  u0c0_t& with_tx_clk_rising(bool e) {
    this->bits.is_tx_clk_rising = e;
    return *this;
  }

  u0c0_t& with_msb_first(bool e) {
    this->bits.is_msb_first = e;
    return *this;
  }

  u0c0_t clone() volatile {
    return u0c0_t(this->as_uint8);
  }

  void set(const u0c0_t that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} u0c0_t;

typedef union u0c1_t {
  struct {
    bool is_tx_enabled:1;
    bool is_tx_buf_empty:1;
    bool is_rx_enabled:1;
    bool is_rx_completed:1;
    bool is_tx_completed:1;
    bool is_cont_rx_enabled:1;
    unsigned int reserved0:2;
  } bits;
  uint8_t as_uint8;

  u0c1_t(uint8_t u = 0) {
    this->as_uint8 = u;
  }

  u0c1_t clone() volatile {
    return u0c1_t(this->as_uint8);
  }

  u0c1_t& with_tx_enabled(bool e) {
    this->bits.is_tx_enabled = e;
    return *this;
  }

  u0c1_t& with_rx_enabled(bool e) {
    this->bits.is_rx_enabled = e;
    return *this;
  }

  u0c1_t& with_tx_completed(bool e) {
    this->bits.is_tx_completed = e;
    return *this;
  }

  u0c1_t& with_cont_rx_enabled(bool e) {
    this->bits.is_cont_rx_enabled = e;
    return *this;
  }

  void clr_err() volatile {
    this->bits.is_rx_enabled = false;
    this->bits.is_rx_enabled = true;
  }

  void set(const u0c1_t& u) volatile {
    this->as_uint8 = u.as_uint8;
  }
} u0c1_t;

typedef union u0ir_t {
  struct {
    unsigned int reserved0:2;
    bool is_rx_itr_enabled:1;
    bool is_tx_itr_enabled:1;
    unsigned int reserved1:2;
    bool is_rx_itr_requested:1;
    bool is_tx_itr_requested:1;
  } bits;
  uint8_t as_uint8;

  u0ir_t(uint8_t u = 0) {
    this->as_uint8 = u;
  }

  u0ir_t clone() volatile {
    return u0ir_t(this->as_uint8);
  }

  u0ir_t& with_rx_itr_enabled(bool enabled) {
    this->bits.is_rx_itr_enabled= enabled;
    return *this;
  }

  u0ir_t& with_tx_itr_enabled(bool enabled) {
    this->bits.is_tx_itr_enabled = enabled;
    return *this;
  }

  u0ir_t& with_rx_itr_requested(bool enabled) {
    this->bits.is_rx_itr_requested = enabled;
    return *this;
  }

  u0ir_t& with_tx_itr_requested(bool enabled) {
    this->bits.is_tx_itr_requested = enabled;
    return *this;
  }

  void set(const u0ir_t& u) volatile {
    this->as_uint8 = u.as_uint8;
  }
} u0ir_t;

enum class PRCR_UNLOCK_REG : uint8_t {
  LOCKED = 0,
  UNLOCKED = 1
};

typedef union prcr_t {
  struct {
    bool p0_enabled:1;
    bool p1_enabled:1;
    unsigned int reserved0:1;
    bool p3_enabled:1;
    bool p4_enabled:1;
    unsigned int reserved1:3;
  } bits;
  uint8_t as_uint8;

  prcr_t(uint8_t u = 0): as_uint8(u) {}

  prcr_t clone() volatile {
    return prcr_t(this->as_uint8);
  }

  prcr_t& with_p0_enabled(bool e) {
    this->bits.p0_enabled = e;
    return *this;
  }

  prcr_t& with_p1_enabled(bool e) {
    this->bits.p1_enabled = e;
    return *this;
  }

  prcr_t& with_p3_enabled(bool e) {
    this->bits.p3_enabled = e;
    return *this;
  }

  prcr_t& with_p4_enabled(bool e) {
    this->bits.p4_enabled = e;
    return *this;
  }

  void set(const prcr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} prcr_t;

typedef union u0rb_t {
  struct {
    unsigned int data:7;
    unsigned int reserved:5;
    bool is_ovr_err:1;
    bool is_frm_err:1;
    bool is_prity_err:1;
    bool is_sum_err:1;
  } b7;

  struct {
    unsigned int data:8;
    unsigned int reserved:4;
    bool is_ovr_err:1;
    bool is_frm_err:1;
    bool is_prity_err:1;
    bool is_sum_err:1;
  } b8;

  struct {
    unsigned int data:9;
    unsigned int reserved:3;
    bool is_ovr_err:1;
    bool is_frm_err:1;
    bool is_prity_err:1;
    bool is_sum_err:1;
  } b9;

  uint16_t as_uint16;

  u0rb_t(uint16_t u16 = 0) {
    this->as_uint16 = u16;
  }
  
  u0rb_t clone() volatile {
    return u0rb_t(this->as_uint16);
  }

  uint8_t recv_b7() volatile {
    return this->b7.data;
  }

  uint8_t recv_b8() volatile {
    return this->b8.data;
  }

  uint16_t recv_b9() volatile {
    return this->b9.data;
  }
} u0rb_t;

typedef union ococr_t {
  struct {
    bool is_hosc_enabled:1;
    bool is_losc_enabled:1;
    unsigned int reserved:6;
  } bits;
  uint8_t as_uint8;

  ococr_t(uint8_t u): as_uint8(u) {}

  ococr_t clone() volatile {
    return ococr_t(this->as_uint8);
  }

  ococr_t& with_hs_osc(bool enabled) {
    this->bits.is_hosc_enabled = enabled;
    return *this;
  }

  ococr_t& with_ls_osc(bool enabled) {
    this->bits.is_losc_enabled = enabled;
    return *this;
  }

  void set(const ococr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} ococr_t;

enum class SCKCR_PHISSEL : uint8_t {
  DIV_1 = 0,
  DIV_2 = 1,
  DIV_4 = 2,
  DIV_8 = 3,
  DIV_16 = 4,
  DIV_32 = 5,
};

enum class SCKCR_HSCKSEL : uint8_t {
  EXT_CLK_SRC = 0,
  ON_CHIP_CLK_SRC = 1
};

typedef union sckcr_t {
  struct {
    unsigned int phissel:3;
    unsigned int reserved0:2;
    bool is_wait_mode_entered:1;
    unsigned int hscksel:1;
    unsigned int reserved1:1;
  } bits;
  uint8_t as_uint8;

  sckcr_t(uint8_t u = 0): as_uint8(0) {}

  sckcr_t clone() volatile {
    return sckcr_t(this->as_uint8);
  }

  sckcr_t& with_cpu_clk_div(SCKCR_PHISSEL sel) {
    this->bits.phissel = (uint8_t)sel;
    return *this;
  }

  void set_cpu_clk_div(SCKCR_PHISSEL sel) volatile {
    this->bits.phissel = (uint8_t)sel;
  }

  sckcr_t& with_wait_mode(bool enabled) {
    this->bits.is_wait_mode_entered = enabled;
    return *this;
  }

  sckcr_t& with_clk_src(SCKCR_HSCKSEL sel) {
    this->bits.hscksel = (uint8_t)sel;
    return *this;
  }

  void set_clk_src(SCKCR_HSCKSEL sel) volatile {
    this->bits.hscksel = (uint8_t)sel;
  }

  void set(const sckcr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} sckcr_t;

enum class CKSTPR_SCKSEL : uint8_t {
  LOW_SPEED = 0,
  HIGH_SPEED = 1
};

typedef union ckstpr_t {
  struct {
    bool is_all_clk_stopped:1;
    bool is_sys_clk_stopped:1;
    bool is_prescaler_stopped:1;
    unsigned int reserved:4;
    unsigned int base_clk:1;
  } bits;
  uint8_t as_uint8;

  ckstpr_t(uint8_t u = 0): as_uint8(u) {}

  ckstpr_t clone() volatile {
    return ckstpr_t(this->as_uint8);
  }

  ckstpr_t& with_all_clk_stopped(bool s) {
    this->bits.is_all_clk_stopped = s;
    return *this;
  }

  ckstpr_t& with_sys_clk_stopped(bool s) {
    this->bits.is_sys_clk_stopped = s;
    return *this;
  }

  ckstpr_t& with_prescaler_stopped(bool s) {
    this->bits.is_prescaler_stopped = s;
    return *this;
  }

  ckstpr_t& with_base_clk(CKSTPR_SCKSEL clk) {
    this->bits.base_clk = (uint8_t)clk;
    return *this;
  }

  void set_base_clk(CKSTPR_SCKSEL clk) volatile {
    this->bits.base_clk = (uint8_t)clk;
  }

  void set(const ckstpr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} ckstpr_t;

enum class PM1_B4_FUNC : uint8_t {
  IO_AN4_TRCIOB = 0,
  TXD0 = 1,
  RXD0 = 2,
  INT0 = 3,
};

enum class PM1_B5_FUNC : uint8_t {
  IO_VCOUT1 = 0,
  RXD0 = 1,
  TRJIO = 2,
  INT1 = 3,
};

typedef struct pmh1e_t {
  union {
    struct {
      bool is_b4_trciob:1;
      unsigned int reserved0:1;
      bool is_b5_vcout1:1;
      unsigned int reserved1:5;
    } bits;
    uint8_t as_uint8;
  };

  pmh1e_t(uint8_t u = 0): as_uint8(u) {}

  pmh1e_t clone() volatile {
    return pmh1e_t(this->as_uint8);
  }

  pmh1e_t& with_b4_trciob(bool b) {
    this->bits.is_b4_trciob = b;
    return *this;
  }

  pmh1e_t& with_b5_vcout1(bool b) {
    this->bits.is_b5_vcout1 = b;
    return *this;
  }

  void set(const pmh1e_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pmh1e_t;

typedef union mstcr_t {
  struct {
    bool is_tmr_rj2_standby:1;
    bool is_tmr_rb2_standby:1;
    unsigned int reserved0:2;
    bool is_ad_standby:1;
    bool is_tmr_rc_standby:1;
    bool is_uart_standby:1;
    unsigned int reserved1:1;
  } bits;
  uint8_t as_uint8;
  
  mstcr_t(uint8_t u = 0): as_uint8(u) {}

  mstcr_t clone() volatile {
    return mstcr_t(this->as_uint8);
  }

  mstcr_t& activating_timer_rj2(bool is_active) {
    this->bits.is_tmr_rj2_standby = is_active ? 0 : 1;
    return *this;
  }

  mstcr_t& activating_timer_rb2(bool is_active) {
    this->bits.is_tmr_rb2_standby = is_active ? 0 : 1;
    return *this;
  }

  mstcr_t& activating_ad(bool is_active) {
    this->bits.is_ad_standby = is_active ? 0 : 1;
    return *this;
  }

  mstcr_t& activating_timer_rc(bool is_active) {
    this->bits.is_tmr_rc_standby = is_active ? 0 : 1;
    return *this;
  }

  mstcr_t& activating_uart(bool is_active) {
    this->bits.is_uart_standby = is_active ? 0 : 1;
    return *this;
  }

  void set(const mstcr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} mstcr_t;

enum class EXCKCR_CKPT : uint8_t {
  P4_6_IO_P4_7_IO = 0,
  P4_6_XIN_P4_7_IO = 1,
  P4_6_IO_P4_7_SCO = 2,
  P4_6_XIN_P4_7_XOUT = 3,
};

typedef union exckcr_t {
  struct {
    unsigned int ckpt: 2;
    unsigned int reserved0: 4;
    bool is_fdbk_reg_disabled: 1;
    unsigned int reserved1: 1;
  } bits;
  uint8_t as_uint8;

  exckcr_t(uint8_t u = 0): as_uint8(u) {}
  
  exckcr_t clone() volatile {
    return exckcr_t(this->as_uint8);
  }

  exckcr_t& with_pin_assign(EXCKCR_CKPT assign) {
    this->bits.ckpt = (uint8_t)assign;
    return *this;
  }

  void set_pin_assign(EXCKCR_CKPT assign) volatile {
    this->bits.ckpt = (uint8_t)assign;
  }

  exckcr_t& with_onchip_fbreg_disabled(bool disabled) {
    this->bits.is_fdbk_reg_disabled = disabled;
    return *this;
  }

  void set(const exckcr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} exckcr_t;

enum class CKRSCR_CKST : uint8_t {
  WAIT_4 = 0,
  WAIT_16 = 1,
  WAIT_32 = 2,
  WAIT_64 = 3,
  WAIT_128 = 4,
  WAIT_256 = 5,
  WAIT_512 = 6,
  WAIT_1024 = 7,
  WAIT_2048 = 8,
  WAIT_4096 = 9,
  WAIT_8192 = 10,
  WAIT_16384 = 11,
  WAIT_32768 = 12,
  WAIT_65536 = 13,
  WAIT_131072 = 14,
  WAIT_262144 = 15,
};

enum class CKRSCR_PHISRS : uint8_t {
  USE_PHISSEL = 0,
  NO_DIV = 1,
};

enum class CKRSCR_RS : uint8_t {
  USE_SYSTEM_CLK = 0,
  USE_HSCK = 1,
};

typedef union ckrscr_t {
  struct {
    unsigned int ckst: 4;
    unsigned int reserved0: 1;
    unsigned int phisrs: 1;
    unsigned int waitrs: 1;
    unsigned int stoprs: 1;
  } bits;
  uint8_t as_uint8;

  ckrscr_t(uint8_t u = 0): as_uint8(u) {}

  ckrscr_t clone() volatile {
    return ckrscr_t(this->as_uint8);
  }

  ckrscr_t& with_ckst(CKRSCR_CKST ckst) {
    this->bits.ckst = (uint8_t)ckst;
    return *this;
  }

  void set_ckst(CKRSCR_CKST ckst) volatile {
    this->bits.ckst = (uint8_t)ckst;
  }

  ckrscr_t& with_phisrs(CKRSCR_PHISRS phisrs) {
    this->bits.phisrs = (uint8_t)phisrs;
    return *this;
  }

  void set_phisrs(CKRSCR_PHISRS phisrs) volatile {
    this->bits.phisrs = (uint8_t)phisrs;
  }

  ckrscr_t& with_waitrs(CKRSCR_RS rs) {
    this->bits.waitrs = (uint8_t)rs;
    return *this;
  }

  void set_waitrs(CKRSCR_RS rs) volatile {
    this->bits.waitrs = (uint8_t)rs;
  }

  ckrscr_t& with_stoprs(CKRSCR_RS rs) {
    this->bits.stoprs = (uint8_t)rs;
    return *this;
  }

  void set_stoprs(CKRSCR_RS rs) volatile {
    this->bits.stoprs = (uint8_t)rs;
  }

  void set(const ckrscr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} ckrscr_t;

typedef union bakcr_t {
  struct {
    bool is_osc_stop_dtct_enabled:1;
    bool is_osc_stop_dtct_itr_enabled:1;
    bool is_xin_halsted:1;
    bool is_osc_stop_dtct_itr_requested:1;
    unsigned int reserved0:4;
  } bits;
  uint8_t as_uint8;

  bakcr_t(uint8_t u = 0): as_uint8(u) {}

  bakcr_t clone() {
    return bakcr_t(this->as_uint8);
  }

  bakcr_t& with_osc_stop_dtct(bool enabled) {
    this->bits.is_osc_stop_dtct_enabled = enabled;
    return *this;
  }

  bakcr_t& with_osc_stop_dtct_itr(bool enabled) {
    this->bits.is_osc_stop_dtct_itr_enabled = enabled;
    return *this;
  }

  bakcr_t& with_osc_stop_dtct_itr_req(bool set) {
    this->bits.is_osc_stop_dtct_itr_requested = set;
    return *this;
  }

  void set(const bakcr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} bakcr_t;

enum class WDTC_DIV : uint8_t {
  DIV_2 = 0,
  DIV_16 = 1,
  DIV_128 = 2,
  DIV_LO_16 = 3,
};

typedef struct wdtc_t {
  unsigned int reserved0:6;
  unsigned int div:2;

  void set(WDTC_DIV div) volatile {
    this->div = (uint8_t)div;
  }
} wdtc_t;

enum class FLTR_SEL : uint8_t {
  NO_FILTER = 0,
  F1 = 1,
  F8 = 2,
  F32 = 3,
};

typedef union intf0_t {
  struct {
    unsigned int int0f:2;
    unsigned int int1f:2;
    unsigned int int2f:2;
    unsigned int int3f:2;
  } bits;
  uint8_t as_uint8;

  intf0_t(uint8_t u = 0): as_uint8(u) {}

  intf0_t clone() volatile {
    return intf0_t(this->as_uint8);
  }

  intf0_t& with_int0(FLTR_SEL sel) {
    this->bits.int0f = (uint8_t)sel;
    return *this;
  }

  void set_int0(FLTR_SEL sel) volatile {
    this->bits.int0f = (uint8_t)sel;
  }

  intf0_t& with_int1(FLTR_SEL sel) {
    this->bits.int1f = (uint8_t)sel;
    return *this;
  }

  void set_int1(FLTR_SEL sel) volatile {
    this->bits.int1f = (uint8_t)sel;
  }

  intf0_t& with_int2(FLTR_SEL sel) {
    this->bits.int2f = (uint8_t)sel;
    return *this;
  }

  void with_int2(FLTR_SEL sel) volatile {
    this->bits.int2f = (uint8_t)sel;
  }

  intf0_t& with_int3(FLTR_SEL sel) {
    this->bits.int3f = (uint8_t)sel;
    return *this;
  }

  void set_int3(FLTR_SEL sel) volatile {
    this->bits.int3f = (uint8_t)sel;
  }

  void set(const intf0_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} intf0_t;

enum class ISCR0_EDGE : uint8_t {
  FALLING = 0,
  RISING = 1,
  NOT_SET = 2,
  BOTH = 3,
};

typedef union iscr0_t {
  struct {
    unsigned int int0s:2;
    unsigned int int1s:2;
    unsigned int int2s:2;
    unsigned int int3s:2;
  } bits;
  uint8_t as_uint8;

  iscr0_t(uint8_t u = 0): as_uint8(u) {}

  iscr0_t clone() volatile {
    return iscr0_t(this->as_uint8);
  }

  iscr0_t& with_int0(ISCR0_EDGE edge) {
    this->bits.int0s = (uint8_t)edge;
    return *this;
  }

  void set_int0(ISCR0_EDGE edge) volatile {
    this->bits.int0s = (uint8_t)edge;
  }

  iscr0_t& with_int1(ISCR0_EDGE edge) {
    this->bits.int1s = (uint8_t)edge;
    return *this;
  }

  void set_int1(ISCR0_EDGE edge) volatile {
    this->bits.int1s = (uint8_t)edge;
  }

  iscr0_t& with_int2(ISCR0_EDGE edge) {
    this->bits.int2s = (uint8_t)edge;
    return *this;
  }

  void set_int2(ISCR0_EDGE edge) volatile {
    this->bits.int2s = (uint8_t)edge;
  }

  iscr0_t& with_int3(ISCR0_EDGE edge) {
    this->bits.int3s = (uint8_t)edge;
    return *this;
  }

  void set_int3(ISCR0_EDGE edge) volatile {
    this->bits.int3s = (uint8_t)edge;
  }

  void set(const iscr0_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} iscr0_t;

enum class KIEN_EDGE : uint8_t {
  FALING = 0,
  RIGINS = 1,
};

typedef union kien_t {
  struct {
    bool is_ki0_enabled:1;
    unsigned int ki0_edge:1;
    bool is_ki1_enabled:1;
    unsigned int ki1_edge:1;
    bool is_ki2_enabled:1;
    unsigned int ki2_edge:1;
    bool is_ki3_enabled:1;
    unsigned int ki3_edge:1;
  } bits;
  uint8_t as_uint8;

  kien_t(uint8_t u = 0): as_uint8(u) {}

  kien_t clone() volatile {
    return kien_t(this->as_uint8);
  }

  kien_t& with_ki0_enabled(bool enabled) {
    this->bits.is_ki0_enabled = enabled ? 1 : 0;
    return *this;
  }

  kien_t& with_ki0_edge(KIEN_EDGE edge) {
    this->bits.ki0_edge = (uint8_t)edge;
    return *this;
  }

  void set_ki0_edge(KIEN_EDGE edge) volatile {
    this->bits.ki0_edge = (uint8_t)edge;
  }

  kien_t& with_ki1_enabled(bool enabled) {
    this->bits.is_ki1_enabled = enabled ? 1 : 0;
    return *this;
  }

  kien_t& with_ki1_edge(KIEN_EDGE edge) {
    this->bits.ki1_edge = (uint8_t)edge;
    return *this;
  }

  void set_ki1_edge(KIEN_EDGE edge) volatile {
    this->bits.ki1_edge = (uint8_t)edge;
  }

  kien_t& with_ki2_enabled(bool enabled) {
    this->bits.is_ki2_enabled = enabled ? 1 : 0;
    return *this;
  }

  kien_t& with_ki2_edge(KIEN_EDGE edge) {
    this->bits.ki2_edge = (uint8_t)edge;
    return *this;
  }

  void set_ki2_edge(KIEN_EDGE edge) volatile {
    this->bits.ki2_edge = (uint8_t)edge;
  }

  kien_t& with_ki3_enabled(bool enabled) {
    this->bits.is_ki3_enabled = enabled ? 1 : 0;
    return *this;
  }

  kien_t& with_ki3_edge(KIEN_EDGE edge) {
    this->bits.ki3_edge = (uint8_t)edge;
    return *this;
  }

  void set_ki3_edge(KIEN_EDGE edge) volatile {
    this->bits.ki3_edge = (uint8_t)edge;
  }

  void set(const kien_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} kien_t;

enum class ITR_LEVEL : uint8_t {
  DISABLED = 0,
  LEVEL_1 = 1,
  LEVEL_2 = 2,
};

typedef union ilvl0_t {
  struct {
    unsigned int reserved0:4;
    unsigned int flash_ready:2;
    unsigned int reserved1:2;
  } bits;
  uint8_t as_uint8_t;

  ilvl0_t(uint8_t u = 0): as_uint8_t(u) {}

  ilvl0_t clone() volatile {
    return ilvl0_t(this->as_uint8_t);
  }

  ilvl0_t& with_flash_ready(ITR_LEVEL lvl) {
    this->bits.flash_ready = (uint8_t)lvl;
    return *this;
  }

  void set_flash_ready(ITR_LEVEL lvl) volatile {
    this->bits.flash_ready = (uint8_t)lvl;
  }

  void set(const ilvl0_t& that) volatile {
    this->as_uint8_t = that.as_uint8_t;
  }
} ilvl0_t;

typedef union ilvl2_t {
  struct {
    unsigned int comp_b1:2;
    unsigned int reserved0:2;
    unsigned int comp_b3:2;
    unsigned int reserved1:2;
  } bits;
  uint8_t as_uint8_t;

  ilvl2_t(uint8_t u = 0): as_uint8_t(u) {}

  ilvl2_t clone() volatile {
    return ilvl2_t(this->as_uint8_t);
  }

  ilvl2_t& with_comp_b3(ITR_LEVEL lvl) {
    this->bits.comp_b3 = (uint8_t)lvl;
    return *this;
  }

  void set_comp_b3(ITR_LEVEL lvl) volatile {
    this->bits.comp_b3 = (uint8_t)lvl;
  }

  ilvl2_t& with_comp_b1(ITR_LEVEL lvl) {
    this->bits.comp_b1 = (uint8_t)lvl;
    return *this;
  }

  void set_comp_b1(ITR_LEVEL lvl) volatile {
    this->bits.comp_b1 = (uint8_t)lvl;
  }

  void set(const ilvl2_t& that) volatile {
    this->as_uint8_t = that.as_uint8_t;
  }
} ilvl2_t;

typedef union ilvl3_t {
  struct {
    unsigned int reserved0:4;
    unsigned int timer_rc:2;
    unsigned int reserved1:2;
  } bits;
  uint8_t as_uint8_t;

  ilvl3_t(uint8_t u = 0): as_uint8_t(u) {}

  ilvl3_t clone() volatile {
    return ilvl3_t(this->as_uint8_t);
  }

  ilvl3_t& with_time_rc(ITR_LEVEL lvl) {
    this->bits.timer_rc = (uint8_t)lvl;
    return *this;
  }

  void set_timer_rc(ITR_LEVEL lvl) volatile {
    this->bits.timer_rc = (uint8_t)lvl;
  }

  void set(const ilvl2_t& that) volatile {
    this->as_uint8_t = that.as_uint8_t;
  }
} ilvl3_t;

typedef union ilvl6_t {
  struct {
    unsigned int reserved0:4;
    unsigned int key_input:2;
    unsigned int reserved1:2;
  } bits;
  uint8_t as_uint8_t;

  ilvl6_t(uint8_t u = 0): as_uint8_t(u) {}

  ilvl6_t clone() volatile {
    return ilvl6_t(this->as_uint8_t);
  }

  ilvl6_t& with_key_input(ITR_LEVEL lvl) {
    this->bits.key_input = (uint8_t)lvl;
    return *this;
  }

  void set_key_input(ITR_LEVEL lvl) volatile {
    this->bits.key_input = (uint8_t)lvl;
  }

  void set(const ilvl6_t& that) volatile {
    this->as_uint8_t = that.as_uint8_t;
  }
} ilvl6_t;

typedef union ilvl7_t {
  struct {
    unsigned int adc:2;
    unsigned int reserved1:6;
  } bits;
  uint8_t as_uint8_t;

  ilvl7_t(uint8_t u = 0): as_uint8_t(u) {}

  ilvl7_t clone() volatile {
    return ilvl7_t(this->as_uint8_t);
  }

  ilvl7_t& with_adc(ITR_LEVEL lvl) {
    this->bits.adc = (uint8_t)lvl;
    return *this;
  }

  void set_adc(ITR_LEVEL lvl) volatile {
    this->bits.adc = (uint8_t)lvl;
  }

  void set(const ilvl7_t& that) volatile {
    this->as_uint8_t = that.as_uint8_t;
  }
} ilvl7_t;

typedef union ilvl8_t {
  struct {
    unsigned int reserved0:4;
    unsigned int uart_tx:2;
    unsigned int reserved1:2;
  } bits;
  uint8_t as_uint8_t;

  ilvl8_t(uint8_t u = 0): as_uint8_t(u) {}

  ilvl8_t clone() volatile {
    return ilvl8_t(this->as_uint8_t);
  }

  ilvl8_t& with_uart_tx(ITR_LEVEL lvl) {
    this->bits.uart_tx = (uint8_t)lvl;
    return *this;
  }

  void set_uart_tx(ITR_LEVEL lvl) volatile {
    this->bits.uart_tx = (uint8_t)lvl;
  }

  void set(const ilvl8_t& that) volatile {
    this->as_uint8_t = that.as_uint8_t;
  }
} ilvl8_t;

typedef union ilvl9_t {
  struct {
    unsigned int uart_rx:2;
    unsigned int reserved0:6;
  } bits;
  uint8_t as_uint8_t;

  ilvl9_t(uint8_t u = 0): as_uint8_t(u) {}

  ilvl9_t clone() volatile {
    return ilvl9_t(this->as_uint8_t);
  }

  ilvl9_t& with_uart_rx(ITR_LEVEL lvl) {
    this->bits.uart_rx = (uint8_t)lvl;
    return *this;
  }

  void set_uart_rx(ITR_LEVEL lvl) volatile {
    this->bits.uart_rx = (uint8_t)lvl;
  }

  void set(const ilvl9_t& that) volatile {
    this->as_uint8_t = that.as_uint8_t;
  }
} ilvl9_t;

typedef union ilvla_t {
  struct {
    unsigned int reserved0:4;
    unsigned int int2:2;
    unsigned int reserved1:2;
  } bits;
  uint8_t as_uint8_t;

  ilvla_t(uint8_t u = 0): as_uint8_t(u) {}

  ilvla_t clone() volatile {
    return ilvla_t(this->as_uint8_t);
  }

  ilvla_t& with_int2(ITR_LEVEL lvl) {
    this->bits.int2 = (uint8_t)lvl;
    return *this;
  }

  void set_int2(ITR_LEVEL lvl) volatile {
    this->bits.int2 = (uint8_t)lvl;
  }

  void set(const ilvla_t& that) volatile {
    this->as_uint8_t = that.as_uint8_t;
  }
} ilvla_t;

typedef union ilvlb_t {
  struct {
    unsigned int reserved0:2;
    unsigned int ped_timer:2;
    unsigned int reserved1:2;
    unsigned int timer_rj2:2;
  } bits;
  uint8_t as_uint8_t;

  ilvlb_t(uint8_t u = 0): as_uint8_t(u) {}

  ilvlb_t clone() volatile {
    return ilvlb_t(this->as_uint8_t);
  }

  ilvlb_t& with_ped_timer(ITR_LEVEL lvl) {
    this->bits.ped_timer = (uint8_t)lvl;
    return *this;
  }

  void set_ped_timer(ITR_LEVEL lvl) volatile {
    this->bits.ped_timer = (uint8_t)lvl;
  }

  ilvlb_t& with_timer_rj2(ITR_LEVEL lvl) {
    this->bits.timer_rj2 = (uint8_t)lvl;
    return *this;
  }

  void set_timer_rj2(ITR_LEVEL lvl) volatile {
    this->bits.timer_rj2 = (uint8_t)lvl;
  }

  void set(const ilvlb_t& that) volatile {
    this->as_uint8_t = that.as_uint8_t;
  }
} ilvlb_t;

typedef union ilvlc_t {
  struct {
    unsigned int reserved0:2;
    unsigned int int1:2;
    unsigned int reserved1:2;
    unsigned int timer_rb2:2;
  } bits;
  uint8_t as_uint8_t;

  ilvlc_t(uint8_t u = 0): as_uint8_t(u) {}

  ilvlc_t clone() volatile {
    return ilvlc_t(this->as_uint8_t);
  }

  ilvlc_t& with_int1(ITR_LEVEL lvl) {
    this->bits.int1 = (uint8_t)lvl;
    return *this;
  }

  void set_int1(ITR_LEVEL lvl) volatile {
    this->bits.int1 = (uint8_t)lvl;
  }

  ilvlc_t& with_timer_rb2(ITR_LEVEL lvl) {
    this->bits.timer_rb2 = (uint8_t)lvl;
    return *this;
  }

  void set_timer_rb2(ITR_LEVEL lvl) volatile {
    this->bits.timer_rb2 = (uint8_t)lvl;
  }

  void set(const ilvlc_t& that) volatile {
    this->as_uint8_t = that.as_uint8_t;
  }
} ilvlc_t;

typedef union ilvld_t {
  struct {
    unsigned int int3:2;
    unsigned int reserved0:6;
  } bits;
  uint8_t as_uint8_t;

  ilvld_t(uint8_t u = 0): as_uint8_t(u) {}

  ilvld_t clone() volatile {
    return ilvld_t(this->as_uint8_t);
  }

  ilvld_t& with_int3(ITR_LEVEL lvl) {
    this->bits.int3 = (uint8_t)lvl;
    return *this;
  }

  void set_int3(ITR_LEVEL lvl) volatile {
    this->bits.int3 = (uint8_t)lvl;
  }

  void set(const ilvld_t& that) volatile {
    this->as_uint8_t = that.as_uint8_t;
  }
} ilvld_t;

typedef union ilvle_t {
  struct {
    unsigned int reserved0:4;
    unsigned int int0:2;
    unsigned int reserved1:2;
  } bits;
  uint8_t as_uint8_t;

  ilvle_t(uint8_t u = 0): as_uint8_t(u) {}

  ilvle_t clone() volatile {
    return ilvle_t(this->as_uint8_t);
  }

  ilvle_t& with_int0(ITR_LEVEL lvl) {
    this->bits.int0 = (uint8_t)lvl;
    return *this;
  }

  void set_int0(ITR_LEVEL lvl) volatile {
    this->bits.int0 = (uint8_t)lvl;
  }

  void set(const ilvle_t& that) volatile {
    this->as_uint8_t = that.as_uint8_t;
  }
} ilvle_t;

enum class VCAC_EDGE : uint8_t {
  ONE_WAY_EDGE = 0,
  TWO_WAY_EDGE = 1,
};

typedef union vca2_t {
  struct {
    bool is_lo_power_wait_enabled:1;
    unsigned int reserved0:4;
    bool is_v_dtct0_enabled:1;
    bool is_v_dtct1_enabled:1;
    unsigned int reserved1:1;
  } bits;
  uint8_t as_uint8;

  vca2_t(uint8_t u = 0): as_uint8(u) {}

  vca2_t clone() volatile {
    return vca2_t(this->as_uint8);
  }

  vca2_t& with_lpe(bool enabled) {
    this->bits.is_lo_power_wait_enabled = enabled;
    return *this;
  }

  vca2_t& with_v_dtct0_enabled(bool enabled) {
    this->bits.is_v_dtct0_enabled = enabled;
    return *this;
  }

  vca2_t& with_v_dtct1_enabled(bool enabled) {
    this->bits.is_v_dtct1_enabled = enabled;
    return *this;
  }

  void set(const vca2_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} vca2_t;

enum class VD1LS_DETECT_LEVEL : uint8_t {
  V_2_35 = 0,
  V_2_65 = 1,
  V_2_95 = 2,
  V_3_25 = 3,
  V_3_55 = 4,
  V_3_85 = 5,
  V_4_15 = 6,
  V_4_45 = 7,
};

enum class SMPL_CLOCK_DIV : uint8_t {
  DIV_1 = 0,
  DIV_2 = 1,
  DIV_4 = 2,
  DIV_8 = 3,
};

typedef union vd1ls_t {
  struct {
    unsigned int reserved0:1;
    unsigned int dtct_lvl:3;
    unsigned int reserved1:4;
  } bits;
  uint8_t as_uint8;

  vd1ls_t(uint8_t u = 0): as_uint8(u) {}

  vd1ls_t clone() volatile {
    return vd1ls_t(this->as_uint8);
  }

  vd1ls_t& with_dtct_lvl(VD1LS_DETECT_LEVEL lvl) {
    this->bits.dtct_lvl = (uint8_t)lvl;
    return *this;
  }

  void set(const vd1ls_t that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} vd1ls_t;

typedef union vw0c_t {
  struct {
    bool is_v_mon_rst_enabled:1;
    bool is_v_filter_disabled:1;
    unsigned int reserved0:2;
    unsigned int vw0f:2;
    unsigned int reserved1:2;
  } bits;
  uint8_t as_uint8;

  vw0c_t(uint8_t u = 0): as_uint8(u) {}

  vw0c_t clone() volatile {
    return vw0c_t(this->as_uint8);
  }

  vw0c_t& with_reset_enabled(bool enabled) {
    this->bits.is_v_mon_rst_enabled = enabled;
    return *this;
  }

  vw0c_t& with_filter_disabled(bool disabled) {
    this->bits.is_v_filter_disabled = disabled;
    return *this;
  }

  vw0c_t& with_smpl_clk(SMPL_CLOCK_DIV div) {
    this->bits.vw0f = (uint8_t)div;
    return *this;
  }

  void set_smpl_clk(SMPL_CLOCK_DIV div) volatile {
    this->bits.vw0f = (uint8_t)div;
  }

  void set(const vw0c_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} vw0c_t;

enum class VW1C_V_CHG_DETECT : uint8_t {
  NOT_DETECTED = 0,
  DETECTED_VDET1 = 1,
};

enum class VW1C_VDET1 : uint8_t {
  VCC_LT_VDET1 = 0,
  VCC_GE_VDET1 = 1,
};

enum class VW1C_ITR_SRC {
  VCC_GE_VDET1 = 0,
  VCC_LE_VDET1 = 1,
};

typedef union vw1c_t {
  struct {
    bool is_v_mon_itr_enabled:1;
    bool is_v_mon_filter_disabled:1;
    unsigned int vw1c2:1;
    unsigned int vw1c3:1;
    unsigned int vw1f:2;
    unsigned int reserved0:1;
    unsigned int vw1c7:1;
  } bits;
  uint8_t as_uint8;

  vw1c_t(uint8_t u = 0): as_uint8(u) {}

  vw1c_t clone() volatile {
    return vw1c_t(this->as_uint8);
  }

  vw1c_t& with_itr_enabled(bool enabled) {
    this->bits.is_v_mon_itr_enabled = enabled;
    return *this;
  }

  vw1c_t& with_filter(bool disabled) {
    this->bits.is_v_mon_filter_disabled = disabled;
    return *this;
  }

  vw1c_t& with_chg_detected(VW1C_V_CHG_DETECT dtct) {
    this->bits.vw1c2 = (uint8_t)dtct;
    return *this;
  }

  void set_chg_detected(VW1C_V_CHG_DETECT dtct) volatile {
    this->bits.vw1c2 = (uint8_t)dtct;
  }

  vw1c_t& with_detect(VW1C_VDET1 v) {
    this->bits.vw1c3 = (uint8_t)v;
    return *this;
  }

  void set_detect(VW1C_VDET1 v) volatile {
    this->bits.vw1c3 = (uint8_t)v;
  }

  vw1c_t& with_smpl_clk(SMPL_CLOCK_DIV div) {
    this->bits.vw1f = (uint8_t)div;
    return *this;
  }

  void set_smpl_clk(SMPL_CLOCK_DIV div) volatile {
    this->bits.vw1f = (uint8_t)div;
  }

  vw1c_t& with_itr_src(VW1C_ITR_SRC src) {
    this->bits.vw1c7 = (uint8_t)src;
    return *this;
  }

  void set_itr_src(VW1C_ITR_SRC src) volatile {
    this->bits.vw1c7 = (uint8_t)src;
  }

  void set(const vw1c_t that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} vw1c_t;

enum class RSTFR_START_UP : uint8_t {
  COLD_START_UP = 0,
  WARM_START_UP = 1,
};

enum class ADMOD_CKS : uint8_t {
  F_8 = 0,
  F_4 = 1,
  F_2 = 2,
  F_1 = 3,
  F_AD = 4,
};

enum class ADMOD_MODE : uint8_t {
  ONE_SHOT = 0,
  REPEAT = 1,
  SINGLE_SWEEP = 2,
  REPEAT_SWEEP = 3,
};

enum class ADMOD_TRIGGER : uint8_t {
  TIMER_RC = 0,
  CV_TRIGGER_TIMER_RC = 2,
  ADTRG = 3,
};

typedef union admod_t {
  struct {
    unsigned int cks:3;
    unsigned int md:2;
    unsigned reserved0:1;
    unsigned int trigger:2;
  } bits;
  uint8_t as_uint8;

  admod_t(uint8_t u = 0): as_uint8(u) {}

  admod_t clone() volatile {
    return admod_t(this->as_uint8);
  }

  admod_t& with_cks(ADMOD_CKS clk) {
    this->bits.cks = (uint8_t)clk;
    return *this;
  }

  void set_cks(ADMOD_CKS clk) volatile {
    this->bits.cks = (uint8_t)clk;
  }

  admod_t& with_mode(ADMOD_MODE mode) {
    this->bits.md = (uint8_t)mode;
    return *this;
  }

  void set_mode(ADMOD_MODE mode) volatile {
    this->bits.md = (uint8_t)mode;
  }

  admod_t& with_trigger(ADMOD_TRIGGER trigger) {
    this->bits.trigger = (uint8_t)trigger;
    return *this;
  }

  void set_trigger(ADMOD_TRIGGER trigger) volatile {
    this->bits.trigger = (uint8_t)trigger;
  }

  void set(const admod_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }

} admod_t;

enum class ADINSEL_ADGSEL : uint8_t {
  AN0_1 = 0,
  AN2_3 = 1,
  AN4_7 = 2,
};

typedef union adinsel_t {
  struct {
    unsigned int ch0:1;
    unsigned int reserved0:5;
    unsigned int adgsel:2;
  } bits;
  uint8_t as_uint8;

  adinsel_t(uint8_t u = 0): as_uint8(u) {}

  adinsel_t clone() volatile {
    return adinsel_t(this->as_uint8);
  }

  adinsel_t& with_ch0(unsigned int ch0) {
    this->bits.ch0 = ch0;
    return *this;
  }

  adinsel_t& with_adgsel(ADINSEL_ADGSEL adgsel) {
    this->bits.adgsel = (uint8_t)adgsel;
    return *this;
  }

  void set_adgsel(ADINSEL_ADGSEL adgsel) volatile {
    this->bits.adgsel = (uint8_t)adgsel;
  }

  void set(const adinsel_t that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} adinsel_t;

typedef union adicsr_t {
  struct {
    unsigned int reserved0:6;
    bool is_itr_enabled:1;
    bool is_itr_requested:1;
  } bits;
  uint8_t as_uint8;

  adicsr_t(uint8_t u = 0): as_uint8(u) {}

  adicsr_t clone() volatile {
    return adicsr_t(this->as_uint8);
  }

  adicsr_t& with_itr_enabled(bool enabled) {
    this->bits.is_itr_enabled = enabled;
    return *this;
  }

  adicsr_t& with_itr_requested(bool requested) {
    this->bits.is_itr_requested = requested;
    return *this;
  }

  void set(const adicsr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} adicsr_t;

enum class PD_DIR : uint8_t {
  IN = 0,
  OUT = 1,
};

typedef union pd1_t {
  struct {
    unsigned int b0:1;
    unsigned int b1:1;
    unsigned int b2:1;
    unsigned int b3:1;
    unsigned int b4:1;
    unsigned int b5:1;
    unsigned int b6:1;
    unsigned int b7:1;
  } bits;
  uint8_t as_uint8;

  pd1_t(uint8_t u = 0): as_uint8(u) {}
  
  pd1_t clone() volatile {
    return pd1_t(this->as_uint8);
  }

  pd1_t& with_p1_0(PD_DIR dir) {
    this->bits.b0 = (uint8_t)dir;
    return *this;
  }

  void set_p1_0(PD_DIR dir) volatile {
    this->bits.b0 = (uint8_t)dir;
  }

  pd1_t& with_p1_1(PD_DIR dir) {
    this->bits.b1 = (uint8_t)dir;
    return *this;
  }

  void set_p1_1(PD_DIR dir) volatile {
    this->bits.b1 = (uint8_t)dir;
  }

  pd1_t& with_p1_2(PD_DIR dir) {
    this->bits.b2 = (uint8_t)dir;
    return *this;
  }

  void set_p1_2(PD_DIR dir) volatile {
    this->bits.b2 = (uint8_t)dir;
  }

  pd1_t& with_p1_3(PD_DIR dir) {
    this->bits.b3 = (uint8_t)dir;
    return *this;
  }

  void set_p1_3(PD_DIR dir) volatile {
    this->bits.b3 = (uint8_t)dir;
  }

  pd1_t& with_p1_4(PD_DIR dir) {
    this->bits.b4 = (uint8_t)dir;
    return *this;
  }

  void set_p1_4(PD_DIR dir) volatile {
    this->bits.b4 = (uint8_t)dir;
  }

  pd1_t& with_p1_5(PD_DIR dir) {
    this->bits.b5 = (uint8_t)dir;
    return *this;
  }

  void set_p1_5(PD_DIR dir) volatile {
    this->bits.b5 = (uint8_t)dir;
  }

  pd1_t& with_p1_6(PD_DIR dir) {
    this->bits.b6 = (uint8_t)dir;
    return *this;
  }

  void set_p1_6(PD_DIR dir) volatile {
    this->bits.b6 = (uint8_t)dir;
  }

  pd1_t& with_p1_7(PD_DIR dir) {
    this->bits.b7 = (uint8_t)dir;
    return *this;
  }

  void set_p1_7(PD_DIR dir) volatile {
    this->bits.b7 = (uint8_t)dir;
  }

  void set(const pd1_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pd1_t;

typedef union pd3_t {
  struct {
    unsigned int reserved0:3;
    unsigned int b3:1;
    unsigned int b4:1;
    unsigned int b5:1;
    unsigned int reserved1:1;
    unsigned int b7:1;
  } bits;
  uint8_t as_uint8;

  pd3_t(uint8_t u = 0): as_uint8(u) {}

  pd3_t clone() volatile {
    return pd3_t(this->as_uint8);
  }

  pd3_t& with_p3_3(PD_DIR dir) {
    this->bits.b3 = (uint8_t)dir;
    return *this;
  }

  void set_p3_3(PD_DIR dir) volatile {
    this->bits.b3 = (uint8_t)dir;
  }

  pd3_t& with_p3_4(PD_DIR dir) {
    this->bits.b4 = (uint8_t)dir;
    return *this;
  }

  void set_p3_4(PD_DIR dir) volatile {
    this->bits.b4 = (uint8_t)dir;
  }

  pd3_t& with_p3_5(PD_DIR dir) {
    this->bits.b5 = (uint8_t)dir;
    return *this;
  }

  void set_p3_5(PD_DIR dir) volatile {
    this->bits.b5 = (uint8_t)dir;
  }

  pd3_t& with_p3_7(PD_DIR dir) {
    this->bits.b7 = (uint8_t)dir;
    return *this;
  }

  void set_p3_7(PD_DIR dir) volatile {
    this->bits.b7 = (uint8_t)dir;
  }

  void set(const pd3_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pd3_t;

typedef union pd4_t {
  struct {
    unsigned int reserved0:2;
    unsigned int b2:1;
    unsigned int reserved1:2;
    unsigned int b5:1;
    unsigned int b6:1;
    unsigned int b7:1;
  } bits;
  uint8_t as_uint8;

  pd4_t(uint8_t u = 0): as_uint8(u) {}

  pd4_t clone() volatile {
    return pd4_t(this->as_uint8);
  }

  pd4_t& with_p4_2(PD_DIR dir) {
    this->bits.b2 = (uint8_t)dir;
    return *this;
  }

  void set_p4_2(PD_DIR dir) volatile {
    this->bits.b2 = (uint8_t)dir;
  }

  pd4_t& with_p4_5(PD_DIR dir) {
    this->bits.b5 = (uint8_t)dir;
    return *this;
  }

  void set_p4_5(PD_DIR dir) volatile {
    this->bits.b5 = (uint8_t)dir;
  }

  pd4_t& with_p4_6(PD_DIR dir) {
    this->bits.b6 = (uint8_t)dir;
    return *this;
  }

  void set_p4_6(PD_DIR dir) volatile {
    this->bits.b6 = (uint8_t)dir;
  }

  pd4_t& with_p4_7(PD_DIR dir) {
    this->bits.b7 = (uint8_t)dir;
    return *this;
  }

  void set_p4_7(PD_DIR dir) volatile {
    this->bits.b7 = (uint8_t)dir;
  }

  void set(const pd4_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pd4_t;

typedef union p1_t {
  struct {
    bool b0:1;
    bool b1:1;
    bool b2:1;
    bool b3:1;
    bool b4:1;
    bool b5:1;
    bool b6:1;
    bool b7:1;
  } bits;
  uint8_t as_uint8;

  p1_t(uint8_t u = 0): as_uint8(u) {}
  
  p1_t clone() volatile {
    return p1_t(this->as_uint8);
  }

  p1_t& with_b0(bool b) {
    this->bits.b0 = b;
    return *this;
  }

  p1_t& with_b1(bool b) {
    this->bits.b1 = b;
    return *this;
  }

  p1_t& with_b2(bool b) {
    this->bits.b2 = b;
    return *this;
  }

  p1_t& with_b3(bool b) {
    this->bits.b3 = b;
    return *this;
  }

  p1_t& with_b4(bool b) {
    this->bits.b4 = b;
    return *this;
  }

  p1_t& with_b5(bool b) {
    this->bits.b5 = b;
    return *this;
  }

  p1_t& with_b6(bool b) {
    this->bits.b6 = b;
    return *this;
  }

  p1_t& with_b7(bool b) {
    this->bits.b7 = b;
    return *this;
  }

  void set(const p1_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} p1_t;

typedef union p3_t {
  struct {
    unsigned int reserved0:3;
    bool b3:1;
    bool b4:1;
    bool b5:1;
    unsigned int reserved1:1;
    bool b7:1;
  } bits;
  uint8_t as_uint8;

  p3_t(uint8_t u = 0): as_uint8(u) {}
  
  p3_t clone() volatile {
    return p3_t(this->as_uint8);
  }

  p3_t& with_b3(bool b) {
    this->bits.b3 = b;
    return *this;
  }

  p3_t& with_b4(bool b) {
    this->bits.b4 = b;
    return *this;
  }

  p3_t& with_b5(bool b) {
    this->bits.b5 = b;
    return *this;
  }

  p3_t& with_b7(bool b) {
    this->bits.b7 = b;
    return *this;
  }

  void set(const p3_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} p3_t;

typedef union p4_t {
  struct {
    unsigned int reserved0:2;
    bool b2:1;
    unsigned int reserved1:2;
    bool b5:1;
    bool b6:1;
    bool b7:1;
  } bits;
  uint8_t as_uint8;

  p4_t(uint8_t u = 0): as_uint8(u) {}
  
  p4_t clone() volatile {
    return p4_t(this->as_uint8);
  }

  p4_t& with_b2(bool b) {
    this->bits.b2 = b;
    return *this;
  }

  p4_t& with_b5(bool b) {
    this->bits.b5 = b;
    return *this;
  }

  p4_t& with_b6(bool b) {
    this->bits.b6 = b;
    return *this;
  }

  p4_t& with_b7(bool b) {
    this->bits.b7 = b;
    return *this;
  }

  void set(const p4_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} p4_t;

typedef union pur1_t {
  struct {
    bool pull_up_b0:1;
    bool pull_up_b1:1;
    bool pull_up_b2:1;
    bool pull_up_b3:1;
    bool pull_up_b4:1;
    bool pull_up_b5:1;
    bool pull_up_b6:1;
    bool pull_up_b7:1;
  } bits;
  uint8_t as_uint8;

  pur1_t(uint8_t u = 0): as_uint8(u) {}
  
  pur1_t clone() volatile {
    return pur1_t(this->as_uint8);
  }

  pur1_t& with_pull_up_b0(bool b) {
    this->bits.pull_up_b0 = b;
    return *this;
  }

  pur1_t& with_pull_up_b1(bool b) {
    this->bits.pull_up_b1 = b;
    return *this;
  }

  pur1_t& with_pull_up_b2(bool b) {
    this->bits.pull_up_b2 = b;
    return *this;
  }

  pur1_t& with_pull_up_b3(bool b) {
    this->bits.pull_up_b3 = b;
    return *this;
  }

  pur1_t& with_pull_up_b4(bool b) {
    this->bits.pull_up_b4 = b;
    return *this;
  }

  pur1_t& with_pull_up_b5(bool b) {
    this->bits.pull_up_b5 = b;
    return *this;
  }

  pur1_t& with_pull_up_b6(bool b) {
    this->bits.pull_up_b6 = b;
    return *this;
  }

  pur1_t& with_pull_up_b7(bool b) {
    this->bits.pull_up_b7 = b;
    return *this;
  }

  void set(const pur1_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pur1_t;

typedef union pur3_t {
  struct {
    unsigned int reserved0:3;
    bool pull_up_b3:1;
    bool pull_up_b4:1;
    bool pull_up_b5:1;
    unsigned int reserved1:1;
    bool pull_up_b7:1;
  } bits;
  uint8_t as_uint8;

  pur3_t(uint8_t u = 0): as_uint8(u) {}
  
  pur3_t clone() volatile {
    return pur3_t(this->as_uint8);
  }

  pur3_t& with_pull_up_b3(bool b) {
    this->bits.pull_up_b3 = b;
    return *this;
  }

  pur3_t& with_pull_up_b4(bool b) {
    this->bits.pull_up_b4 = b;
    return *this;
  }

  pur3_t& with_pull_up_b5(bool b) {
    this->bits.pull_up_b5 = b;
    return *this;
  }

  pur3_t& with_pull_up_b7(bool b) {
    this->bits.pull_up_b7 = b;
    return *this;
  }

  void set(const pur3_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pur3_t;

typedef union pur4_t {
  struct {
    bool reserved0:2;
    bool pull_up_b2:1;
    unsigned int reserved1:2;
    bool pull_up_b5:1;
    bool pull_up_b6:1;
    bool pull_up_b7:1;
  } bits;
  uint8_t as_uint8;

  pur4_t(uint8_t u = 0): as_uint8(u) {}
  
  pur4_t clone() volatile {
    return pur4_t(this->as_uint8);
  }

  pur4_t& with_pull_up_b2(bool b) {
    this->bits.pull_up_b2 = b;
    return *this;
  }

  pur4_t& with_pull_up_b5(bool b) {
    this->bits.pull_up_b5 = b;
    return *this;
  }

  pur4_t& with_pull_up_b6(bool b) {
    this->bits.pull_up_b6 = b;
    return *this;
  }

  pur4_t& with_pull_up_b7(bool b) {
    this->bits.pull_up_b7 = b;
    return *this;
  }

  void set(const pur4_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pur4_t;

enum class PINSR_INPUT : uint8_t {
  TRJIO_PIN = 0,
  VCOUT1 = 1,
};

typedef union pinsr_t {
  struct {
    unsigned int reserved0:6;
    unsigned int trjiosel:1;
    bool read_level:1;
  } bits;
  uint8_t as_uint8;

  pinsr_t(uint8_t u = 0): as_uint8(u) {}

  pinsr_t clone() volatile {
    return pinsr_t(this->as_uint8);
  }

  pinsr_t& with_trjiosel(PINSR_INPUT in) {
    this->bits.trjiosel = (uint8_t)in;
    return *this;
  }

  void set_trjiosel(PINSR_INPUT in) volatile {
    this->bits.trjiosel = (uint8_t)in;
  }

  pinsr_t& with_read_level(bool enabled) {
    this->bits.read_level = enabled ? 1 : 0;
    return *this;
  }

  void set(const pinsr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pinsr_t;

enum class DRIVE_CAPACITY : uint8_t {
  LOW = 0,
  HIGH = 1,
};

typedef union drr1_t {
  struct {
    unsigned int reserved0:2;
    unsigned int p1_2:1;
    unsigned int p1_3:1;
    unsigned int p1_4:1;
    unsigned int p1_5:1;
    unsigned int reserved1:2;
  } bits;
  uint8_t as_uint8;

  drr1_t(uint8_t u = 0): as_uint8(u) {}

  drr1_t clone() volatile {
    return drr1_t(this->as_uint8);
  }

  drr1_t& with_p1_2(DRIVE_CAPACITY drv) {
    this->bits.p1_2 = (uint8_t)drv;
    return *this;
  }

  void set_p1_2(DRIVE_CAPACITY drv) volatile {
    this->bits.p1_2 = (uint8_t)drv;
  }

  drr1_t& with_p1_3(DRIVE_CAPACITY drv) {
    this->bits.p1_3 = (uint8_t)drv;
    return *this;
  }

  void set_p1_3(DRIVE_CAPACITY drv) volatile {
    this->bits.p1_3 = (uint8_t)drv;
  }

  drr1_t& with_p1_4(DRIVE_CAPACITY drv) {
    this->bits.p1_4 = (uint8_t)drv;
    return *this;
  }

  void set_p1_4(DRIVE_CAPACITY drv) volatile {
    this->bits.p1_4 = (uint8_t)drv;
  }

  drr1_t& with_p1_5(DRIVE_CAPACITY drv) {
    this->bits.p1_5 = (uint8_t)drv;
    return *this;
  }

  void set_p1_5(DRIVE_CAPACITY drv) volatile {
    this->bits.p1_5 = (uint8_t)drv;
  }

  void set(const drr1_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} drr1_t;

typedef union drr3_t {
  struct {
    unsigned int reserved0:3;
    unsigned int p3_3:1;
    unsigned int p3_4:1;
    unsigned int p3_5:1;
    unsigned int reserved1:1;
    unsigned int p3_7:1;
  } bits;
  uint8_t as_uint8;

  drr3_t(uint8_t u = 0): as_uint8(u) {}

  drr3_t clone() volatile {
    return drr3_t(this->as_uint8);
  }

  drr3_t& with_p3_3(DRIVE_CAPACITY drv) {
    this->bits.p3_3 = (uint8_t)drv;
    return *this;
  }

  void set_p3_3(DRIVE_CAPACITY drv) volatile {
    this->bits.p3_3 = (uint8_t)drv;
  }

  drr3_t& with_p3_4(DRIVE_CAPACITY drv) {
    this->bits.p3_4 = (uint8_t)drv;
    return *this;
  }

  void set_p3_4(DRIVE_CAPACITY drv) volatile {
    this->bits.p3_4 = (uint8_t)drv;
  }

  drr3_t& with_p3_5(DRIVE_CAPACITY drv) {
    this->bits.p3_5 = (uint8_t)drv;
    return *this;
  }

  void set_p3_5(DRIVE_CAPACITY drv) volatile {
    this->bits.p3_5 = (uint8_t)drv;
  }

  drr3_t& with_p3_7(DRIVE_CAPACITY drv) {
    this->bits.p3_7 = (uint8_t)drv;
    return *this;
  }

  void set_p3_7(DRIVE_CAPACITY drv) volatile {
    this->bits.p3_7 = (uint8_t)drv;
  }

  void set(const drr3_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} drr3_t;

typedef union pod1_t {
  struct {
    bool p1_0_od:1;
    bool p1_1_od:1;
    bool p1_2_od:1;
    bool p1_3_od:1;
    bool p1_4_od:1;
    bool p1_5_od:1;
    bool p1_6_od:1;
    bool p1_7_od:1;
  } bits;
  uint8_t as_uint8;

  pod1_t(uint8_t u = 0): as_uint8(u) {}

  pod1_t clone() volatile {
    return pod1_t(this->as_uint8);
  }

  pod1_t& with_p1b0_open_drain(bool od) {
    this->bits.p1_0_od = od;
    return *this;
  }

  pod1_t& with_p1b1_open_drain(bool od) {
    this->bits.p1_1_od = od;
    return *this;
  }

  pod1_t& with_p1b2_open_drain(bool od) {
    this->bits.p1_2_od = od;
    return *this;
  }

  pod1_t& with_p1b3_open_drain(bool od) {
    this->bits.p1_3_od = od;
    return *this;
  }

  pod1_t& with_p1b4_open_drain(bool od) {
    this->bits.p1_4_od = od;
    return *this;
  }

  pod1_t& with_p1b5_open_drain(bool od) {
    this->bits.p1_5_od = od;
    return *this;
  }

  pod1_t& with_p1b6_open_drain(bool od) {
    this->bits.p1_6_od = od;
    return *this;
  }

  pod1_t& with_p1b7_open_drain(bool od) {
    this->bits.p1_7_od = od;
    return *this;
  }

  void set(const pod1_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pod1_t;

typedef union pod3_t {
  struct {
    unsigned int reserved0:3;
    bool p3_3_od:1;
    bool p3_4_od:1;
    bool p3_5_od:1;
    unsigned int reserved1:1;
    bool p3_7_od:1;
  } bits;
  uint8_t as_uint8;

  pod3_t(uint8_t u = 0): as_uint8(u) {}

  pod3_t clone() volatile {
    return pod3_t(this->as_uint8);
  }

  pod3_t& with_p3b3_open_drain(bool od) {
    this->bits.p3_3_od = od;
    return *this;
  }

  pod3_t& with_p3b4_open_drain(bool od) {
    this->bits.p3_4_od = od;
    return *this;
  }

  pod3_t& with_p3b5_open_drain(bool od) {
    this->bits.p3_5_od = od;
    return *this;
  }

  pod3_t& with_p3b7_open_drain(bool od) {
    this->bits.p3_7_od = od;
    return *this;
  }

  void set(const pod3_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pod3_t;

typedef union pod4_t {
  struct {
    unsigned int reserved0:2;
    bool p4_2_od:1;
    unsigned int reserved1:2;
    bool p4_5_od:1;
    bool p4_6_od:1;
    bool p4_7_od:1;
  } bits;
  uint8_t as_uint8;

  pod4_t(uint8_t u = 0): as_uint8(u) {}

  pod4_t clone() volatile {
    return pod4_t(this->as_uint8);
  }

  pod4_t& with_p4b2_open_drain(bool od) {
    this->bits.p4_2_od = od;
    return *this;
  }

  pod4_t& with_p4b5_open_drain(bool od) {
    this->bits.p4_5_od = od;
    return *this;
  }

  pod4_t& with_p4b6_open_drain(bool od) {
    this->bits.p4_6_od = od;
    return *this;
  }

  pod4_t& with_p4b7_open_drain(bool od) {
    this->bits.p4_7_od = od;
    return *this;
  }

  void set(const pod4_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pod4_t;

enum class PAMCR_PIN_FUNC : uint8_t {
  AS_IO = 0,
  AS_RESET = 1,
};

typedef union pamcr_t {
  struct {
    bool pa_0_od:1;
    unsigned int reserved0:3;
    unsigned int pa0_func:1;
    unsigned int reserved1:3;
  } bits;
  uint8_t as_uint8;

  pamcr_t(uint8_t u = 0): as_uint8(u) {}

  pamcr_t clone() volatile {
    return pamcr_t(this->as_uint8);
  }

  pamcr_t& with_pab0_open_drain(bool od) {
    this->bits.pa_0_od = od;
    return *this;
  }

  pamcr_t& with_pa0_func(PAMCR_PIN_FUNC func) {
    this->bits.pa0_func = (uint8_t)func;
    return *this;
  }

  void set_pa0_func(PAMCR_PIN_FUNC func) volatile {
    this->bits.pa0_func = (uint8_t)func;
  }

  void set(const pamcr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pamcr_t;

enum class PM1_B0_FUNC : uint8_t {
  IO_OR_AD = 0,
  TRCIOD = 1,
  KI0 = 2,
};

enum class PM1_B1_FUNC : uint8_t {
  IO_OR_AD = 0,
  TRCIOA_TRCTRG = 1,
  KI1 = 2,
};

enum class PM1_B2_FUNC : uint8_t {
  IO_OR_AD = 0,
  TRCIOB = 1,
  KI2 = 2,
};

enum class PM1_B3_FUNC : uint8_t {
  IO_OR_AD = 0,
  TRCIOC = 1,
  KI3 = 2,
  TRBO = 3,
};

enum class PM1_B6_FUNC : uint8_t {
  IO_IVREF1 = 0,
  CLK0 = 1,
  TRJO = 2,
  TRCIOB = 3
};

enum class PM1_B7_FUNC : uint8_t {
  IO_AN7_IVCMP1 = 0,
  INT1 = 1,
  TRJIO = 2,
  TRCCLK = 3
};

typedef union pm1_t {
  struct {
    unsigned int b0_func:2;
    unsigned int b1_func:2;
    unsigned int b2_func:2;
    unsigned int b3_func:2;
    unsigned int b4_func:2;
    unsigned int b5_func:2;
    unsigned int b6_func:2;
    unsigned int b7_func:2;
  } bits;
  uint16_t as_uint16;

  pm1_t(uint16_t u = 0): as_uint16(u) {}

  pm1_t clone() volatile {
    return pm1_t(this->as_uint16);
  }

  pm1_t& with_b0_func(PM1_B0_FUNC func) {
    this->bits.b0_func = (uint8_t)func;
    return *this;
  }

  void set_b0_func(PM1_B0_FUNC func) volatile {
    this->bits.b0_func = (uint8_t)func;
  }

  pm1_t& with_b1_func(PM1_B1_FUNC func) {
    this->bits.b1_func = (uint8_t)func;
    return *this;
  }

  void set_b1_func(PM1_B1_FUNC func) volatile {
    this->bits.b1_func = (uint8_t)func;
  }

  pm1_t& with_b2_func(PM1_B2_FUNC func) {
    this->bits.b2_func = (uint8_t)func;
    return *this;
  }

  void set_b2_func(PM1_B2_FUNC func) volatile {
    this->bits.b2_func = (uint8_t)func;
  }

  pm1_t& with_b3_func(PM1_B3_FUNC func) {
    this->bits.b3_func = (uint8_t)func;
    return *this;
  }

  void set_b3_func(PM1_B3_FUNC func) volatile {
    this->bits.b3_func = (uint8_t)func;
  }

  pm1_t& with_b4_func(PM1_B4_FUNC func) {
    this->bits.b4_func = (uint8_t)func;
    return *this;
  }

  void set_b4_func(PM1_B4_FUNC func) volatile {
    this->bits.b4_func = (uint8_t)func;
  }

  pm1_t& with_b5_func(PM1_B5_FUNC func) {
    this->bits.b5_func = (uint8_t)func;
    return *this;
  }

  void set_b5_func(PM1_B5_FUNC func) volatile {
    this->bits.b5_func = (uint8_t)func;
  }

  pm1_t& with_b6_func(PM1_B6_FUNC func) {
    this->bits.b6_func = (uint8_t)func;
    return *this;
  }

  void set_b6_func(PM1_B6_FUNC func) volatile {
    this->bits.b6_func = (uint8_t)func;
  }

  pm1_t& with_b7_func(PM1_B7_FUNC func) {
    this->bits.b7_func = (uint8_t)func;
    return *this;
  }

  void set_b7_func(PM1_B7_FUNC func) volatile {
    this->bits.b7_func = (uint8_t)func;
  }

  void set(const pm1_t& that) volatile {
    this->as_uint16 = that.as_uint16;
  }
} pm1_t;

enum class PM3_B3_FUNC : uint8_t {
  IO_OR_IVCMP3 = 0,
  TRCCLK = 1,
  INT3 = 2,
};

enum class PM3_B4_FUNC : uint8_t {
  IO_OR_IVREF3 = 0,
  TRCIOC = 1,
  INT2 = 2,
};

enum class PM3_B5_FUNC : uint8_t {
  IO = 0,
  TRCIOD = 1,
  KI2 = 2,
  VCOUT3 = 3,
};

enum class PM3_B7_FUNC : uint8_t {
  IO = 0,
  ADTRG = 1,
  TRJO = 2,
  TRCIOD = 3,
};

typedef union pm3_t {
  struct {
    unsigned int reserved0:6;
    unsigned int b3_func:2;
    unsigned int b4_func:2;
    unsigned int b5_func:2;
    unsigned int reserved1:2;
    unsigned int b7_func:2;
  } bits;
  uint16_t as_uint16;

  pm3_t(uint16_t u = 0): as_uint16(u) {}

  pm3_t clone() volatile {
    return pm3_t(this->as_uint16);
  }

  pm3_t& with_b3_func(PM3_B3_FUNC func) {
    this->bits.b3_func = (uint8_t)func;
    return *this;
  }

  void set_b3_func(PM3_B3_FUNC func) volatile {
    this->bits.b3_func = (uint8_t)func;
  }

  pm3_t& with_b4_func(PM3_B4_FUNC func) {
    this->bits.b4_func = (uint8_t)func;
    return *this;
  }

  void set_b4_func(PM3_B4_FUNC func) volatile {
    this->bits.b4_func = (uint8_t)func;
  }

  pm3_t& with_b5_func(PM3_B5_FUNC func) {
    this->bits.b5_func = (uint8_t)func;
    return *this;
  }

  void set_b5_func(PM3_B5_FUNC func) volatile {
    this->bits.b5_func = (uint8_t)func;
  }

  pm3_t& with_b7_func(PM3_B7_FUNC func) {
    this->bits.b7_func = (uint8_t)func;
    return *this;
  }

  void set_b7_func(PM3_B7_FUNC func) volatile {
    this->bits.b7_func = (uint8_t)func;
  }

  void set(const pm3_t& that) volatile {
    this->as_uint16 = that.as_uint16;
  }
} pm3_t;

enum class PM4_B2_FUNC : uint8_t {
  IO = 0,
  TRBO = 1,
  TXD0 = 2,
  KI3 = 3,
};

enum class PM4_B5_FUNC : uint8_t {
  IO = 0,
  INT0 = 1,
  ADTRG = 2,
};

enum class PM4_B6_FUNC : uint8_t {
  IO_OR_XIN_VCOUT1 = 0,
  RXD0_OR_TRJIO = 1,
  TXD0 = 2,
  INT1 = 3,
};

enum class PM4_B7_FUNC : uint8_t {
  IO_OR_XOUT = 0,
  INT2 = 1,
};

typedef union pm4_t {
  struct {
    unsigned int reserved0:4;
    unsigned int b2_func:2;
    unsigned int reserved1:4;
    unsigned int b5_func:2;
    unsigned int b6_func:2;
    unsigned int b7_func:2;
  } bits;
  uint16_t as_uint16;

  pm4_t(uint16_t u = 0): as_uint16(u) {}

  pm4_t clone() volatile {
    return pm4_t(this->as_uint16);
  }

  pm4_t& with_b2_func(PM4_B2_FUNC func) {
    this->bits.b2_func = (uint8_t)func;
    return *this;
  }

  void set_b2_func(PM4_B2_FUNC func) volatile {
    this->bits.b2_func = (uint8_t)func;
  }

  pm4_t& with_b5_func(PM4_B5_FUNC func) {
    this->bits.b5_func = (uint8_t)func;
    return *this;
  }

  void set_b5_func(PM4_B5_FUNC func) volatile {
    this->bits.b5_func = (uint8_t)func;
  }

  pm4_t& with_b6_func(PM4_B6_FUNC func) {
    this->bits.b6_func = (uint8_t)func;
    return *this;
  }

  void set_b6_func(PM4_B6_FUNC func) volatile {
    this->bits.b6_func = (uint8_t)func;
  }

  pm4_t& with_b7_func(PM4_B7_FUNC func) {
    this->bits.b7_func = (uint8_t)func;
    return *this;
  }

  void set_b7_func(PM4_B7_FUNC func) volatile {
    this->bits.b7_func = (uint8_t)func;
  }

  void set(const pm4_t& that) volatile {
    this->as_uint16 = that.as_uint16;
  }
} pm4_t;

typedef struct pmh4e_t {
  union {
    struct {
      unsigned int reserved0:4;
      bool is_b6_vcout1_trjio:1;
      unsigned int reserved1:3;
    } bits;
    uint8_t as_uint8;
  };

  pmh4e_t(uint8_t u = 0): as_uint8(u) {}

  pmh4e_t clone() volatile {
    return pmh4e_t(this->as_uint8);
  }

  pmh4e_t& with_b6_vcout1_trjio(bool b) {
    this->bits.is_b6_vcout1_trjio = b;
    return *this;
  }

  void set(const pmh4e_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} pmh4e_t;

typedef union trjcr_t {
  struct {
    bool is_started:1;
    bool is_running:1;
    bool force_stop:1;
    unsigned int reserved0:1;
    bool is_edge_received:1;
    bool is_underflow:1;
    unsigned int reserved1:2;
  } bits;
  uint8_t as_uint8;

  trjcr_t(uint8_t u = 0): as_uint8(u) {}

  trjcr_t clone() volatile {
    return trjcr_t(this->as_uint8);
  }

  trjcr_t& with_started(bool started) {
    this->bits.is_started = started;
    return *this;
  }

  trjcr_t& with_force_stop(bool fs) {
    this->bits.force_stop = fs;
    return *this;
  }

  trjcr_t& with_edge_received(bool er) {
    this->bits.is_edge_received = er;
    return *this;
  }

  trjcr_t& with_underflow(bool underflow) {
    this->bits.is_underflow = underflow;
    return *this;
  }

  void set(const trjcr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trjcr_t;

enum class TRJIOC_CTRL : uint8_t {
  ALWAYS = 0,
  DURING_INT2_HIGH = 1,
  TMR_RC = 2,
};

typedef union trjioc_t {
  struct {
    unsigned int tedgsel:1;
    bool trjio_disabled:1;
    unsigned int reserved:2;
    unsigned int trjio_fltr_sample:2;
    unsigned int ctrl:2;
  } bits;
  uint8_t as_uint8;

  trjioc_t(uint8_t u = 0): as_uint8(u) {}

  trjioc_t clone() volatile {
    return trjioc_t(this->as_uint8);
  }

  trjioc_t& with_tedgsel(uint8_t u) {
    this->bits.tedgsel = u;
    return *this;
  }

  trjioc_t& with_trjio_disabled(bool disabled) {
    this->bits.trjio_disabled = disabled;
    return *this;
  }

  trjioc_t& with_flter_sample(FLTR_SEL sel) {
    this->bits.trjio_fltr_sample = (uint8_t)sel;
    return *this;
  }

  void set_flter_sample(FLTR_SEL sel) volatile {
    this->bits.trjio_fltr_sample = (uint8_t)sel;
  }

  trjioc_t& with_ctrl(TRJIOC_CTRL ctrl) {
    this->bits.ctrl = (uint8_t)ctrl;
    return *this;
  }

  void set_ctrl(TRJIOC_CTRL ctrl) volatile {
    this->bits.ctrl = (uint8_t)ctrl;
  }

  void set(const trjioc_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trjioc_t;

enum class TRJMR_OP_MODE : uint8_t {
  TIMER = 0,
  PULSE_OUT = 1,
  EVENT_COUNTER = 2,
  MEASURE_PULSE_WIDTH = 3,
  MEASURE_PULSE_PERIOD = 4,
};

enum class TRJMR_SOURCE : uint8_t {
  F1 = 0,
  F8 = 1,
  FHOCO = 2,
  H2 = 3,
};

enum class TIMER_CUTOFF : uint8_t {
  SUPPLIED = 0,
  CUT_OFF = 1,
};

typedef union trjmr_t {
  struct {
    unsigned int op_mode:3;
    unsigned int edge:1;
    unsigned int source:3;
    unsigned int cutoff:1;
  } bits;
  uint8_t as_uint8;

  trjmr_t(uint8_t u = 0): as_uint8(u) {}

  trjmr_t clone() volatile {
    return trjmr_t(this->as_uint8);
  }

  trjmr_t& with_op_mode(TRJMR_OP_MODE op_mode) {
    this->bits.op_mode = (uint8_t)op_mode;
    return *this;
  }

  void set_op_mode(TRJMR_OP_MODE op_mode) volatile {
    this->bits.op_mode = (uint8_t)op_mode;
  }

  trjmr_t& with_edge(bool is_two_way_edge) {
    this->bits.edge = is_two_way_edge;
    return *this;
  }

  trjmr_t& with_source(TRJMR_SOURCE source) {
    this->bits.source = (uint8_t)source;
    return *this;
  }

  void set_source(TRJMR_SOURCE source) volatile {
    this->bits.source = (uint8_t)source;
  }

  trjmr_t& with_cutoff(TIMER_CUTOFF cutoff) {
    this->bits.cutoff = (uint8_t)cutoff;
    return *this;
  }

  void set_cutoff(TIMER_CUTOFF cutoff) volatile {
    this->bits.cutoff = (uint8_t)cutoff;
  }

  void set(const trjmr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trjmr_t;

enum class TRJISR_OUTPUT : uint8_t {
  TRCIOD = 0,
  TRCIOC = 1,
  TRCIOB = 2,
  TRCIOA = 3,
};

enum class TRJISR_COUNT_WHILE : uint8_t {
  LOW = 0,
  HIGH = 1,
};

typedef union trjisr_t {
  struct {
    unsigned int output:2;
    unsigned int count_while:1;
    unsigned int reserved:5;
  } bits;
  uint8_t as_uint8;

  trjisr_t(uint8_t u = 0): as_uint8(u) {}

  trjisr_t clone() volatile {
    return trjisr_t(this->as_uint8);
  }

  trjisr_t& with_output(TRJISR_OUTPUT out) {
    this->bits.output = (uint8_t)out;
    return *this;
  }

  void set_output(TRJISR_OUTPUT out) volatile {
    this->bits.output = (uint8_t)out;
  }

  trjisr_t& with_count_while(TRJISR_COUNT_WHILE cw) {
    this->bits.count_while = (uint8_t)cw;
    return *this;
  }

  void set_count_while(TRJISR_COUNT_WHILE cw) volatile {
    this->bits.count_while = (uint8_t)cw;
  }

  void set(const trjisr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trjisr_t;

typedef union timerir_t {
  struct {
    unsigned int reserved:6;
    bool is_itr_requested:1;
    bool is_itr_enabled:1;
  } bits;
  uint8_t as_uint8;

  timerir_t(uint8_t u = 0): as_uint8(u) {}

  timerir_t clone() volatile {
    return timerir_t(this->as_uint8);
  }

  timerir_t& with_itr_requested(bool b) {
    this->bits.is_itr_requested = b;
    return *this;
  }

  timerir_t& with_itr_enabled(bool enabled) {
    this->bits.is_itr_enabled = enabled;
    return *this;
  }

  void set(const timerir_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} timerir_t;

typedef union trbcr_t {
  struct {
    unsigned int tstart:1;
    unsigned int tcstf:1;
    bool force_stop:1;
    unsigned int reserved0:5;
  } bits;
  uint8_t as_uint8;

  trbcr_t(uint8_t u = 0): as_uint8(u) {}

  trbcr_t clone() volatile {
    return trbcr_t(this->as_uint8);
  }

  trbcr_t& with_tstart(uint8_t u) {
    this->bits.tstart = u;
    return *this;
  }

  trbcr_t& with_force_stop(bool force_stop) {
    this->bits.force_stop = force_stop;
    return *this;
  }

  void set(const trbcr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trbcr_t;

typedef union trbocr_t {
  struct {
    bool trigger_one_shot:1;
    bool stop_one_shot:1;
    bool is_one_shot_running:1;
    unsigned int reserved0:5;
  } bits;
  uint8_t as_uint8;

  trbocr_t(uint8_t u = 0): as_uint8(u) {}

  trbocr_t clone() volatile {
    return trbocr_t(this->as_uint8);
  }

  trbocr_t& with_trigger_one_shot(bool b) {
    this->bits.trigger_one_shot = b;
    return *this;
  }

  trbocr_t& with_stop_one_shot(bool b) {
    this->bits.stop_one_shot = b;
    return *this;
  }

  void set(const trbocr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trbocr_t;

enum class TRBIOC_OUTPUT : uint8_t {
  WAVEFORM = 0,
  FIXED_VALUE = 1,
};

enum class TRBIOC_EDGE : uint8_t {
  FALLING = 0,
  RISING = 1,
};

typedef union trbioc_t {
  struct {
    unsigned int topl:1;
    unsigned int output:1;
    bool is_int0_trigger_one_shot:1;
    unsigned int edge:1;
    unsigned int reserved0:4;
  } bits;
  uint8_t as_uint8;

  trbioc_t(uint8_t u = 0): as_uint8(u) {}

  trbioc_t clone() volatile {
    return trbioc_t(this->as_uint8);
  }

  trbioc_t& with_output(TRBIOC_OUTPUT out) {
    this->bits.output = (uint8_t)out;
    return *this;
  }

  void set_output(TRBIOC_OUTPUT out) volatile {
    this->bits.output = (uint8_t)out;
  }

  trbioc_t& with_int0_trigger_one_shot(bool b) {
    this->bits.is_int0_trigger_one_shot = b;
    return *this;
  }

  trbioc_t& with_edge(TRBIOC_EDGE edge) {
    this->bits.edge = (uint8_t)edge;
    return *this;
  }

  void set_edge(TRBIOC_EDGE edge) volatile {
    this->bits.edge = (uint8_t)edge;
  }

  void set(const trbioc_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trbioc_t;

enum class TRBMR_MODE : uint8_t {
  TIMER = 0,
  WAVEFORM = 1,
  ONE_SHOT = 2,
  WAIT_ONE_SHOT = 3,
};

enum class TRBMR_BIT_LEN : uint8_t {
  BITS_8 = 0,
  BITS_16 = 1,
};

enum class TRBMR_RELOAD_TGT : uint8_t {
  REGISTER_AND_COUNTER = 0,
  REGISTER_ONLY = 1,
};

enum class TRBMR_SOURCE : uint8_t {
  F1 = 0,
  F8 = 1,
  TIMER_RJ2_UNDERFLOW = 2,
  F2 = 3,
  F4 = 4,
  F32 = 5,
  F64 = 6,
  F128 = 7,
};

typedef union trbmr_t {
  struct {
    unsigned int mode:2;
    unsigned int bit_len:1;
    unsigned int reload_target:1;
    unsigned int source:3;
    unsigned int cutoff:1;
  } bits;
  uint8_t as_uint8;

  trbmr_t(uint8_t u = 0): as_uint8(u) {}

  trbmr_t clone() volatile {
    return trbmr_t(this->as_uint8);
  }

  trbmr_t& with_mode(TRBMR_MODE mode) {
    this->bits.mode = (uint8_t)mode;
    return *this;
  }

  void set_mode(TRBMR_MODE mode) volatile {
    this->bits.mode = (uint8_t)mode;
  }

  trbmr_t& with_bits(TRBMR_BIT_LEN len) {
    this->bits.bit_len = (uint8_t)len;
    return *this;
  }

  void set_bits(TRBMR_BIT_LEN len) volatile {
    this->bits.bit_len = (uint8_t)len;
  }

  trbmr_t& with_reload_target(TRBMR_RELOAD_TGT tgt) {
    this->bits.reload_target = (uint8_t)tgt;
    return *this;
  }

  void set_reload_target(TRBMR_RELOAD_TGT tgt) volatile {
    this->bits.reload_target = (uint8_t)tgt;
  }

  trbmr_t& with_source(TRBMR_SOURCE src) {
    this->bits.source = (uint8_t)src;
    return *this;
  }

  void set_source(TRBMR_SOURCE src) volatile {
    this->bits.source = (uint8_t)src;
  }

  trbmr_t& with_cutoff(TIMER_CUTOFF cutoff) {
    this->bits.cutoff = (uint8_t)cutoff;
    return *this;
  }

  void set_cutoff(TIMER_CUTOFF cutoff) volatile {
    this->bits.cutoff = (uint8_t)cutoff;
  }

  void set(const trbmr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trbmr_t;

enum class TRCMR_MODE : uint8_t {
  TIMER = 0,
  PWM = 1,
};

enum class TRCMR_MODE2 : uint8_t {
  PWM2 = 0,
  TIMER_OR_PWM = 1,
};

enum class TRCMR_TRCGR : uint8_t {
  OUT_CMP_OR_IN_CAPT = 0,
  BUF_OR_TRCGR_BUF = 1,
};

typedef union trcmr_t {
  struct {
    unsigned int trciob:1;
    unsigned int trcioc:1;
    unsigned int trciod:1;
    unsigned int pwm2:1;
    unsigned int bufea:1;
    unsigned int bufeb:1;
    unsigned int reserved0:1;
    bool is_count_started:1;
  } bits;
  uint8_t as_uint8;

  trcmr_t(uint8_t u = 0): as_uint8(u) {}

  trcmr_t clone() volatile {
    return trcmr_t(this->as_uint8);
  }

  trcmr_t& with_trciob(TRCMR_MODE mode) {
    this->bits.trciob = (uint8_t)mode;
    return *this;
  }

  void set_trciob(TRCMR_MODE mode) volatile {
    this->bits.trciob = (uint8_t)mode;
  }

  trcmr_t& with_trcioc(TRCMR_MODE mode) {
    this->bits.trcioc = (uint8_t)mode;
    return *this;
  }

  void set_trcioc(TRCMR_MODE mode) volatile {
    this->bits.trcioc = (uint8_t)mode;
  }

  trcmr_t& with_trciod(TRCMR_MODE mode) {
    this->bits.trciod = (uint8_t)mode;
    return *this;
  }

  void set_trciod(TRCMR_MODE mode) volatile {
    this->bits.trciod = (uint8_t)mode;
  }

  trcmr_t& with_pwm2(TRCMR_MODE2 mode) {
    this->bits.pwm2 = (uint8_t)mode;
    return *this;
  }

  void set_pwm2(TRCMR_MODE2 mode) volatile {
    this->bits.pwm2 = (uint8_t)mode;
  }

  trcmr_t& with_bufea(TRCMR_TRCGR buf) {
    this->bits.bufea = (uint8_t)buf;
    return *this;
  }

  void set_bufea(TRCMR_TRCGR buf) volatile {
    this->bits.bufea = (uint8_t)buf;
  }

  trcmr_t& with_bufeb(TRCMR_TRCGR buf) {
    this->bits.bufeb = (uint8_t)buf;
    return *this;
  }

  void set_bufeb(TRCMR_TRCGR buf) volatile {
    this->bits.bufeb = (uint8_t)buf;
  }

  void set(const trcmr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trcmr_t;

enum class TRCCR1_SOURCE : uint8_t {
  F1 = 0,
  F2 = 1,
  F4 = 2,
  F8 = 3,
  F32 = 4,
  FALLING_EDGE_TRCCLK = 5,
  HFOCO = 6,
};

enum class TRCCR1_CLEAR_MODE : uint8_t {
  DISABLED = 0,
  CLEARED = 1,
};

typedef union trccr1_t {
  struct {
    unsigned int trcioa_output_level:1;
    unsigned int trciob_output_level:1;
    unsigned int trcioc_output_level:1;
    unsigned int trciod_output_level:1;
    unsigned int source:3;
    unsigned int trccnt_clear_mode:1;
  } bits;
  uint8_t as_uint8;

  trccr1_t(uint8_t u = 0): as_uint8(u) {}

  trccr1_t clone() volatile {
    return trccr1_t(this->as_uint8);
  }

  trccr1_t& with_trcioa_output_level(uint8_t u) {
    this->bits.trcioa_output_level = u;
    return *this;
  }

  trccr1_t& with_trciob_output_level(uint8_t u) {
    this->bits.trciob_output_level = u;
    return *this;
  }

  trccr1_t& with_trcioc_output_level(uint8_t u) {
    this->bits.trcioc_output_level = u;
    return *this;
  }

  trccr1_t& with_trciod_output_level(uint8_t u) {
    this->bits.trciod_output_level = u;
    return *this;
  }

  trccr1_t& with_source(TRCCR1_SOURCE source) {
    this->bits.source = (uint8_t)source;
    return *this;
  }

  void set_source(TRCCR1_SOURCE source) volatile {
    this->bits.source = (uint8_t)source;
  }

  trccr1_t& with_trccnt_clear_mode(TRCCR1_CLEAR_MODE mode) {
    this->bits.trccnt_clear_mode = (uint8_t)mode;
    return *this;
  }

  void set_trccnt_clear_mode(TRCCR1_CLEAR_MODE mode) volatile {
    this->bits.trccnt_clear_mode = (uint8_t)mode;
  }

  void set(const trccr1_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trccr1_t;

typedef union trcier_t {
  struct {
    bool imia_itr_enabled:1;
    bool imib_itr_enabled:1;
    bool imic_itr_enabled:1;
    bool imid_itr_enabled:1;
    unsigned int reserved0:3;
    bool overflow_itr_enabled:1;
  } bits;
  uint8_t as_uint8;

  trcier_t(uint8_t u = 0): as_uint8(u) {}

  trcier_t clone() volatile {
    return trcier_t(this->as_uint8);
  }

  trcier_t& with_imia_itr_enabled(bool enabled) {
    this->bits.imia_itr_enabled = enabled;
    return *this;
  }

  trcier_t& with_imib_itr_enabled(bool enabled) {
    this->bits.imib_itr_enabled = enabled;
    return *this;
  }

  trcier_t& with_imic_itr_enabled(bool enabled) {
    this->bits.imic_itr_enabled = enabled;
    return *this;
  }

  trcier_t& with_imid_itr_enabled(bool enabled) {
    this->bits.imid_itr_enabled = enabled;
    return *this;
  }

  trcier_t& with_overflow_itr_enabled(bool enabled) {
    this->bits.overflow_itr_enabled = enabled;
    return *this;
  }

  void set(const trcier_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trcier_t;

typedef union trcsr_t {
  struct {
    unsigned int imfa:1;
    unsigned int imfb:1;
    unsigned int imfc:1;
    unsigned int imfd:1;
    unsigned int reserved0:3;
    unsigned int ovf:1;
  } bits;
  uint8_t as_uint8;

  trcsr_t(uint8_t u = 0): as_uint8(u) {}

  trcsr_t clone() volatile {
    return trcsr_t(this->as_uint8);
  }

  trcsr_t& with_imfa(uint8_t u) {
    this->bits.imfa = u;
    return *this;
  }

  trcsr_t& with_imfb(uint8_t u) {
    this->bits.imfb = u;
    return *this;
  }

  trcsr_t& with_imfc(uint8_t u) {
    this->bits.imfc = u;
    return *this;
  }

  trcsr_t& with_imfd(uint8_t u) {
    this->bits.imfd = u;
    return *this;
  }

  trcsr_t& with_ovf(uint8_t u) {
    this->bits.ovf = u;
    return *this;
  }

  void set(const trcsr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trcsr_t;

enum class TRCIOR0_CTRL : uint8_t {
  OUT_COMP_DISABLED = 0,
  OUT_COMP_LOW_LEVEL = 1,
  OUT_COMP_HIGH_LEVEL = 2,
  OUT_COMP_TOGGLE = 3,
  IN_CAPT_RISING_EDGE = 4,
  IN_CAPT_FALLING_EDGE = 5,
  IN_CAPT_BOTH_EDGE = 6,
};

typedef union trcior0_t {
  struct {
    unsigned int trcgra_ctrl:3;
    unsigned int reserved0:1;
    unsigned int trcgrb_ctrl:3;
    unsigned int reserved1:1;
  } bits;
  uint8_t as_uint8;

  trcior0_t(uint8_t u = 0): as_uint8(u) {}

  trcior0_t clone() volatile {
    return trcior0_t(this->as_uint8);
  }

  trcior0_t& with_trcgra_ctrl(TRCIOR0_CTRL ctrl) {
    this->bits.trcgra_ctrl = (uint8_t)ctrl;
    return *this;
  }

  void set_trcgra_ctrl(TRCIOR0_CTRL ctrl) volatile {
    this->bits.trcgra_ctrl = (uint8_t)ctrl;
  }

  trcior0_t& with_trcgrb_ctrl(TRCIOR0_CTRL ctrl) {
    this->bits.trcgrb_ctrl = (uint8_t)ctrl;
    return *this;
  }

  void set_trcgrb_ctrl(TRCIOR0_CTRL ctrl) volatile {
    this->bits.trcgrb_ctrl = (uint8_t)ctrl;
  }

  void set(const trcior0_t that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trcior0_t;

enum class TRCIOR1_TRCGRC_CTRL : uint8_t {
  OUT_COMP_TRCIOA_DISABLED = 0,
  OUT_COMP_TRCIOA_LOW_LEVEL = 1,
  OUT_COMP_TRCIOA_HIGH_LEVEL = 2,
  OUT_COMP_TRCIOA_TOGGLE = 3,
  OUT_COMP_TRCIOC_DISABLED = 8, 
  OUT_COMP_TRCIOC_LOW_LEVEL = 9, 
  OUT_COMP_TRCIOC_HIGH_LEVEL = 10, 
  OUT_COMP_TRCIOC_TOGGLE = 11, 
  IN_CAPT_TRCIOC_RISING_EDGE = 12,
  IN_CAPT_TRCIOC_FALING_EDGE = 13,
  IN_CAPT_TRCIOC_BOTH_EDGE = 14,
};

enum class TRCIOR1_TRCGRD_CTRL : uint8_t {
  OUT_COMP_TRCIOB_DISABLED = 0,
  OUT_COMP_TRCIOB_LOW_LEVEL = 1,
  OUT_COMP_TRCIOB_HIGH_LEVEL = 2,
  OUT_COMP_TRCIOB_TOGGLE = 3,
  OUT_COMP_TRCIOD_DISABLED = 8, 
  OUT_COMP_TRCIOD_LOW_LEVEL = 9, 
  OUT_COMP_TRCIOD_HIGH_LEVEL = 10, 
  OUT_COMP_TRCIOD_TOGGLE = 11, 
  IN_CAPT_TRCIOD_RISING_EDGE = 12,
  IN_CAPT_TRCIOD_FALING_EDGE = 13,
  IN_CAPT_TRCIOD_BOTH_EDGE = 14,
};

typedef union trcior1_t {
  struct {
    unsigned int trcgrc_ctrl:4;
    unsigned int trcgrd_ctrl:4;
  } bits;
  uint8_t as_uint8;

  trcior1_t(uint8_t u = 0): as_uint8(u) {}

  trcior1_t clone() volatile {
    return trcior1_t(this->as_uint8);
  }

  trcior1_t& with_trcgrc_ctrl(TRCIOR1_TRCGRC_CTRL ctrl) {
    this->bits.trcgrc_ctrl = (uint8_t)ctrl;
    return *this;
  }

  void set_trcgrc_ctrl(TRCIOR1_TRCGRC_CTRL ctrl) volatile {
    this->bits.trcgrc_ctrl = (uint8_t)ctrl;
  }

  trcior1_t& with_trcgrd_ctrl(TRCIOR1_TRCGRD_CTRL ctrl) {
    this->bits.trcgrd_ctrl = (uint8_t)ctrl;
    return *this;
  }

  void set_trcgrd_ctrl(TRCIOR1_TRCGRD_CTRL ctrl) volatile {
    this->bits.trcgrd_ctrl = (uint8_t)ctrl;
  }

  void set(const trcior1_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trcior1_t;

enum class TRCCR2_EDGE : uint8_t {
  DISABLED = 0,
  RISING = 1,
  FALLING = 2,
  BOTH = 3,
};

typedef union trccr2_t {
  struct {
    bool is_trciob_active_high:1;
    bool is_trcioc_active_high:1;
    bool is_trciod_active_high:1;
    unsigned int reserved0:2;
    bool is_count_stopped:1;
    unsigned int edge:2;
  } bits;
  uint8_t as_uint8;

  trccr2_t(uint8_t u = 0): as_uint8(u) {}

  trccr2_t clone() volatile {
    return trccr2_t(this->as_uint8);
  }

  trccr2_t& with_trciob_active_high(bool b) {
    this->bits.is_trciob_active_high = b;
    return *this;
  }

  trccr2_t& with_trcioc_active_high(bool b) {
    this->bits.is_trcioc_active_high = b;
    return *this;
  }

  trccr2_t& with_trciod_active_high(bool b) {
    this->bits.is_trciod_active_high = b;
    return *this;
  }

  trccr2_t& with_counter_stopped(bool b) {
    this->bits.is_count_stopped = b;
    return *this;
  }

  trccr2_t& with_edge(TRCCR2_EDGE edge) {
    this->bits.edge = (uint8_t)edge;
    return *this;
  }

  void set_edge(TRCCR2_EDGE edge) volatile {
    this->bits.edge = (uint8_t)edge;
  }

  void set(const trccr2_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trccr2_t;

enum class TRCDF_CLOCK : uint8_t {
  F32 = 0,
  F8 = 1,
  F1 = 2,
  COUNT = 3,
};

typedef union trcdf_t {
  struct {
    bool is_trcioa_filter_enabled:1;
    bool is_trciob_filter_enabled:1;
    bool is_trcioc_filter_enabled:1;
    bool is_trciod_filter_enabled:1;
    bool is_trciog_filter_enabled:1;
    unsigned int reserved0:1;
    unsigned int clock:2;
  } bits;
  uint8_t as_uint8;

  trcdf_t(uint8_t u = 0): as_uint8(u) {}

  trcdf_t clone() volatile {
    return trcdf_t(this->as_uint8);
  }

  trcdf_t& with_trcioa_filter_enabled(bool enabled) {
    this->bits.is_trcioa_filter_enabled = enabled;
    return *this;
  }

  trcdf_t& with_trciob_filter_enabled(bool enabled) {
    this->bits.is_trciob_filter_enabled = enabled;
    return *this;
  }

  trcdf_t& with_trcioc_filter_enabled(bool enabled) {
    this->bits.is_trcioc_filter_enabled = enabled;
    return *this;
  }

  trcdf_t& with_trciod_filter_enabled(bool enabled) {
    this->bits.is_trciod_filter_enabled = enabled;
    return *this;
  }
  
  trcdf_t& with_trciog_filter_enabled(bool enabled) {
    this->bits.is_trciog_filter_enabled = enabled;
    return *this;
  }

  trcdf_t& with_clock(TRCDF_CLOCK clock) {
    this->bits.clock = (uint8_t)clock;
    return *this;
  }

  void set_clock(TRCDF_CLOCK clock) volatile {
    this->bits.clock = (uint8_t)clock;
  }

  void set(const trcdf_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trcdf_t;

enum class TRCOER_E : uint8_t {
  ENABLED = 0,
  DISABLED_OR_HIGH_IMP = 1,
};

enum class TRCOER_OUT : uint8_t {
  DO_NOT_CHANGE = 0,
  SET = 1,
};

typedef union trcoer_t {
  struct {
    unsigned int trcioa:1;
    unsigned int trciob:1;
    unsigned int trcioc:1;
    unsigned int trciod:1;
    unsigned int reserved0:3;
    unsigned int timer_output:1;
  } bits;
  uint8_t as_uint8;

  trcoer_t(uint8_t u = 0): as_uint8(u) {}

  trcoer_t clone() volatile {
    return trcoer_t(this->as_uint8);
  }

  trcoer_t& with_trcioa(TRCOER_E e) {
    this->bits.trcioa = (uint8_t)e;
    return *this;
  }

  void set_trcioa(TRCOER_E e) volatile {
    this->bits.trcioa = (uint8_t)e;
  }

  trcoer_t& with_trciob(TRCOER_E e) {
    this->bits.trciob = (uint8_t)e;
    return *this;
  }

  void set_trciob(TRCOER_E e) volatile {
    this->bits.trciob = (uint8_t)e;
  }

  trcoer_t& with_trcioc(TRCOER_E e) {
    this->bits.trcioc = (uint8_t)e;
    return *this;
  }

  void set_trcioc(TRCOER_E e) volatile {
    this->bits.trcioc = (uint8_t)e;
  }

  trcoer_t& with_trciod(TRCOER_E e) {
    this->bits.trciod = (uint8_t)e;
    return *this;
  }

  void set_trciod(TRCOER_E e) volatile {
    this->bits.trciod = (uint8_t)e;
  }

  trcoer_t& with_timer_output(TRCOER_OUT out) {
    this->bits.timer_output = (uint8_t)out;
    return *this;
  }

  void set_timer_output(TRCOER_OUT out) volatile {
    this->bits.timer_output = (uint8_t)out;
  }

  void set(const trcoer_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trcoer_t;

typedef union trcadcr_t {
  struct {
    bool ad_a_trigger_start:1;
    bool ad_b_trigger_start:1;
    bool ad_c_trigger_start:1;
    bool ad_d_trigger_start:1;
    unsigned int reserved0:4;
  } bits;
  uint8_t as_uint8;

  trcadcr_t(uint8_t u = 0): as_uint8(u) {}

  trcadcr_t clone() volatile {
    return trcadcr_t(this->as_uint8);
  }

  trcadcr_t& with_ad_a_trigger_start(bool b) {
    this->bits.ad_a_trigger_start = b;
    return *this;
  }

  trcadcr_t& with_ad_b_trigger_start(bool b) {
    this->bits.ad_b_trigger_start = b;
    return *this;
  }

  trcadcr_t& with_ad_c_trigger_start(bool b) {
    this->bits.ad_c_trigger_start = b;
    return *this;
  }

  trcadcr_t& with_ad_d_trigger_start(bool b) {
    this->bits.ad_d_trigger_start = b;
    return *this;
  }

  void set(const trcadcr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trcadcr_t;

enum class TRCOPR_OP_SEL {
  B1 = 0,
  INT1 = 1,
  BOTH0 = 2,
  BOTH1 = 3,
};

enum class TRCOPR_OP_OUT_LEVEL {
  HI_IMP_WHEN_PULL_DOWN,
  HI_IMP_WHEN_PULL_UP,
  LOW_WHILE_OUT_PERIOD,
  HI_WHILE_OUT_PERIOD,
};

typedef union trcopr_t {
  struct {
    unsigned int opsel:2;
    unsigned int opol:2;
    bool is_out_auto_started:1;
    bool is_wave_man_enabled:1;
    unsigned int reserved0:2;
  } bits;
  uint8_t as_uint8;

  trcopr_t(uint8_t u = 0): as_uint8(u) {}

  trcopr_t clone() volatile {
    return trcopr_t(this->as_uint8);
  }

  trcopr_t& with_opsel(TRCOPR_OP_SEL sel) {
    this->bits.opsel = (uint8_t)sel;
    return *this;
  }

  void set_opsel(TRCOPR_OP_SEL sel) volatile {
    this->bits.opsel = (uint8_t)sel;
  }

  trcopr_t& with_opol(TRCOPR_OP_OUT_LEVEL ol) {
    this->bits.opol = (uint8_t)ol;
    return *this;
  }

  void set_opol(TRCOPR_OP_OUT_LEVEL ol) volatile {
    this->bits.opol = (uint8_t)ol;
  }

  trcopr_t& with_out_auto_started(bool b) {
    this->bits.is_out_auto_started = b;
    return *this;
  }

  trcopr_t& with_wave_man_enabled(bool enabled) {
    this->bits.is_wave_man_enabled = enabled;
    return *this;
  }

  void set(const trcopr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} trcopr_t;

enum class WCMPR_COND : uint8_t {
  CMP_LESS_THAN_REF_OR_DISABLED = 0,
  CMP_GREATER_THAN_REF = 1,
};

typedef union wcmpr_t {
  struct {
    bool op1_enabled:1;
    unsigned reserved0:2;
    unsigned int cond1:1;
    bool op3_enabled:1;
    unsigned reserved1:2;
    unsigned int cond3:1;
  } bits;
  uint8_t as_uint8;

  wcmpr_t(uint8_t u = 0): as_uint8(u) {}

  wcmpr_t clone() volatile {
    return wcmpr_t(this->as_uint8);
  }

  wcmpr_t& with_op1_enabled1(bool e) {
    this->bits.op1_enabled = e;
    return *this;
  }

  wcmpr_t& with_op3_enabled1(bool e) {
    this->bits.op3_enabled = e;
    return *this;
  }

  void set(const wcmpr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} wcmpr_t;

enum class CMP_FILTER_SMPL : uint8_t {
  NO_FILTER = 0,
  F1 = 1,
  F8 = 2,
  F32 = 3,
};

enum class CMP_ITR_EDGE: uint8_t {
  LOWER = 0,
  HIGHER = 1,
  BOTH = 2,
};

typedef union wcbintr_t {
  struct {
    unsigned int smpl:2;
    unsigned int reserved0:2;
    unsigned int itr_edge:2;
    bool is_itr_enabled:1;
    bool is_itr_requested:1;
  } bits;
  uint8_t as_uint8;

  wcbintr_t(uint8_t u = 0): as_uint8(u) {}

  wcbintr_t clone() volatile {
    return wcbintr_t(this->as_uint8);
  }

  wcbintr_t& with_smpl(CMP_FILTER_SMPL smpl) {
    this->bits.smpl = (uint8_t)smpl;
    return *this;
  }

  void set_smpl(CMP_FILTER_SMPL smpl) volatile {
    this->bits.smpl = (uint8_t)smpl;
  }

  wcbintr_t& with_itr_edge(CMP_ITR_EDGE edge) {
    this->bits.itr_edge = (uint8_t)edge;
    return *this;
  }

  void set_itr_edge(CMP_ITR_EDGE edge) volatile {
    this->bits.itr_edge = (uint8_t)edge;
  }

  wcbintr_t& with_itr_enabled(bool e) {
    this->bits.is_itr_enabled = e;
    return *this;
  }

  wcbintr_t& with_itr_requested(bool e) {
    this->bits.is_itr_requested = e;
    return *this;
  }

  void set(const wcbintr_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} wcbintr_t;

typedef union fst_t {
  struct {
    bool is_ready_itr_requested:1;
    bool is_access_err_itr_requested:1;
    bool is_unlokced:1;
    bool is_program_suspended:1;
    bool is_program_error:1;
    bool is_erase_error:1;
    bool is_erase_suspended:1;
    bool is_ready:1;
  } bits;
  uint8_t as_uint8;

  fst_t(uint8_t u = 0): as_uint8(u) {}

  fst_t clone() volatile {
    return fst_t(this->as_uint8);
  }

  fst_t& with_ready_itr_requested(bool b) {
    this->bits.is_ready_itr_requested = b;
    return *this;
  }

  fst_t& with_access_err_itr_requested(bool b) {
    this->bits.is_access_err_itr_requested = b;
    return *this;
  }

  void set(const fst_t& that) {
    this->as_uint8 = that.as_uint8;
  }
} fst_t;

enum class FMR0_EW_MODE : uint8_t {
  EW0_MODE = 0,
  EW1_MODE = 1,
};

typedef union fmr0_t {
  struct {
    unsigned reserved0:1;
    bool is_cpu_rewrite_enabled:1;
    unsigned int ew_mode:1;
    bool is_flash_memory_stopped:1;
    bool is_write_seq_reset:1;
    bool is_write_error_itr_enabled:1;
    bool is_access_error_itr_enabled:1;
    bool is_ready_itr_enabled:1;
  } bits;
  uint8_t as_uint8;

  fmr0_t(uint8_t u = 0): as_uint8(u) {}

  fmr0_t clone() volatile {
    return fmr0_t(this->as_uint8);
  }

  fmr0_t& with_cpu_rewrite_enabled(bool e) {
    this->bits.is_cpu_rewrite_enabled = e;
    return *this;
  }

  fmr0_t& with_ew_mode(FMR0_EW_MODE mode) {
    this->bits.ew_mode = (uint8_t)mode;
    return *this;
  }

  void set_ew_mode(FMR0_EW_MODE mode) volatile {
    this->bits.ew_mode = (uint8_t)mode;
  }

  fmr0_t& with_flash_memory_stopped(bool b) {
    this->bits.is_flash_memory_stopped = b;
    return *this;
  }

  fmr0_t& with_write_seq_reset(bool b) {
    this->bits.is_write_seq_reset = b;
    return *this;
  }

  fmr0_t& with_write_error_itr_enabled(bool b) {
    this->bits.is_write_error_itr_enabled = b;
    return *this;
  }

  fmr0_t& with_access_error_itr_enabled(bool b) {
    this->bits.is_access_error_itr_enabled = b;
    return *this;
  }

  fmr0_t& with_ready_itr_enabled(bool b) {
    this->bits.is_ready_itr_enabled = b;
    return *this;
  }

  void set(const fmr0_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} fmr0_t;

typedef union fmr1_t {
  struct {
    unsigned int reserved0:2;
    bool is_stopped_in_wait_mode:1;
    bool is_unlocked:1;
    unsigned int reserved1:2;
    bool is_block_a_rewrite_disabled:1;
    bool is_block_b_rewrite_disabled:1;
  } bits;
  uint8_t as_uint8;

  fmr1_t(uint8_t u = 0): as_uint8(u) {}

  fmr1_t clone() volatile {
    return fmr1_t(this->as_uint8);
  }

  fmr1_t& with_stopped_in_wait_mode(bool b) {
    this->bits.is_stopped_in_wait_mode = b;
    return *this;
  }

  fmr1_t& with_unlocked(bool b) {
    this->bits.is_unlocked = b;
    return *this;
  }

  fmr1_t& with_block_a_rewrite_disabled(bool b) {
    this->bits.is_block_a_rewrite_disabled = b;
    return *this;
  }

  fmr1_t& with_block_b_rewrite_disabled(bool b) {
    this->bits.is_block_b_rewrite_disabled = b;
    return *this;
  }

  void set(const fmr1_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} fmr1_t;

typedef union fmr2_t {
  struct {
    bool is_suspend_enabled:1;
    bool is_suspend_requested:1;
    bool req_suspend_by_itr:1;
    unsigned int reserved0:4;
    bool is_power_saving_enabled:1;
  } bits;
  uint8_t as_uint8;

  fmr2_t(uint8_t u = 0): as_uint8(u) {}

  fmr2_t clone() volatile {
    return fmr2_t(this->as_uint8);
  }

  fmr2_t& with_suspend_enabled(bool b) {
    this->bits.is_suspend_enabled = b;
    return *this;
  }

  fmr2_t& with_suspend_requested(bool b) {
    this->bits.is_suspend_requested = b;
    return *this;
  }

  fmr2_t& with_req_suspend_by_itr(bool b) {
    this->bits.req_suspend_by_itr = b;
    return *this;
  }

  fmr2_t& with_power_saving_enabled(bool b) {
    this->bits.is_power_saving_enabled = b;
    return *this;
  }

  void set(const fmr2_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} fmr2_t;

enum class OFS2_WDT_UNDERFLOW_PERIOD {
  L03FF = 0,
  L0FFF = 1,
  L1FFF = 2,
  L3FFF = 3,
};

enum class OFS2_WDT_REFRESH_PERIOD {
  P25 = 0,
  P50 = 1,
  P75 = 2,
  P100 = 3,
};

enum class OFS2_MSTCR_INI_VALUE {
  V0 = 0,
  Vx77 = 1,
};

typedef union ofs2_t {
  struct {
    unsigned int wdt_underflow_period:2;
    unsigned int wdt_refresh_period:2;
    unsigned int reserved0:1;
    unsigned int mstcr_ini_value:1;
    unsigned int reserved1:2;
  } bits;
  uint8_t as_uint8;

  ofs2_t(uint8_t u = 0): as_uint8(u) {}

  ofs2_t clone() volatile {
    return ofs2_t(this->as_uint8);
  }

  ofs2_t& with_wdt_underflow_period(OFS2_WDT_UNDERFLOW_PERIOD v) {
    this->bits.wdt_underflow_period = (uint8_t)v;
    return *this;
  }

  void with_wdt_underflow_period(OFS2_WDT_UNDERFLOW_PERIOD v) volatile {
    this->bits.wdt_underflow_period = (uint8_t)v;
  }

  ofs2_t& with_wdt_refresh_period(OFS2_WDT_REFRESH_PERIOD v) {
    this->bits.wdt_refresh_period = (uint8_t)v;
    return *this;
  }

  void set_wdt_refresh_period(OFS2_WDT_REFRESH_PERIOD v) volatile {
    this->bits.wdt_refresh_period = (uint8_t)v;
  }

  ofs2_t& with_mstcr_ini_value(OFS2_MSTCR_INI_VALUE v) {
    this->bits.mstcr_ini_value = (uint8_t)v;
    return *this;
  }

  void set_mstcr_ini_value(OFS2_MSTCR_INI_VALUE v) volatile {
    this->bits.mstcr_ini_value = (uint8_t)v;
  }

  void set(const ofs2_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} ofs2_t;

enum class OFS_V_DTCT {
  V3_80 = 0,
  V2_85 = 1,
  V2_35 = 2,
  V1_90 = 3, 
};

typedef union ofs_t {
  struct {
    bool stop_wdt_after_reset:1;
    unsigned int reserved0:1;
    bool is_disable_protect_rom_bit_enabled:1;
    bool disable_protect_rom:1;
    unsigned int v_dtct:2;
    bool is_v_mon_rst_disabled:1;
    bool is_cnt_src_protect_mode_disabled:1;
  } bits;
  uint8_t as_uint8;

  ofs_t(uint8_t u = 0): as_uint8(u) {}

  ofs_t clone() volatile {
    return ofs_t(this->as_uint8);
  }

  ofs_t& with_stop_wdt_after_reset(bool b) {
    this->bits.stop_wdt_after_reset = b;
    return *this;
  }

  ofs_t& with_disable_protect_rom_bit_enabled(bool b) {
    this->bits.is_disable_protect_rom_bit_enabled = b;
    return *this;
  }

  ofs_t& with_disable_protect_rom(bool b) {
    this->bits.disable_protect_rom = b;
    return *this;
  }

  ofs_t& with_v_dtct(OFS_V_DTCT dtct) {
    this->bits.v_dtct = (uint8_t)dtct;
    return *this;
  }

  void set_v_dtct(OFS_V_DTCT dtct) volatile {
    this->bits.v_dtct = (uint8_t)dtct;
  }

  ofs_t& with_v_mon_rst_disabled(bool b) {
    this->bits.is_v_mon_rst_disabled = b;
    return *this;
  }

  ofs_t& with_cnt_src_protect_mode_disabled(bool b) {
    this->bits.is_cnt_src_protect_mode_disabled = b;
    return *this;
  }

  void set(const ofs_t& that) volatile {
    this->as_uint8 = that.as_uint8;
  }
} ofs_t;

typedef struct {
  uint8_t buf[32767];
} foo;

typedef struct {
  struct { // 0x00010
    unsigned int reserved0:3;
    unsigned int srst:1;
    unsigned int reserved1:4;
  } pm0;

  uint8_t padding0; // 0x00011
  mstcr_t mstcr; // 0x00012
  prcr_t prcr; // 0x00013

  uint8_t padding1[2]; // 0x00014

  struct { // 0x00016
    unsigned int pamcre: 1;
    unsigned int reserved0: 7;
  } hrpr;

  uint8_t padding2[9]; // 0x00017

  exckcr_t exckcr; // 0x00020
  ococr_t ococr; // 0x00021
  sckcr_t sckcr; // 0x00022
  uint8_t phisel;  // 0x00023
  ckstpr_t ckstpr; // 0x00024
  ckrscr_t ckrscr; // 0x00025
  bakcr_t bakcr; // 0x00026

  uint8_t padding4[9]; // 0x00027
  
  struct { // 0x00030
    unsigned int reserved0:6;
    unsigned int ufif:1;
    unsigned int ris:1;
  } risr;

  uint8_t wdtr; // 0x00031
  uint8_t wdts; // 0x00032
  wdtc_t wdtc; // 0x00033

  struct { // 0x00034
    unsigned int reserved0:7;
    unsigned int cspro:1;
  } cspr;

  struct { // 0x00035
    unsigned int reserved0:6;
    unsigned int itr_req_flag:1;
    unsigned int itr_enabled:1;
  } wdtir;

  uint8_t padding5[2]; // 0x00036
  
  struct { // 0x00038
    unsigned int int0_enabled:1;
    unsigned int int1_enabled:1;
    unsigned int int2_enabled:1;
    unsigned int int3_enabled:1;
    unsigned int reserved0:4;
  } inten;

  uint8_t padding6[1]; // 0x00039
  
  intf0_t intf0; // 0x0003A

  uint8_t padding7[1]; // 0x0003B

  iscr0_t iscr0; // 0x0003C

  uint8_t padding8[1]; // 0x0003D

  kien_t kien; // 0x0003E

  uint8_t padding9[1]; // 0x0003F

  ilvl0_t ilvl0; // 0x00040

  uint8_t padding10[1]; // 0x00041

  ilvl2_t ilvl2; // 0x00042
  ilvl3_t ilvl3; // 0x00043

  uint8_t ilvl4[1]; // 0x00044
  uint8_t ilvl5[1]; // 0x00045

  ilvl6_t ilvl6; // 0x00046
  ilvl7_t ilvl7; // 0x00047
  ilvl8_t ilvl8; // 0x00048
  ilvl9_t ilvl9; // 0x0004A
  ilvla_t ilvla; // 0x0004B
  ilvlb_t ilvlb; // 0x0004C
  ilvlc_t ilvlc; // 0x0004C
  ilvld_t ilvld; // 0x0004D
  ilvle_t ilvle; // 0x0004E
  
  uint8_t padding11[1]; // 0x0004F

  struct { // 0x00050
    bool timer_rj2_itr_requested:1;
    bool timer_rb2_itr_requested:1;
    bool timer_rc_itr_requested:1;
    unsigned int reserved0:1;
    bool uart_tx_itr_requested:1;
    bool uart_rx_itr_requested:1;
    unsigned int reserved1:2;
  } irr0;

  struct { // 0x00051
    unsigned int reserved0:2;
    bool adc_itr_requested:1;
    unsigned int reserved1:1;
    bool flash_ready_itr_requested:1;
    bool ped_timer_itr_requested:1;
    unsigned int reserved2:2;
  } irr1;

  struct { // 0x00052
    unsigned int reserved0:2;
    bool comparator_b1_itr_requested:1;
    bool comparator_b3_itr_requested:1;
    unsigned int reserved1:4;
  } irr2;

  struct { // 0x00053
    bool int0_itr_requestd:1;
    bool int1_itr_requested:1;
    bool int2_itr_requested:1;
    bool int3_itr_requested:1;
    unsigned int reserved0:1;
    bool key_input_itr_requested:1;
    unsigned int reserved1:2;
  } irr3;

  uint8_t padding12[4]; // 0x00054
  
  struct { // 0x00058
    unsigned int reserved0:1;
    bool is_two_way_edge:1;
    unsigned int reserved1:6;
  } vcac;

  uint8_t padding13[1]; // 0x00059

  vca2_t vca2; //0x0005A

  vd1ls_t vd1ls; // 0x0005B
  vw0c_t vw0c; // 0x0005C
  vw1c_t vw1c; // 0x0005D

  uint8_t padding14[1]; // 0x0005E

  struct { // 0x0005F
    bool is_warm_start:1;
    bool is_hw_reset_detected:1;
    bool is_sw_reset_detected:1;
    bool is_wdt_reset_detected:1;
    unsigned int reserved:4;
  } rstfr;

  uint8_t padding15[4]; // 0x00060
  
  uint16_t fr18s; // 0x00064

  uint8_t padding16[1]; // 0x00066

  uint16_t frv1; // 0x00067

  uint8_t padding17[7]; // 0x00069
  uint8_t padding18[16]; // 0x00070

  u0mr_t u0mr; // 0x00080
  uint8_t u0brg; // 0x00081
  uint8_t u0tbl; // 0x00082
  uint8_t u0tbh; // 0x00083

  u0c0_t u0c0; // 0x00084
  u0c1_t u0c1; // 0x00085
  u0rb_t u0rb; // 0x00086
  u0ir_t u0ir; // 0x00088

  uint8_t padding19[7]; // 0x00089
  uint8_t padding20[8]; // 0x00090

  uint16_t ad0; // 0x00098
  uint16_t ad1; // 0x0009a

  admod_t admod; // 0x0009c

  adinsel_t adinsel; // 0x0009d

  struct { // 0x0009e
    unsigned int ad_starts:1;
    unsigned int reserved0:7;
  } adcon0;

  adicsr_t adicsr; // 0x0009f

  uint8_t padding21[9]; // 0x000A0

  pd1_t pd1; // 0x000A9

  uint8_t padding22[1]; // 0x000AA

  pd3_t pd3; // 0x000AB
  pd4_t pd4; // 0x000AC

  struct { // 0x000AD
    bool is_out_mode:1;
    unsigned int reserved0:7;
  } pda;

  uint8_t padding23[1]; // 0x000AE

  p1_t p1; // 0x000AF

  uint8_t padding24[1]; // 0x000B0

  p3_t p3; // 0x000B1
  p4_t p4; // 0x000B2

  struct { // 0x000B3
    unsigned int b0:1;
    unsigned int reserved0:7;
  } pa;

  uint8_t padding25[1]; // 0x000B4

  pur1_t pur1; // 0x000B5

  uint8_t padding26[1]; // 0x000B6

  pur3_t pur3; // 0x000B7
  pur4_t pur4; // 0x000B8

  pinsr_t pinsr; // 0x000B9

  uint8_t padding27[1]; // 0x000BA

  drr1_t drr1; // 0x000BB

  uint8_t padding28[1]; // 0x000BC

  drr3_t drr3; // 0x000BD

  uint8_t padding29[3]; // 0x000BE

  pod1_t pod1; // 0x000C1

  uint8_t padding30[1]; // 0x000C2

  pod3_t pod3; // 0x000C3
  pod4_t pod4; // 0x000C4
  pamcr_t pamcr; // 0x000C5

  uint8_t padding31[2]; // 0x000C6

  pm1_t pm1; // 0x000C8

  uint8_t padding32[2]; // 0x000CA
  
  pm3_t pm3; // 0x000CC
  pm4_t pm4; // 0x000CE

  uint8_t padding33[1]; // 0x000D0

  pmh1e_t pmh1e; // 0x000D1

  uint8_t padding34[3]; // 0x000D2

  pmh4e_t pmh4; // 0x000D5

  uint8_t padding35[2]; // 0x000D6

  uint16_t trj; // 0x000D8
  trjcr_t trjcr; // 0x000DA
  trjioc_t trjioc; // 0x000DB
  trjmr_t trjmr; // 0x000DC
  trjisr_t trjisr; // 0x000DD
  timerir_t trjir; // 0x000DE

  uint8_t padding36[1]; // 0x000DF

  trbcr_t trbcr; // 0x000E0
  trbocr_t trbocr; // 0x000E1
  trbioc_t trbioc; // 0x000E2
  trbmr_t trbmr; // 0x000E3
  uint8_t trbpre; // 0x000E4
  uint8_t trbpr; // 0x000E5
  uint8_t trbsc; // 0x000E6
  timerir_t trbir; // 0x000E7
  uint16_t trccnt; // 0x000E8
  uint16_t trcgra; // 0x000EA
  uint16_t trcgrb; // 0x000EC
  uint16_t trcgrc; // 0x000EE
  uint16_t trcgrd; // 0x000F0
  trcmr_t trcmr; // 0x000F2
  trccr1_t trccr1; // 0x000F3
  trcier_t trcier; // 0x000F4
  trcsr_t trcsr; // 0x000F5
  trcior0_t trcior0; // 0x000F6
  trcior1_t trcior1; // 0x000F7
  trccr2_t trccr2; // 0x000F8
  trcdf_t trcdf; // 0x000F9
  trcoer_t trcoer; // 0x000FA
  trcadcr_t trcadcr; // 0x000FB
  trcopr_t trcopr; // 0x000FC

  uint8_t padding37[3]; // 0x000FD
  uint8_t padding38[16]; // 0x00100
  uint8_t padding39[16]; // 0x00110
  uint8_t padding40[16]; // 0x00120
  uint8_t padding41[16]; // 0x00130
  uint8_t padding42[16]; // 0x00140
  uint8_t padding43[16]; // 0x00150
  uint8_t padding44[16]; // 0x00160
  uint8_t padding45[16]; // 0x00170

  wcmpr_t wcmpr; // 0x00180

  wcbintr_t wcb1intr; // 0x00181
  wcbintr_t wcb3intr; // 0x00182

  uint8_t padding46[13]; // 0x00183
  uint8_t padding47[16]; // 0x00190
  uint8_t padding48[9]; // 0x001A0

  fst_t fst; // 0x0001A9
  fmr0_t fmr0; // 0x0001AA
  fmr1_t fmr1; // 0x0001AB
  fmr2_t fmr2; // 0x0001AC

  struct { // 0x0001AD
    unsigned int value:6;
    unsigned int reserved0:2;
  } frefr;

  uint8_t padding49[2]; // 0x001AE
  uint8_t padding50[16]; // 0x001B0

  uint16_t aiadr0l; // 0x001C0
  struct { // 0x001C2
    unsigned int value:4;
    unsigned int reserved:4;
  } aiadr0h;

  struct { // 0x001C3
    unsigned int reserved0:7;
    bool is_addr_match_itr_enabled:1;
  } aien0;

  uint16_t aiadr1l; // 0x001C4

  struct { // 0x001C6
    unsigned int value:4;
    unsigned int reserved:4;
  } aiadr1h;

  struct { // 0x001C7
    unsigned int reserved0:7;
    bool is_addr_match_itr_enabled:1;
  } aien1;
} io_t;
#pragma pack()

extern volatile io_t *pIo;
extern volatile ofs2_t *pOfs2;
extern volatile ofs_t *pOfs;

#define IO_START_ADDR 0x10
#define OFS2_ADDR 0xFFDB
#define OFS_ADDR 0xFFFF

