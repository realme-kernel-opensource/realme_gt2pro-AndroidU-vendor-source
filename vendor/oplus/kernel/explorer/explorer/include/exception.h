/*
 * Copyright (c) 2021 ZEKU Technology(Shanghai) Corp.,Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * Basecode Created :        2020/10/11 Author: wt@zeku.com
 *
 */

#ifndef _EXPLORER_EXCEPTION_H
#define _EXPLORER_EXCEPTION_H

#define EXCEPTION_LOG_E(fmt, ...) pr_err("[ExplorerException] %s(%d) "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define EXCEPTION_LOG_I(fmt, ...) pr_info("[ExplorerException] %s(%d) "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define EXCEPTION_LOG_W(fmt, ...) pr_warn("[ExplorerException] %s(%d) "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define HAL_CMD_RTT_RAMINFO 3002
#define HAL_CMD_EXCEPTION2AP 3003

#define AP_CTRL_REG1_SDU 0x801
#define AP_CTRL_REG8_SDU 0x808
#define AP_STAT_REG3_SDU 0x813
#define AP_STAT_REG4_SDU 0x814
#define AP_STAT_REG5_SDU 0x815
#define AP_STAT_REG6_SDU 0x816
#define AP_STAT_REG7_SDU 0x817

#define AHB_PORT_SDIO (0x1 << 2)
#define AHB_PORT_MPU (0x1 << 3)
#define AHB_PORT_LSAPB (0x1 << 11)

#define INT_BUS_MONITOR	(0x1)
#define INT_WDT         (0x1 << 3)

#define AP_CTRL_REG0_SDU 0x800

#define SDI_DO_EXIT_DDRLP2	(0x1)

#define AP_CTRL_REG5_SDU 0x805
#define AP_RST_CPUCORE (0x1 << 1)

#define EXCEPTION_MASK	0xFF
#define EXCEPTION_MAJORTYPE_SHIF	8
#define EXCEPTION_SUBTYPE_SHIF	16
#define EXCEPTION_MASK_ACT	0xF
#define EXCEPTION_ACTION_SHIF	24
#define EXCEPTION_MASK_LVL	0xF
#define EXCEPTION_LEVEL_SHIF	28

#define EXCEPTION_ALL	0xFF

#define MIN_MATCH	1
#define MID_MATCH	2
#define BEST_MATCH	3

#define EXCEPTION_SDIO_DEBUG

enum EXCEPTION_MODULE_ID {
	EXCEPTION_NONE = 0,
	EXCEPTION_ISP,
	EXCEPTION_NPU,
	EXCEPTION_PMIC,
	EXCEPTION_PVT,
	EXCEPTION_CPU,
	EXCEPTION_SE,
	EXCEPTION_WDT,
	EXCEPTION_BUS,
	EXCEPTION_SDIO,
	EXCEPTION_POWER,
	EXCEPTION_BOOT,
	EXCEPTION_MIPI,
	EXCEPTION_THERMAL,
	EXCEPTION_DDR,
	EXCEPTION_MAX_MODULE,
};

enum EXCEPTION_POWER_MAJOR_TYPE {
	EXCEPTION_POWER_MAJOR_TYPE_POWER_ON_OFF = 0,
	EXCEPTION_POWER_MAJOR_TYPE_SUSPEND_RESUME,
	EXCEPTION_POWER_MAJOR_TYPE_POWER_STATE,
	EXCEPTION_POWER_MAJOR_TYPE_PMIC_HW_ERR,
	EXCEPTION_POWER_MAJOR_TYPE_UNEXPECTED_STATE,
};

enum EXCEPTION_BOOT_MAJOR_TYPE {
	MAJOR_TYPE_STAGE = 0,
	MAJOR_TYPE_ERROR,
};

enum EXCEPTION_BOOT_ERROR_SUB_TYPE {
	ERROR_TYPE_TIMEOUT = 0,
	ERROR_TYPE_ARGUMENT,
};

enum EXCEPTION_BOOT_STAGE_SUB_TYPE {
	STAGE_TYPE_START = 0,
	STAGE_TYPE_DDR_OK,
	STAGE_TYPE_RTOS_VERIFIED,
	STAGE_TYPE_RTOS_RUN,
	STAGE_TYPE_NPU_DONE,
};

enum EXCEPTION_POWER_SUB_TYPE {
	EXCEPTION_POWER_SUB_TYPE_WAKEUP_FAIL = 0,
	EXCEPTION_POWER_SUB_TYPE_SLEEP_FAIL = 1,
	EXCEPTION_POWER_SUB_TYPE_PMIC_HW_ERR_BY_HEARTBEAT = 2,
	EXCEPTION_POWER_SUB_TYPE_PMIC_HW_ERR_BY_PBL_DETECT = 3,
	EXCEPTION_POWER_SUB_TYPE_PMIC_HW_ERR_BY_BOOT_TIMEOUT = 4,
	EXCEPTION_POWER_SUB_TYPE_EXPLORER_SUSPEND = 5,
};

enum EXCEPTION_PVT_MAJOR_TYPE {
	EXCEPTION_TS_00 = 0,
	EXCEPTION_TS_01,
	EXCEPTION_TS_02,
	EXCEPTION_PD_00,
	EXCEPTION_PD_01,
	EXCEPTION_PD_02,
	EXCEPTION_PD_03,
	EXCEPTION_PD_04,
	EXCEPTION_PD_05,
	EXCEPTION_PD_06,
	EXCEPTION_PD_07,
	EXCEPTION_PD_08,
	EXCEPTION_PD_09,
	EXCEPTION_PD_10,
	EXCEPTION_VM_00,
	EXCEPTION_VM_01,
	EXCEPTION_VM_02,
	EXCEPTION_VM_03,
	EXCEPTION_VM_04,
	EXCEPTION_VM_05,
	EXCEPTION_VM_06,
	EXCEPTION_VM_07,
	EXCEPTION_VM_08,
	EXCEPTION_VM_09,
	EXCEPTION_VM_10,
	EXCEPTION_VM_11,
	EXCEPTION_VM_12,
	EXCEPTION_VM_13,
	EXCEPTION_VM_14,
	EXCEPTION_VM_15,
	EXCEPTION_PVT_MAX,
};

enum EXCEPTION_PVT_SUB_TYPE {
	EXCEPTION_PVT_FAULT = 0,
	EXCEPTION_PVT_ALARMA,
	EXCEPTION_PVT_ALARMB,
};

#ifdef EXCEPTION_SDIO_DEBUG
enum EXCEPTION_SDIO_MAJOR_TYPE {
	EXCEPTION_SDIO_CMD52_ERR,
	EXCEPTION_SDIO_CMD53_ERR,
	EXCEPTION_SDIO_DEV_ERR,
};

enum EXCEPTION_SDIO_SUB_TYPE {
	EXCEPTION_SDIO_TIMEOUT_RECOVERABLE,
	EXCEPTION_SDIO_TIMEOUT,
	EXCEPTION_SDIO_CRC_ERR_RECOVERABLE,
	EXCEPTION_SDIO_CRC_ERR,
	EXCEPTION_SDIO_RECOVER_ERR,
	EXCEPTION_SDIO_ELSE_ERR,
};
#endif

enum EXCEPTION_DDR_MAJOR_TYPE {
	EXCEPTION_DDR_INIT_FAIL,
	EXCEPTION_DDR_DFS_FAIL,
	EXCEPTION_DDR_TEMP_LIMIT,
};

#define BUSHANG 1
#define EXCEPTION_WDT_BITE 2

enum EXCEPTION_ACTION {
	EXCEPTION_ACT_NONE = 0,
	EXCEPTION_ACT_POWROFF,
	EXCEPTION_ACT_RESET,
	EXCEPTION_ACT_MIPIBYPASS,
	EXCEPTION_ACT_MAX,
};

enum EXCEPTION_LEVEL {
    EXCEPTION_NOTICE,
    EXCEPTION_WARNING,
    EXCEPTION_ERROR,
    EXCEPTION_FATAL,
    EXCEPTION_MAX_LEVEL,
};

struct exception_info{
	uint8_t	moduleId;
	uint8_t majorType;
	uint8_t subType;
	uint8_t level;
	enum EXCEPTION_ACTION action;
};

typedef int (*exception_func_type)(struct explorer_plat_data *epd, struct exception_info *info);

typedef struct {
	struct exception_info info;
	exception_func_type handle;
}exception_handle_table_entry;

typedef struct {
	u32 dump_addr;
	u32 dump_len;
}dump_info;

int explorer_exception_msg(struct explorer_plat_data *epd, struct hal_comm_data *comm_data);
int exception_handle_func(struct explorer_plat_data *epd, struct exception_info *info);
int explorer_bus_hang_irq_handler(struct explorer_plat_data *epd);
int explorer_wdt_bite_irq_handler(struct explorer_plat_data *epd);
#endif
