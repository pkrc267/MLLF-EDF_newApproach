#ifndef SCHEDULER
#define SCHEDULER

#include "dataStructures.h"
#include <stdio.h>
#define min(a, b) (a < b ? a : b)

void scheduler(task **taskset, int number_of_tasks, job **joblist, int number_of_jobs, float max_time);

#endif