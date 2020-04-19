#include "helper.h"

void read_taskset(FILE *fptr, int *number_of_tasks, task ***task_set)
{
    fscanf(fptr, "%d", number_of_tasks);

    task **local_taskset = (task **)malloc(sizeof(task) * (*number_of_tasks));

    for (size_t i = 0; i < (*number_of_tasks); i++)
    {
        float phase, wcet, period, deadline;
        fscanf(fptr, "%f, %f, %f, %f", &phase, &wcet, &period, &deadline);
        task *temp = (task *)malloc(sizeof(task));
        temp->task_id = i;
        temp->phase = phase;
        temp->wcet = wcet;
        temp->period = period;
        temp->deadline = deadline;

        local_taskset[i] = temp;
    }
    *task_set = local_taskset;
}

job *job_init(task *t, int tid, int jid)
{
    job *tj = (job *)malloc(sizeof(job));
    tj->task_id = tid;
    tj->job_id = jid;
    tj->arrival = ((t->period * jid) + t->phase);
    tj->wcet = t->wcet;
    tj->actual_et = t->wcet;
    tj->remaining_et = t->wcet;
    tj->deadline = tj->arrival + tj->wcet;
    tj->slack = 0; //tj->deadline - tj->arrival - tj->remaining_et;
    tj->marked = 0;
}

void set_job_list(task **taskset, int number_of_tasks, int hyper_period, job ***job_list, int *total_jobs)
{
    int total_number_of_jobs = 0;
    for (size_t i = 0; i < number_of_tasks; i++)
    {
        task *temp;

        temp = taskset[i];

        total_number_of_jobs += ((hyper_period - temp->phase) / temp->period);
    }

    job **local_joblist = (job **)malloc(sizeof(job) * total_number_of_jobs);

    int jindex = 0;
    for (size_t i = 0; i < number_of_tasks; i++)
    {
        int n = (hyper_period - taskset[i]->phase) / taskset[i]->period;
        for (size_t j = 0; j < n; j++)
        {
            job *tj = job_init(taskset[i], i, j);
            local_joblist[jindex] = tj;
            jindex++;
        }
    }

    *job_list = local_joblist;
    *total_jobs = total_number_of_jobs;
}