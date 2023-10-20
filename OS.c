#include"OS.h"
void showAllProcess(OS* os)
{
	printf("当前OS中所有的进程:\n");
	printf("进程名   进程优先级   进程已服务时间   进程状态   进程到达时间  进程需要服务时间   内部标识\n");
	for (int i = 1; i <= os->Pcount; i++)
	{
		printProcess(os->dict[i]);
	}
}
void initialize(OS* os, PRIOIOR less)
{
	os->readyQueue = CreateReadyQueue(less);
	os->finishQueue = CreateFinishQueue();
	os->Pcount = 0;
	os->dict = malloc(sizeof(PCB*) * (MAX_PROCESS + 1));
}

PCB* findProcess(OS* os,int pid)
{
	if (os->Pcount < pid) {
		return NULL;
	}
	return os->dict[pid];
}


void end(OS* os)
{
	showAllProcess(os);
	destroyFinishQueue(os->finishQueue);
	destroyReadyQueue(os->readyQueue);
	free(os->dict);
}