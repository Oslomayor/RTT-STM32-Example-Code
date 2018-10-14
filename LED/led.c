#include "led.h"

/* �����߳̿��ƿ� */
rt_thread_t led0_thread;
rt_thread_t led1_thread;

/* �����̺߳������ */
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
/* ����LED�߳� */
void run_led(void)
{
	led0_thread = rt_thread_create(
		"led0",             /* �߳����� */
		led0_thread_entry,  /* �߳���ں��� */
		RT_NULL,            /* �߳���ڲ��� */
		512,                /* �߳�ջ��С */
		3,                  /* �߳����ȼ� */
		20                  /* �߳�ʱ��Ƭ  */
	);
	if(led0_thread != RT_NULL)
		rt_thread_startup(led0_thread);
	led1_thread = rt_thread_create(
		"led1",             /* �߳����� */
		led1_thread_entry,  /* �߳���ں��� */
		RT_NULL,            /* �߳���ڲ��� */
		512,                /* �߳�ջ��С */
		3,                  /* �߳����ȼ� */
		20                  /* �߳�ʱ��Ƭ  */
	);
	if(led1_thread != RT_NULL)
		rt_thread_startup(led1_thread);
	
}
