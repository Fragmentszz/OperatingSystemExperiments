#include"ready_queue.h"
PCB* next_process_PSA(ready_queue* readyQueue)
{
	PCB* pcb = readyQueue->head_PCB->next_PCB;
	if (!pcb)	return NULL;
	PCB* pri = readyQueue->head_PCB;
	PCB* pre = readyQueue->head_PCB;
	while (pcb)
	{
		if (pri->next_PCB->priority < pcb->priority || 
			(pri->next_PCB->priority == pcb->priority && pri->next_PCB->nserver_time - pri->next_PCB->server_time  > pcb->nserver_time - pcb->server_time))
		{
			pri = pre;
		}
		pcb = pcb->next_PCB;
		pre = pre->next_PCB;
	}
	pcb = pri->next_PCB;
	pri->next_PCB = pcb->next_PCB;
	readyQueue->Out = pcb;
	return pcb;
}

PCB* next_process_FCFS(ready_queue* readyQueue)
{
	PCB* pcb = readyQueue->head_PCB->next_PCB;
	if (!pcb)	return NULL;
	PCB* pri = readyQueue->head_PCB;
	PCB* pre = readyQueue->head_PCB;
	while (pcb)
	{
		if (pri->next_PCB->start_time > pcb->start_time || 
			(pri->next_PCB->start_time == pcb->start_time && pri->next_PCB->nserver_time - pri->next_PCB->server_time > pcb->nserver_time - pcb->server_time)
		   )
		{
			pri = pre;
		}
		pcb = pcb->next_PCB;
		pre = pre->next_PCB;
	}
	pcb = pri->next_PCB;
	pri->next_PCB = pcb->next_PCB;
	readyQueue->Out = pcb;
	return pcb;
}


Status insert(ready_queue* readyQueue, PCB* pcb)
{
	if (!pcb || !readyQueue)	return fail;
	pcb->next_PCB = readyQueue->head_PCB->next_PCB;
	readyQueue->head_PCB->next_PCB = pcb;
	pcb->status = Wait;
	return success;
}
Status empty(ready_queue* readyQueue)
{
	return readyQueue->head_PCB->next_PCB == NULL;
}

ready_queue* CreateReadyQueue()
{
	ready_queue* readyQueue = malloc(sizeof(readyQueue));
	if (!readyQueue)	return NULL;
	readyQueue->head_PCB = createProcess("Head Node", -1, 0,0);
	return readyQueue;
}

void destroyReadyQueue(ready_queue* readyQueue)
{
	if (!readyQueue)	return;
	destroyProcess(readyQueue->head_PCB);
	free(readyQueue);
}

void showReadyQueue(ready_queue* readyQueue)
{
	PCB* process = readyQueue->head_PCB->next_PCB;
	if (!process) {
		printf("此时就绪队列为空...等待...\n");
		return;
	}
	//printf("=========就绪队列==============\n");
	while (process)
	{
		printProcess(process);
		process = process->next_PCB;
	}
}