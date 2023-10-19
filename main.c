#include"schedule.h"


int main()
{
	OS os;
	srand(time(0));
	initialize(&os);
	PCB* p = createProcess("init1", 1 + 1.0*rand() / RAND_MAX*5, 1 + 1.0*rand() / RAND_MAX*3, 0);
	insert(os.readyQueue, p);
	p = createProcess("init2", 1 + 1.0 * rand() / RAND_MAX * 5, 1 + 1.0 * rand() / RAND_MAX * 3, 0);
	insert(os.readyQueue, p);

	random_schedule(&os,1);

	end(&os);
}