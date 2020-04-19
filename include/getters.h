#ifndef GETTERS
#define GETTERS

#include <stdio.h>
#include <stdlib.h>
#include <dataStructures.h>

float get_utilization(task ***taskset, int number_of_tasks);
float get_hyper_period(task **taskset, int number_of_tasks);
float get_inphase_time(task **taskset, int number_of_tasks);

#endif