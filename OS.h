#pragma once
#include"PCB.h"
#include"ready_queue.h"
#include"finish_queue.h"
#define MAX_PROCESS 50
typedef struct
{
	PCB** dict;						//����ڲ���־�����Ա�
	ready_queue* readyQueue;		//��������
	finish_queue* finishQueue;		//��ɶ���
	int Pcount;						//��������
}OS;

PCB* findProcess(OS* os,int pid);
/// @brief ��ʼ��os
/// @param os OS��ַ
/// @param less �������в��õĵ����㷨��Ӧ��ƫ���ϵ
void initialize(OS* os, PRIOIOR less);
void showAllProcess(OS* os);

void end(OS* os);