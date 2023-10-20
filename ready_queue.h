#pragma once
#include"PCB.h"
typedef int (*PRIOIOR)(PCB*, PCB*);
/// @brief ��������
typedef struct RDQ
{
	PCB* head_PCB;
	PCB* Out;		//���ó�����process
	PRIOIOR less;	//�����������õ�ƫ���ϵ
}ready_queue;

PCB* next_process(ready_queue* readyQueue);
Status insert(ready_queue* readyQueue, PCB* pcb);
Status empty(ready_queue* readyQueue);
ready_queue* CreateReadyQueue(PRIOIOR less);
void destroyReadyQueue(ready_queue* readyQueue);
void showReadyQueue(ready_queue*);