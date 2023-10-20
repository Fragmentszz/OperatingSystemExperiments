#pragma once
#include"PCB.h"
typedef int (*PRIOIOR)(PCB*, PCB*);
/// @brief 就绪队列
typedef struct RDQ
{
	PCB* head_PCB;
	PCB* Out;		//被拿出来的process
	PRIOIOR less;	//就绪队列所用的偏序关系
}ready_queue;

PCB* next_process(ready_queue* readyQueue);
Status insert(ready_queue* readyQueue, PCB* pcb);
Status empty(ready_queue* readyQueue);
ready_queue* CreateReadyQueue(PRIOIOR less);
void destroyReadyQueue(ready_queue* readyQueue);
void showReadyQueue(ready_queue*);