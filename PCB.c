#include"PCB.h"

Status ProcessRun(PCB* process)
{
	if (!process)	return 0;
	process->status = Run;
	//printf("==================%s 被服务...==============\n", process->pname);
	printProcess(process);
	process->server_time += 1;
	return process->nserver_time == process->server_time;
}

void printProcess(PCB* process)
{
	printf("%s  %8d  %12d             %c   %13d    %8d              %3d\n", process->pname, process->priority, process->server_time, process->status,
												 process->arrive_time,process->nserver_time,process->pid);
}


void destroyProcess(PCB* process)
{
	if (!process)	return;
	//printf("%s\n", process->pname);
	if(process->priority < INF) printf("\n%s 已被销毁... 到达时间为: %3d, 结束时间为: %3d, 周转时间为: %3d\n", process->pname, process->arrive_time, process->end_time,process->end_time - process->arrive_time);
	free(process);
}

PCB* createEmptyProcess(const char* pname)
{
	PCB* process = (PCB*)malloc(sizeof(PCB));
	if (!process)	return NULL;
	process->pname = pname, process->priority = INF, process->nserver_time = INF;
	process->next_PCB = NULL, process->server_time = 0, process->arrive_time = 0, process->end_time = 0;
	process->status = PWait;
	process->pid = 0;
	return process;
}