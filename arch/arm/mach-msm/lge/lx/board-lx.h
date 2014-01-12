/* Copyright (c) 2012, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __ARCH_ARM_MACH_MSM_BOARD_MSM8960_H
#define __ARCH_ARM_MACH_MSM_BOARD_MSM8960_H

#include <linux/regulator/msm-gpio-regulator.h>
#include <linux/mfd/pm8xxx/pm8921.h>
#include <linux/i2c.h>
#include <linux/i2c/sx150x.h>
#include <mach/irqs.h>
#include <mach/rpm-regulator.h>
#include <mach/msm_memtypes.h>
#include <mach/msm_rtb.h>
#include <mach/msm_cache_dump.h>

/* Macros assume PMIC GPIOs and MPPs start at 1 */
#define PM8921_GPIO_BASE		NR_GPIO_IRQS
#define PM8921_GPIO_PM_TO_SYS(pm_gpio)	(pm_gpio - 1 + PM8921_GPIO_BASE)
#define PM8921_MPP_BASE			(PM8921_GPIO_BASE + PM8921_NR_GPIOS)
#define PM8921_MPP_PM_TO_SYS(pm_gpio)	(pm_gpio - 1 + PM8921_MPP_BASE)
#define PM8921_IRQ_BASE			(NR_MSM_IRQS + NR_GPIO_IRQS)

extern struct pm8xxx_regulator_platform_data
	msm_pm8921_regulator_pdata[] __devinitdata;

extern int msm_pm8921_regulator_pdata_len __devinitdata;

#define GPIO_VREG_ID_EXT_5V		0
#define GPIO_VREG_ID_EXT_L2		1
#define GPIO_VREG_ID_EXT_3P3V		2
#define GPIO_VREG_ID_EXT_OTG_SW		3

extern struct gpio_regulator_platform_data
	msm_gpio_regulator_pdata[] __devinitdata;

extern struct regulator_init_data msm_saw_regulator_pdata_s5;
extern struct regulator_init_data msm_saw_regulator_pdata_s6;

extern struct rpm_regulator_platform_data msm_rpm_regulator_pdata __devinitdata;

#if defined(CONFIG_GPIO_SX150X) || defined(CONFIG_GPIO_SX150X_MODULE)
enum {
	GPIO_EXPANDER_IRQ_BASE = (PM8921_IRQ_BASE + PM8921_NR_IRQS),
	GPIO_EXPANDER_GPIO_BASE = (PM8921_MPP_BASE + PM8921_NR_MPPS),
	/* CAM Expander */
	GPIO_CAM_EXPANDER_BASE = GPIO_EXPANDER_GPIO_BASE,
	GPIO_CAM_GP_STROBE_READY = GPIO_CAM_EXPANDER_BASE,
	GPIO_CAM_GP_AFBUSY,
	GPIO_CAM_GP_STROBE_CE,
	GPIO_CAM_GP_CAM1MP_XCLR,
	GPIO_CAM_GP_CAMIF_RESET_N,
	GPIO_CAM_GP_XMT_FLASH_INT,
	GPIO_CAM_GP_LED_EN1,
	GPIO_CAM_GP_LED_EN2,
	GPIO_LIQUID_EXPANDER_BASE = GPIO_CAM_EXPANDER_BASE + 8,
};
#endif

enum {
	SX150X_CAM,
	SX150X_LIQUID,
};

#endif
/* Camera */
#define GPIO_CAM_MCLK0          (5)
#define GPIO_CAM_MCLK1          (4)
#define GPIO_CAM_VCM_EN_A        (2)
#define GPIO_CAM_VCM_EN         (53)
#define GPIO_CAM_WP_N            (2)
#define GPIO_CAM_DVDD_LDO_EN (43)
#define GPIO_CAM_I2C_SDA        (20)
#define GPIO_CAM_I2C_SCL        (21)
#define GPIO_CAM1_RST_N         (107)
#define GPIO_CAM2_RST_N         (76)
#define GPIO_CAM2_PWRDOWN       (54)
#define GPIO_CAM_FLASH_EN       (1)
#define GPIO_CAM_FLASH_I2C_SDA  (32)
#define GPIO_CAM_FLASH_I2C_SCL  (33)

#define I2C_SLAVE_ADDR_S5K4E1   (0x20)
#define I2C_SLAVE_ADDR_S5K4E1_ACT   (0x18)
#define I2C_SLAVE_ADDR_MT9V113 (0x7A)
#define I2C_SLAVE_ADDR_LM3559    (0x53)
#define I2C_SLAVE_ADDR_IMX119       (0x6E)

#define CAM1_VAF_MINUV          2800000
#define CAM1_VAF_MAXUV          2800000
#define CAM1_VDIG_MINUV         1800000
#define CAM1_VDIG_MAXUV         1800000
#define CAM1_VANA_MINUV         2800000
#define CAM1_VANA_MAXUV         2850000
#define CAM_CSI_VDD_MINUV       1200000
#define CAM_CSI_VDD_MAXUV       1200000

#define CAM1_VAF_LOAD_UA        300000
#define CAM1_VDIG_LOAD_UA       100000
#define CAM1_VANA_LOAD_UA       80000
#define CAM_CSI_LOAD_UA         20000

#ifdef CONFIG_MT9V113
#define CAM2_VIO_MINUV          1800000
#define CAM2_VIO_MAXUV          1800000

#define CAM2_VDIG_MINUV         1800000
#define CAM2_VDIG_MAXUV         1800000

#define CAM2_VANA_MINUV         2800000
#define CAM2_VANA_MAXUV         2850000

#define CAM2_VDIG_LOAD_UA       6400
#define CAM2_VANA_LOAD_UA       85600
#elif defined(CONFIG_IMX119)
/*           
                               
                                  
 */
#define CAM2_VIO_MINUV          1800000
#define CAM2_VIO_MAXUV          1800000

#define CAM2_VDIG_MINUV         1200000
#define CAM2_VDIG_MAXUV         1200000

#define CAM2_VANA_MINUV         2800000
#define CAM2_VANA_MAXUV         2850000

#define CAM2_VDIG_LOAD_UA       105000
#define CAM2_VANA_LOAD_UA       85600
#else
#define CAM2_VIO_MINUV          1800000
#define CAM2_VIO_MAXUV          1800000

#define CAM2_VDIG_MINUV         1800000
#define CAM2_VDIG_MAXUV         1800000

#define CAM2_VANA_MINUV         2800000
#define CAM2_VANA_MAXUV         2850000

#define CAM2_VDIG_LOAD_UA       6400
#define CAM2_VANA_LOAD_UA       85600

#endif

extern struct sx150x_platform_data msm8960_sx150x_data[];
extern struct msm_camera_board_info msm8960_camera_board_info;

void msm8960_init_cam(void);
void msm8960_init_fb(void);
void msm8960_init_pmic(void);
void msm8960_init_mmc(void);
int msm8960_init_gpiomux(void);
unsigned char msm8960_hdmi_as_primary_selected(void);
void msm8960_allocate_fb_region(void);
void msm8960_set_display_params(char *prim_panel, char *ext_panel);
void msm8960_pm8921_gpio_mpp_init(void);
void msm8960_mdp_writeback(struct memtype_reserve *reserve_table);
#define MSM_8960_GSBI4_QUP_I2C_BUS_ID 4
#define MSM_8960_GSBI3_QUP_I2C_BUS_ID 3
#define MSM_8960_GSBI10_QUP_I2C_BUS_ID 10

extern struct msm_rtb_platform_data msm8960_rtb_pdata;
extern struct msm_cache_dump_platform_data msm8960_cache_dump_pdata;
