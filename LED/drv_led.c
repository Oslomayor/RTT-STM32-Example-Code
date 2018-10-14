#include "drv_led.h"
#include "stm32f4xx_hal_gpio.h"


void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitTypeStruct;
	GPIO_InitTypeStruct.Pin = LED0|LED1;
	GPIO_InitTypeStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitTypeStruct.Speed = GPIO_SPEED_FREQ_LOW;
	
	__HAL_RCC_GPIOF_CLK_ENABLE();
	HAL_GPIO_Init(GPIOF,&GPIO_InitTypeStruct);
	HAL_GPIO_WritePin(GPIOF,LED0|LED1,GPIO_PIN_RESET);
	
	
}

void led_on(uint16_t LEDs)
{
	HAL_GPIO_WritePin(GPIOF,LEDs,GPIO_PIN_RESET);
}

void led_off(uint16_t LEDs)
{
	HAL_GPIO_WritePin(GPIOF,LEDs,GPIO_PIN_SET);
}