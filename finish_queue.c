#include"finish_queue.h"

finish_queue* CreateFinishQueue()
{
	finish_queue* fnsQueue = malloc(sizeof(finish_queue));
	if (!fnsQueue)	return NULL;
	fnsQueue->head_PCB = createEmptyProcess("Head Node");
	return fnsQueue;
}

void destroyFinishQueue(finish_queue* fnsQueue)
{
	PCB* process = fnsQueue->head_PCB->next_PCB;
	PCB* p = NULL;
	while (process)
	{
		p = process->next_PCB;
		destroyProcess(process);
		process = p;
	}
	destroyProcess(fnsQueue->head_PCB);
	free(fnsQueue);
}

Status insert_FinishQueue(finish_queue* fnsQueue, PCB* pcb)
{
	if (!pcb || !fnsQueue)	return fail;
	pcb->next_PCB = fnsQueue->head_PCB->next_PCB;
	fnsQueue->head_PCB->next_PCB = pcb;
	pcb->status = Finish;
	return success;
}

void showFinishQueue(finish_queue* Queue)
{
	printf("=======================================完成队列=====================================\n");
	PCB* process = Queue->head_PCB->next_PCB;
	if (!process) {
		printf("此时完成队列为空...没有已完成的进程\n");
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