//+------------------------------------------------------------------------------------------------+
//| SMC peripheral registers for Kinetis MKL26 MCU.                                                |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MKL26_SMC_H_
#define MKL26_SMC_H_

#include <stdint.h>

struct SMC_type {
  uint8_t PMPROT;     //Power mode protection register
  uint8_t PMCTRL;     //Power mode control register
  uint8_t STOPCTRL;   //Stop control register
  uint8_t PMSTAT;     //Power mode status register
};

#define SMC ((volatile struct SMC_type *) 0x4007E000)

//Power mode protection register bitfields
#define SMC_PMPROT_AVLLS_Disallowed   (0 << 1)  //Allow very-low-leakage stop mode
#define SMC_PMPROT_AVLLS_Allowed      (1 << 1)
#define SMC_PMPROT_ALLS_Disallowed    (0 << 3)  //Allow low-leakage stop mode
#define SMC_PMPROT_ALLS_Allowed       (1 << 3)
#define SMC_PMPROT_AVLP_Disallowed    (0 << 5)  //Allow very-low-power modes
#define SMC_PMPROT_AVLP_Allowed       (1 << 5)

//Power mode control register bitfields
#define SMC_PMCTRL_STOPM_STOP     (0 << 0)  //Stop mode control
#define SMC_PMCTRL_STOPM_VLPS     (2 << 0)
#define SMC_PMCTRL_STOPM_LLS      (3 << 0)
#define SMC_PMCTRL_STOPM_VLLSx    (4 << 0)
#define SMC_PMCTRL_STOPA_Success  (0 << 3)  //Stop aborted
#define SMC_PMCTRL_STOPA_Aborted  (1 << 3)
#define SMC_PMCTRL_RUNM_RUN       (0 << 5)  //Run mode control
#define SMC_PMCTRL_RUNM_VLPR      (2 << 5)

//Stop control register bitfields
#define SMC_STOPCTRL_VLLSM_VLLS0      (0 << 0)  //VLLS mode control
#define SMC_STOPCTRL_VLLSM_VLLS1      (1 << 0)
#define SMC_STOPCTRL_VLLSM_VLLS3      (3 << 0)
#define SMC_STOPCTRL_PORPO_Enabled    (0 << 5)  //POR power option
#define SMC_STOPCTRL_PORPO_Disabled   (1 << 5)
#define SMC_STOPCTRL_PSTOPO_STOP      (0 << 6)  //Partial stop option
#define SMC_STOPCTRL_PSTOPO_PSTOP1    (1 << 6)
#define SMC_STOPCTRL_PSTOPO_PSTOP2    (2 << 6)

//Power mode status register bitfields
#define SMC_PMSTAT_RUN    (1 << 0)  //Power mode status
#define SMC_PMSTAT_STOP   (1 << 1)
#define SMC_PMSTAT_VLPR   (1 << 2)
#define SMC_PMSTAT_VLPW   (1 << 3)
#define SMC_PMSTAT_VLPS   (1 << 4)
#define SMC_PMSTAT_LLS    (1 << 5)
#define SMC_PMSTAT_VLLS   (1 << 6)

#endif //MKL26_SMC_H_
