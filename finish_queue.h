#pragma once
#include"PCB.h"
/// @brief 完成队列
typedef struct
{
	PCB* head_PCB;		//头节点
}finish_queue;

finish_queue* CreateFinishQueue();
Status insert_FinishQueue(finish_queue* fnsQueue, PCB* pcb);

void destroyFinishQueue(finish_queue* fnsQueue);

void showFinishQueue(finish_queue* Queue);