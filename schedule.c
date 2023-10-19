#include"schedule.h"
void schedule(ready_queue* readyQueue)
{
	while (1)
	{
		showReadyQueue(readyQueue);
		if (empty(readyQueue))	break;
		PCB* process = next_process_PSA(readyQueue);
		Status status = ProcessRun(process);
		if (status)
		{
			process->status = Finish;
		}
		else
		{
			process->priority += 1;
			insert(readyQueue, process);
		}
	}
}
#define maxsize  1
char test[maxsize + 1][7] = { 0 };
void random_schedule(OS* os,int flag)
{
	ready_queue* readyQueue = os->readyQueue;
	finish_queue* fnsQueue = os->finishQueue;
	int cnt = 0;
	char str[7] = "test0";
	for (int i = 0; i < maxsize; i++)
	{
		str[4] = i+1+'0';
		for (int j = 0; j < 7; j++)
		{
			test[i][j] = str[j];
		}
		printf("%s\n", test[i]);
	}
	srand(time(0));
	int T = 0;
	while (1)
	{
		if (cnt >= maxsize && empty(readyQueue))	break;
		while( cnt < maxsize) {
			double rd = 1.0*rand() / RAND_MAX;
			if (rd < 0.7)	break;
			if (rd >= 0.3) {
				int rd2 = 1 + (1.0 * rand() / RAND_MAX) * 10;
				int rd3 = 1 + (1.0 * rand() / RAND_MAX) * 3;
				PCB* newProcess = createProcess(test[cnt], rd2, rd3,T);
				insert(readyQueue, newProcess);
				cnt++;
			}
		}
		printf("\n\n\n=========当前时间:%5d===========\n", T);
		fflush(stdin);
		fflush(stdout);
		printf("进程名   进程优先级   进程已服务时间   进程状态   进程到达时间  进程需要服务时间\n");
		showReadyQueue(readyQueue);
		PCB* process = NULL;
		if (flag == 1)process = next_process_PSA(readyQueue);
		else if (flag == 2)	process = next_process_FCFS(readyQueue);
		T++;
		if (!process)	continue;
		Status status = ProcessRun(process);
		if (status)
		{
			process->status = Finish;
			process->end_time = T;
			insert_FinishQueue(fnsQueue, process);
		}
		else
		{
			process->priority += 1;
			insert(readyQueue, process);
		}
	}
}
void initialize(OS* os)
{
	os->readyQueue = CreateReadyQueue();
	os->finishQueue = CreateFinishQueue();
}

void end(OS* os)
{
	destroyFinishQueue(os->finishQueue);
	//destroyReadyQueue(os->readyQueue);
}