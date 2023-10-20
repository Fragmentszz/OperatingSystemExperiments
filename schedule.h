#pragma once
#include"OS.h"


void schedule(ready_queue* readyQueue);
/// @brief ��os�д���һ������
/// @param pname ��������
/// @param priority ���̳�ʼ���ȼ�
/// @param server_time ��������Ҫ�ķ���ʱ��Ƭ
/// @param arrive ���̴ﵽʱ��
/// @param os OS
/// @return PCBָ��
PCB* createProcess(const char* pname, int priority, TimeSlice server_time, Time arrive, OS* os);

void random_schedule(OS* os);

