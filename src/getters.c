#include "getters.h"

float get_utilization(task ***taskset, int number_of_tasks)
{
    float util = 0;

    for (size_t i = 0; i < number_of_tasks; i++)
    {
        util += ((*taskset)[i]->wcet / (*taskset)[i]->period);
    }
    return util;
}

int get_gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return get_gcd(b, a % b);
}

int get_lcm(int a, int b)
{
    return ((a * b) / get_gcd(a, b));
}

float get_hyper_period(task **taskset, int number_of_tasks)
{
    float hyperperiod = 1;
    int n = number_of_tasks - 1;
    while (n >= 0)
    {
        hyperperiod = get_lcm(hyperperiod, taskset[n]->period);
        n--;
    }
    return hyperperiod;
}

float get_inphase_time(task **taskset, int number_of_tasks)
{
    float *time = (float *)malloc(sizeof(float) * number_of_tasks);

    for (size_t i = 0; i < number_of_tasks; i++)
    {
        time[i] = taskset[i]->phase;
    }

    float inphase_time = 0;

    while (1)
    {
        size_t flag = 1;

        int pos = 0;

        for (size_t i = 1; i < number_of_tasks; i++)
        {
            if (time[i] != time[pos])
            {
                flag = 0;
                break;
            }
        }

        inphase_time = time[pos];
        if (flag == 1)
            break;

        for (size_t i = 1; i < number_of_tasks; i++)
        {
            if (time[i] < time[pos])
                pos = i;
            else
            {
                if ((time[pos] == time[i]) && (taskset[i]->period < taskset[pos]->period))
                    pos = i;
            }
        }

        time[pos] += taskset[pos]->period;
    }

    return inphase_time;
}