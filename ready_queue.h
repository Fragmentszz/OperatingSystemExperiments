#pragma once
#include"PCB.h"

typedef struct 
{
	PCB* head_PCB;
	PCB* Out;		//被拿出来的process
}ready_queue;

PCB* next_process_PSA(ready_queue* readyQueue);
PCB* next_process_FCFS(ready_queue* readyQueue);
Status insert(ready_queue* readyQueue, PCB* pcb);
Status empty(ready_queue* readyQueue);

ready_queue* CreateReadyQueue();

void destroyReadyQueue(ready_queue* readyQueue);

void showReadyQueue(ready_queue*);