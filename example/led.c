/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    led.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    06/09 2021 14:10
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        06/09 2021      create the file
 * 
 *     last modified: 06/09 2021 14:10
 */
#include <stdio.h>

#include "config.h"

#include "hy_hal/hy_gpio.h"

static void _delay(void)
{
    for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < 10000; ++j) {
        }
    }
}

int main(int argc, char *argv[])
{
#ifdef HAVE_SELECT_MCU_AT32F4XX
    HyGpio_t gpio;
    gpio.group  = HY_GPIO_GROUP_PD;
    gpio.pin    = HY_GPIO_PIN_13;
#endif

#ifdef HAVE_SELECT_MCU_HC32F003
    HyGpio_t gpio;
    gpio.group  = HY_GPIO_GROUP_PC;
    gpio.pin    = HY_GPIO_PIN_6;
#endif

    HyGpioSetOutput(&gpio, HY_GPIO_LEVEL_LOW);

    while (1) {
        HyGpioSetLevel(&gpio, HY_GPIO_LEVEL_HIGH);
        _delay();

        HyGpioSetLevel(&gpio, HY_GPIO_LEVEL_LOW);
        _delay();
    }

    return 0;
}
