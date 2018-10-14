#ifndef __LED_H
#define	__LED_H

#include "drv_led.h"



/* 定义线程控制块 */
extern rt_thread_t led0_thread;
extern rt_thread_t led1_thread;
/* 定义线程函数入口 */
extern void led0_thread_entry(void* parameter);
extern void led1_thread_entry(void* parameter);

/* 运行LED线程 */
extern void run_led(void);







#endif
