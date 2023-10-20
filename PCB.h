#pragma once
#include"_basic.h"
/// @brief PCB���ݽṹ
typedef struct OSPCB{
	const char* pname;			//���̱�ʶ��
	int pid;					//�ڲ���ʶ��
	int priority;				//�������ȼ�
	Time arrive_time, end_time;	//����ʱ�䣬����ʱ��
	TimeSlice server_time;		//�ѱ�����ʱ��
	TimeSlice nserver_time;		//��Ҫ������ʱ��
	ProcessStatus status;		//����״̬
	struct OSPCB* next_PCB;		//��һ��PCB��ַ
} PCB;

Status ProcessRun(PCB* process);
void printProcess(PCB* process);

void destroyProcess(PCB* process);

PCB* createEmptyProcess(const char*);