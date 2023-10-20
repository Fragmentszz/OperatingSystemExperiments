#pragma once
#include"_basic.h"
/// @brief PCB数据结构
typedef struct OSPCB{
	const char* pname;			//进程标识符
	int pid;					//内部标识符
	int priority;				//调度优先级
	Time arrive_time, end_time;	//到达时间，结束时间
	TimeSlice server_time;		//已被服务时间
	TimeSlice nserver_time;		//需要服务总时间
	ProcessStatus status;		//进程状态
	struct OSPCB* next_PCB;		//下一个PCB地址
} PCB;

Status ProcessRun(PCB* process);
void printProcess(PCB* process);

void destroyProcess(PCB* process);

PCB* createEmptyProcess(const char*);