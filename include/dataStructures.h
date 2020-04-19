#ifndef DS
#define DS

typedef struct _task_node task;
typedef struct _job_node job;

struct _task_node
{
    int task_id;
    float phase;
    float wcet;
    float period;
    float deadline;
};

struct _job_node
{
    int task_id;
    int job_id;
    float arrival;
    float wcet;
    float remaining_et;
    float actual_et;
    float slack;
    float deadline;
    short marked;
};

#endif