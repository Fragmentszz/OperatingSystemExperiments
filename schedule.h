#pragma once
#include"ready_queue.h"
#include"finish_queue.h"
typedef struct
{
	ready_queue* readyQueue;
	finish_queue* finishQueue;
}OS;

void schedule(ready_queue* readyQueue);
void initialize(OS* os);

void random_schedule(ready_queue* readyQueue,int flag);