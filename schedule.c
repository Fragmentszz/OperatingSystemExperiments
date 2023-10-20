#include"schedule.h"




PCB* createProcess(const char* pname, int priority, TimeSlice server_time, Time start, OS* os)
{
	PCB* process = (PCB*)malloc(sizeof(PCB));
	if (!process)	return NULL;
	process->pname = pname, process->priority = priority, process->nserver_time = server_time;
	process->next_PCB = NULL, process->server_time = 0, process->arrive_time = start, process->end_time = 0;
	process->status = PWait;
	if (os) {
		process->pid = ++os->Pcount;
		os->dict[os->Pcount] = process;
	}
	else {
		process->pid = 0;
	}
	return process;
}



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
void random_schedule(OS* os)
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
		printf("!!!!!!!!!!!!!!!!!!当前时间:%d-!!!!!!!!!!!!!!!!!!\n", T);
		while(T && cnt < maxsize) {
			double rd = 1.0*rand() / RAND_MAX;
			if (rd < 0.7)	break;
			if (rd >= 0.5) {
				int rd2 = 1 + (1.0 * rand() / RAND_MAX) * 10;
				int rd3 = 1 + (1.0 * rand() / RAND_MAX) * 3;
				PCB* newProcess = createProcess(test[cnt], rd2, rd3,T, os);
				insert(readyQueue, newProcess);
				cnt++;
			}
		}
		showReadyQueue(readyQueue);
		showFinishQueue(fnsQueue);
		printf("\n");
		printf("!!!!!!!!!!!!!!!!!!当前时间:%d+!!!!!!!!!!!!!!!!!!\n",T);
		PCB* process = process = next_process(readyQueue);
		T++;
		showReadyQueue(readyQueue);
		showFinishQueue(fnsQueue);
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
			process->priority -= 1;
			insert(readyQueue, process);
		}
	}
}
