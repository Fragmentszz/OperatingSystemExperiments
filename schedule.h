#pragma once
#include"OS.h"


void schedule(ready_queue* readyQueue);
/// @brief 在os中创建一个进程
/// @param pname 进程名称
/// @param priority 进程初始优先级
/// @param server_time 进程所需要的服务时间片
/// @param arrive 进程达到时间
/// @param os OS
/// @return PCB指针
PCB* createProcess(const char* pname, int priority, TimeSlice server_time, Time arrive, OS* os);

void random_schedule(OS* os);

