/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
*/

#ifndef __DISP_DRV_PLATFORM_H__
#define __DISP_DRV_PLATFORM_H__

#include <linux/dma-mapping.h>
/* #include "mt-plat/mtk_gpio.h" */
#include "m4u.h"
/* #include <mach/mt_reg_base.h> */
#ifdef CONFIG_MTK_CLKMGR
#include <mach/mtk_clkmgr.h>
#endif
/* #include <mach/mt_irq.h> */
#include "mt-plat/sync_write.h"
#include "disp_assert_layer.h"

#include "ddp_hal.h"
#include "ddp_drv.h"
#include "ddp_path.h"

/* #include <mach/mt6585_pwm.h> */
/* #include <mach/boot.h> */

#define ALIGN_TO(x, n)  (((x) + ((n) - 1)) & ~((n) - 1))

#if defined(CONFIG_FPGA_EARLY_PORTING) || !defined(CONFIG_MTK_GPU_SUPPORT)
#define MTK_FB_ALIGNMENT 1 /* SW 3D */
#else
#define MTK_FB_ALIGNMENT 32 /* HW 3D */
#endif

/* Wrap SPM/MMDVFS code for early porting */
#define MTK_FB_SPM_SUPPORT
#define MTK_FB_MMDVFS_SUPPORT
/* #define DISP_SYNC_ENABLE */
#define MTK_FB_ION_SUPPORT
#define VIDEO_LAYER_COUNT (3)
/* #define HW_OVERLAY_COUNT                  (4) */
/*be careful, change ovl config arry size at same time*/
#ifndef CONFIG_MTK_ROUND_CORNER_SUPPORT
#define PRIMARY_SESSION_INPUT_LAYER_COUNT (7) /* phy(4+2) + ext(3+3) */
#else
#define PRIMARY_SESSION_INPUT_LAYER_COUNT (5) /* phy(4+2) + ext(3+3) */
#endif
/* 2 is enough, no need ext layer */
#define EXTERNAL_SESSION_INPUT_LAYER_COUNT	(0)
/* 2 is enough, no need ext layer */
#define MEMORY_SESSION_INPUT_LAYER_COUNT	(1)
#define DISP_SESSION_OVL_TIMELINE_ID(x) (x)

/* Display HW Capabilities */
#define DISP_HW_MODE_CAP DISP_OUTPUT_CAP_SWITCHABLE
#define DISP_HW_PASS_MODE DISP_OUTPUT_CAP_SINGLE_PASS
#define DISP_HW_MAX_LAYER 4

enum DISP_SESSION_ENUM {
	DISP_SESSION_OUTPUT_TIMELINE_ID = PRIMARY_SESSION_INPUT_LAYER_COUNT,
	DISP_SESSION_PRESENT_TIMELINE_ID,
	DISP_SESSION_OUTPUT_INTERFACE_TIMELINE_ID,
	DISP_SESSION_TIMELINE_COUNT,
};

#define MAX_SESSION_COUNT 5

#define FBCONFIG_SHOULD_KICK_IDLEMGR

/* Other platform-dependent features */
#define DISP_PATH_DELAYED_TRIGGER_33ms_SUPPORT
/*#define DISP_PLATFORM_HAS_SHADOW_REG*/

#endif /* __DISP_DRV_PLATFORM_H__ */
