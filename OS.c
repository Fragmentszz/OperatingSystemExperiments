#include"OS.h"
void showAllProcess(OS* os)
{
	printf("��ǰOS�����еĽ���:\n");
	printf("������   �������ȼ�   �����ѷ���ʱ��   ����״̬   ���̵���ʱ��  ������Ҫ����ʱ��   �ڲ���ʶ\n");
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