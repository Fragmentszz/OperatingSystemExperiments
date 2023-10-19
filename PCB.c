#include"PCB.h"

Status ProcessRun(PCB* process)
{
	if (!process)	return 0;
	printf("==================%s 被服务...==============\n", process->pid);
	process->server_time += 1;
	return process->nserver_time == process->server_time;
}

void printProcess(PCB* process)
{
	printf("%s  %8d  %12d             %c   %13d    %8d\n", process->pid, process->priority, process->server_time, process->status,
												 process->start_time,process->nserver_time);
}

PCB* createProcess(const char* pid, int priority, TimeSlice server_time,Time start)
{
	PCB* process = (PCB*)malloc(sizeof(PCB));
	if (!process)	return NULL;
	process->pid = pid, process->priority = priority, process->nserver_time = server_time;
	process->next_PCB = NULL, process->server_time = 0, process->start_time = start, process->end_time = 0;
	process->status = PWait;
	return process;
}
void destroyProcess(PCB* process)
{
	if (!process)	return;
	//printf("%s\n", process->pid);
	if(process->priority != -1) printf("\n%s 已被销毁... 到达时间为: %3d, 结束时间为: %3d, 周转时间为: %3d\n", process->pid, process->start_time, process->end_time,process->end_time - process->start_time);
	free(process);
}