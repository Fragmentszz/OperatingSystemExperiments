#pragma once
#include"PCB.h"

typedef struct
{
	PCB* head_PCB;
}finish_queue;

finish_queue* CreateFinishQueue();
Status insert_FinishQueue(finish_queue* fnsQueue, PCB* pcb);

void destroyFinishQueue(finish_queue* fnsQueue);

void showFinishQueue(finish_queue* Queue);