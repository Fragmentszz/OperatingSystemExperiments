#include"schedule.h"


int FCFS(PCB* a, PCB* b)									//�������ȼ���
{
	return a->arrive_time > b->arrive_time ||				//a��b��
		(a->arrive_time == b->arrive_time &&				
			a->nserver_time - a->server_time > b->nserver_time - b->server_time);		//����a��bͬʱ��������ʣ�����ʱ��a����b
}
int PSA(PCB* a, PCB* b)
{
	return (a->priority < b->priority ||				//a���ȼ�<b
		(a->priority == b->priority && 
			a->nserver_time - a->server_time > b->nserver_time - b->server_time));	//����a��b���ȼ���ͬ������ʣ�����ʱ��a����b
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
		printf("Ѱ��pid = %d�Ľ���:\n", i);
		PCB* finded = findProcess(&os, i);
		printProcess(finded);
	}
	

	//random_schedule(&os);

	end(&os);
}