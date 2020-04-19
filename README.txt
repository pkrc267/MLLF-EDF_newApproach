Assignment 3: MLLF with EDF
-----------------------------------------------------------------

Directory structure:
.
├── README.md
├── include
│   ├── dataStructures.h
│   ├── getters.h
│   ├── helper.h
│   ├── runner.h
│   ├── scheduler.h
│   └── scheduler_helper.h
├── obj
│
└── src
    ├── a3
    ├── getters.c
    ├── helper.c
    ├── input1
    ├── input2
    ├── main.c
    ├── makefile
    ├── runner.c
    ├── scheduler.c
    └── scheduler_helper.c

-----------------------------------------------------------------

Instructions to compile:

* navigate to 'src' directory and type command
    >> make
* this generates executable named 'a3'
* feed input file as a paramenter while executing the output file
    >> ./a3 input1

-----------------------------------------------------------------

What has been tried:
(in order mentioned below)

* taskset read
* utilization calculated
* hyper-period calculated
* job-list created
* scheduling has been tried

-----------------------------------------------------------------

What works:

* hyper-period computation
* utilization computation

What does not work:

* scheduling of jobs get's in an infinite loop
>>>> issue: unable to fetch next decision point correctly

-----------------------------------------------------------------

What approach?

* instead of making a queue of ready jobs, I have tried to simulate the same using next_decision_point() function in scheduler.c and scheduler_helper.c
* the major bug exists in these two files only.