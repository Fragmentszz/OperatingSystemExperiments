#pragma once
#include"PCB.h"
#include"ready_queue.h"
#include"finish_queue.h"
#define MAX_PROCESS 50
typedef struct
{
	PCB** dict;						//存放内部标志的线性表
	ready_queue* readyQueue;		//就绪队列
	finish_queue* finishQueue;		//完成队列
	int Pcount;						//进程数量
}OS;

PCB* findProcess(OS* os,int pid);
/// @brief 初始化os
/// @param os OS地址
/// @param less 就绪队列采用的调度算法对应的偏序关系
void initialize(OS* os, PRIOIOR less);
void showAllProcess(OS* os);

void end(OS* os);