#include "scheduler.h"
#include "scheduler_helper.h"

void scheduler(task **taskset, int number_of_tasks, job **joblist, int number_of_jobs, float max_time)
{
    float cur_time = 0;
    job *cur_job; // todo: select among ready jobs only out of slack/deadline sorted jobs
    float next_decision_point = 0;
    int k = 0;
    while (cur_time < max_time)
    {
        //schedule other job once current job is completed
        cur_job = get_current_job(&joblist, number_of_jobs, cur_time);
        printf("cur job: (%d,%d)\n", cur_job->task_id, cur_job->job_id);

        cur_job->marked = 1;
        next_decision_point = get_next_decision_point(joblist, cur_time, cur_job, number_of_jobs);
        printf("next dp: %f\n", next_decision_point);

        cur_job->remaining_et -= next_decision_point;
        cur_time += next_decision_point;

        if (cur_job->remaining_et == 0)
        {
            cur_job->marked = 2;
        }
        update_slack(&joblist, number_of_jobs, cur_time);
        k++;
        if (k == 3)
            break;
    }
}