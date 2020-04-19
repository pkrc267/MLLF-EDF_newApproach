#ifndef HELPER
#define HELPER

#include <stdio.h>
#include <stdlib.h>
#include "dataStructures.h"

void read_taskset(FILE *fptr, int *number_of_tasks, task ***task_set);
void set_job_list(task **taskset, int number_of_tasks, int hyper_period, job ***job_list, int *total_jobs);

#endif