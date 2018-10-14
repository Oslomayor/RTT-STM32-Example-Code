#ifndef __DRV_LED_H
#define	__DRV_LED_H

#include "stm32f4xx.h"
#include "stm32f4xx_hal_def.h"

#define LED0 GPIO_PIN_9
#define LED1 GPIO_PIN_10







extern void led_init(void);
extern void led_on(uint16_t LEDs);
extern void led_off(uint16_t LEDs);



#endif /* __LED_H */
