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
	//PCB* pri = readyQueue->head_PCB;
	//PCB* pre = readyQueue->head_PCB;
	//while (pcb)
	//{
	//	if (pri->next_PCB->arrive_time > pcb->arrive_time || 
	//		(pri->next_PCB->arrive_time == pcb->arrive_time && pri->next_PCB->nserver_time - pri->next_PCB->server_time > pcb->nserver_time - pcb->server_time)
	//	   )
	//	{
	//		pri = pre;
	//	}
	//	pcb = pcb->next_PCB;
	//	pre = pre->next_PCB;
	//}
	//pcb = pri->next_PCB;
	//pri->next_PCB = pcb->next_PCB;
	//readyQueue->Out = pcb;
	return pcb;
}


PCB* next_process(ready_queue* readyQueue)
{
	PCB* pcb = readyQueue->head_PCB->next_PCB;
	if (!pcb)	return NULL;
	readyQueue->head_PCB->next_PCB = pcb->next_PCB;
	readyQueue->Out = pcb;
	return pcb;
}

Status insert(ready_queue* readyQueue, PCB* pcb)
{
	if (!pcb || !readyQueue)	return fail;
	PCB* nowp = readyQueue->head_PCB;
	int (*f)(PCB*, PCB*) = readyQueue->less;
	while (nowp->next_PCB && f(pcb, nowp->next_PCB))
	{
		nowp = nowp->next_PCB;
	}
	pcb->next_PCB = nowp->next_PCB;
	nowp->next_PCB = pcb;
	pcb->status = Wait;
	return success;
}
Status empty(ready_queue* readyQueue)
{
	return readyQueue->head_PCB->next_PCB == NULL;
}

ready_queue* CreateReadyQueue(PRIOIOR less)
{
	ready_queue* readyQueue = malloc(sizeof(readyQueue) + 20);
	if (!readyQueue)	return NULL;
	readyQueue->less = less;
	readyQueue->head_PCB = createEmptyProcess("Head Node");
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
	printf("=======================================就绪队列=====================================\n");
	printf("进程名   进程优先级   进程已服务时间   进程状态   进程到达时间  进程需要服务时间\n");
	PCB* process = readyQueue->head_PCB->next_PCB;
	if (!process) {
		printf("此时就绪队列为空...等待...\n");
		printf("====================================================================================\n");
		return;
	}
	while (process)
	{
		printProcess(process);
		process = process->next_PCB;
	}
	printf("====================================================================================\n");
}