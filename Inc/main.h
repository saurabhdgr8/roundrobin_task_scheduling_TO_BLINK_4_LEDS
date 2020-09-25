/*
 * main.h
 *
 *  Created on: Sep 24, 2020
 *      Author: saurabh
 */

#ifndef MAIN_H_
#define MAIN_H_

// reserve stacks for tasks define th boundaries
#define SIZE_TASK_STACK   1024U
#define SIZE_SCHED_STACK  1024U
#define SRAM_START 0X20000000
#define SIZE_SRAM  (128 * 1024)
#define SRAM_END  ((SRAM_START) + (SIZE_SRAM))
#define T1_STACK_START  ((SRAM_END) )
#define T2_STACK_START  ((SRAM_END) - (1 * SIZE_TASK_STACK))
#define T3_STACK_START  ((SRAM_END) - (2 * SIZE_TASK_STACK))
#define T4_STACK_START  ((SRAM_END) - (3 * SIZE_TASK_STACK))
#define IDLE_STACK_START ((SRAM_END) - (4 * SIZE_TASK_STACK))
#define SCHED_STACK_START ((SRAM_END) - (5 * SIZE_TASK_STACK))

#define TICK_HZ 1000U
#define HSI_CLOCK 16000000
#define SYSTEM_TICK_CLK HSI_CLOCK


#define MAX_TASKS 5
#define DUMMY_XPSR 0x01000000

#define TASK_RUNNING_STATE 0x00
#define TASK_BLOCKED_STATE 0xff

#define INTERRUPT_DISABLE() do{__asm volatile("MOV R0,#0x01");__asm volatile("MSR PRIMASK , R0");}while(0)
#define INTERRUPT_ENABLE() do{__asm volatile("MOV R0,#0x00");__asm volatile("MSR PRIMASK , R0");}while(0)

#endif /* MAIN_H_ */
