#ifndef __LED_H
#define	__LED_H

#include "drv_led.h"



/* �����߳̿��ƿ� */
extern rt_thread_t led0_thread;
extern rt_thread_t led1_thread;
/* �����̺߳������ */
extern void led0_thread_entry(void* parameter);
extern void led1_thread_entry(void* parameter);

/* ����LED�߳� */
extern void run_led(void);







#endif
