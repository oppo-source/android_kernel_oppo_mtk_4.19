/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
*/

#ifndef __MT_EMI_ELM_H__
#define __MT_EMI_ELM_H__

#define ENABLE_ELM	1

#define EMI_LTCT0_2ND	(CEN_EMI_BASE + 0x750)
#define EMI_LTCT1_2ND	(CEN_EMI_BASE + 0x754)
#define EMI_LTCT2_2ND	(CEN_EMI_BASE + 0x758)
#define EMI_LTCT3_2ND	(CEN_EMI_BASE + 0x75C)
#define EMI_LTST0_2ND	(CEN_EMI_BASE + 0x760)
#define EMI_LTST1_2ND	(CEN_EMI_BASE + 0x764)
#define EMI_LTST2_2ND	(CEN_EMI_BASE + 0x768)
#define EMI_CGMA	(CEN_EMI_BASE + 0x720)
#define EMI_CGMA_ST0	(CEN_EMI_BASE + 0x724)
#define EMI_CGMA_ST1	(CEN_EMI_BASE + 0x728)
#define EMI_CGMA_ST2	(CEN_EMI_BASE + 0x72C)
#define EMI_EBMINT_ST	(CEN_EMI_BASE + 0x744)

#define LT_CMD_THR_VAL 100

extern int elm_init(unsigned int elm_irq);
extern void elm_dump(char *buf, unsigned int leng);
extern void enable_elm(void);
extern void disable_elm(void);
extern void suspend_elm(void);
extern void resume_elm(void);
extern bool is_elm_enabled(void);

#endif  /* !__MT_EMI_BW_ELM_H__ */
