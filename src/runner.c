#include "runner.h"

//compare function
int cmp(const void *a, const void *b)
{
    job *j1 = *(job **)a;
    job *j2 = *(job **)b;
    if (j1->slack == j2->slack)
        return j1->deadline - j2->deadline;
    return j1->slack - j2->slack;
}

int number_of_tasks = 0;
int number_of_jobs = 0;
task **task_set = NULL;
job **job_list = NULL;

int runner(FILE *fptr)
{
    //reading file contents
    read_taskset(fptr, &number_of_tasks, &task_set);
    //taskset read successfully

    //calculating utilization
    float utilization = get_utilization(&task_set, number_of_tasks);
    //calculated utilization successfully

    if (utilization > 1)
    {
        printf("Unschedulable taskset\n");
        return EXIT_FAILURE;
    }

    //calculating hyperperiod
    float hyper_period = get_hyper_period(task_set, number_of_tasks);
    printf("hyper period: %f\n", hyper_period);
    //calculated hyperperiod successfully

    //calculating in-phase time
    float inphase_time = get_inphase_time(task_set, number_of_tasks);
    //calculated inphase time

    //calculating job list ------- function implemented in helper.c
    set_job_list(task_set, number_of_tasks, hyper_period, &job_list, &number_of_jobs);
    //joblist obtained successfully

    //sorting the joblist on the basis of slack
    qsort(job_list, number_of_jobs, sizeof(job_list[0]), cmp);

    // for (size_t i = 0; i < number_of_jobs; i++)
    // {
    //     printf("job (%d,%d) a,d: (%f,%f)\n", job_list[i]->task_id, job_list[i]->job_id, job_list[i]->arrival, job_list[i]->deadline);
    // }

    //sorted successfully

    //schedule according to slack + deadline
    scheduler(task_set, number_of_tasks, job_list, number_of_jobs, hyper_period);
    return EXIT_SUCCESS;
}