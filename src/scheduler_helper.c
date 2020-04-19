#include "scheduler_helper.h"

int cmp2(const void *a, const void *b)
{
    job *j1 = *(job **)a;
    job *j2 = *(job **)b;
    if (j1->slack == j2->slack)
        return j1->deadline - j2->deadline;
    return j1->slack - j2->slack;
}

float get_next_arrival(job **joblist, float cur_time, job *cur_job, int number_of_jobs)
{
    float arr = 1 << 30;

    for (int i = 0; (i < number_of_jobs) /* && (joblist[i]->marked == 0)*/; i++)
    {
        printf("job arrival: %f\n", joblist[i]->arrival);
        if (joblist[i]->arrival != cur_time)
            arr = min(arr, joblist[i]->arrival);
    }
    printf("ret: %f\n", arr);
    return arr;
}

float get_next_completion(job **joblist, float cur_time, job **cur_job, int number_of_jobs)
{
    return (*cur_job)->remaining_et;
}

float get_next_decision_point(job **joblist, float cur_time, job *cur_job, int number_of_jobs)
{

    float next_arrival = get_next_arrival(joblist, cur_time, cur_job, number_of_jobs);

    float next_completion = get_next_completion(joblist, cur_time, &cur_job, number_of_jobs);

    float slack_difference = abs(cur_job->slack, (cur_job + 1)->slack);

    return min(slack_difference, min(next_arrival, next_completion));
}

void update_slack(job ***joblist, int number_of_jobs, float cur_time)
{
    for (int i = 0; i < number_of_jobs; i++)
    {
        if (((*joblist)[i]->marked != 1) && ((*joblist)[i]->marked != 2))
        {
            (*joblist)[i]->slack = (*joblist)[i]->deadline - (*joblist)[i]->remaining_et - cur_time;
        }
    }
    qsort((*joblist), number_of_jobs, sizeof((*joblist)[0]), cmp2); //implement sort function
}

job *get_current_job(job ***joblist, int number_of_jobs, float cur_time)
{
    // job *j = (job *)malloc(sizeof(job));
    job *j = (*joblist)[0];

    for (int i = 0; i < number_of_jobs; i++)
    {
        if (((*joblist)[i]->arrival <= cur_time) && ((*joblist)[i]->marked != 2) && ((*joblist)[i]->remaining_et > 0))
        {
            if ((*joblist)[i]->slack == j->slack)
            {
                if ((*joblist)[i]->deadline < j->deadline)
                    j = (*joblist)[i];
            }
            else
            {
                if ((*joblist)[i]->slack < j->slack)
                    j = (*joblist)[i];
            }
        }
    }
    return j;
}