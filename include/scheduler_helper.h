#ifndef SCHEDULER_HELPER
#define SCHEDULER_HELPER

#include "dataStructures.h"
#include <stdlib.h>
#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define abs(a, b) ((a - b) < 0 ? (b - a) : (a - b))

float get_next_decision_point(job **joblist, float cur_time, job *cur_job, int number_of_jobs);
void update_slack(job ***joblist, int number_of_jobs, float cur_time);
job *get_current_job(job ***joblist, int number_of_jobs, float cur_time);

#endif