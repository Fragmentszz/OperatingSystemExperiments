#pragma once
#include"_basic.h"

typedef struct OSPCB{
	const char* pid;
	int priority;
	Time start_time, end_time;
	TimeSlice server_time;
	TimeSlice nserver_time;
	ProcessStatus status;
	struct OSPCB* next_PCB;
} PCB;

Status ProcessRun(PCB* process);
void printProcess(PCB* process);
PCB* createProcess(const char* pid, int priority, TimeSlice server_time, Time start);
void destroyProcess(PCB* process);