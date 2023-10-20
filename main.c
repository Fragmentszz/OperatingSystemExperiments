#include"schedule.h"


int FCFS(PCB* a, PCB* b)									//定义优先级低
{
	return a->arrive_time > b->arrive_time ||				//a比b晚到
		(a->arrive_time == b->arrive_time &&				
			a->nserver_time - a->server_time > b->nserver_time - b->server_time);		//或者a和b同时到，但是剩余服务时间a多于b
}
int PSA(PCB* a, PCB* b)
{
	return (a->priority < b->priority ||				//a优先级<b
		(a->priority == b->priority && 
			a->nserver_time - a->server_time > b->nserver_time - b->server_time));	//或者a和b优先级相同，但是剩余服务时间a多于b
}
int main()
{
	OS os;
	srand(time(0));
	initialize(&os,FCFS);
	PCB* p = createProcess("init1", 1 + 1.0*rand() / RAND_MAX*5, 1 + 1.0*rand() / RAND_MAX*3, 0, &os);
	insert(os.readyQueue, p);
	p = createProcess("init2", 1 + 1.0 * rand() / RAND_MAX * 5, 1 + 1.0 * rand() / RAND_MAX * 3, 0, &os);
	insert(os.readyQueue, p);
	for (int i = 2; i >= 1; i--) {
		printf("寻找pid = %d的进程:\n", i);
		PCB* finded = findProcess(&os, i);
		printProcess(finded);
	}
	

	//random_schedule(&os);

	end(&os);
}