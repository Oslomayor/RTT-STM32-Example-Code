#include "led.h"

/* 定义线程控制块 */
rt_thread_t led0_thread;
rt_thread_t led1_thread;

/* 定义线程函数入口 */
void led0_thread_entry(void* parameter)
{
	while(1){
		led_on(LED0);
		rt_thread_delay(50);
		led_off(LED0);
		rt_thread_delay(50);
	}
}
void led1_thread_entry(void* parameter)
{
	while(1){
		led_on(LED1);
		rt_thread_delay(50);
		led_off(LED1);
		rt_thread_delay(50);
	}
}
/* 运行LED线程 */
void run_led(void)
{
	led0_thread = rt_thread_create(
		"led0",             /* 线程名称 */
		led0_thread_entry,  /* 线程入口函数 */
		RT_NULL,            /* 线程入口参数 */
		512,                /* 线程栈大小 */
		3,                  /* 线程优先级 */
		20                  /* 线程时间片  */
	);
	if(led0_thread != RT_NULL)  /* 若创建线程成功，则运行线程 */
		rt_thread_startup(led0_thread);  
	
	led1_thread = rt_thread_create(
		"led1",             /* 线程名称 */
		led1_thread_entry,  /* 线程入口函数 */
		RT_NULL,            /* 线程入口参数 */
		512,                /* 线程栈大小 */
		3,                  /* 线程优先级 */
		20                  /* 线程时间片  */
	);
	if(led1_thread != RT_NULL)  /* 若创建线程成功，则运行线程 */
		rt_thread_startup(led1_thread);
	
}
