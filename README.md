# MLLF with EDF
-----------------------------------------------------------------
Approach: instead of making a queue of ready jobs, I have tried to use a complete job-list before scheduling
-----------------------------------------------------------------

Directory structure:<br>
<br>
├── README.md<br>
├── include<br>
&nbsp;&nbsp;&nbsp;├── dataStructures.h<br>
&nbsp;&nbsp;&nbsp;├── getters.h<br>
&nbsp;&nbsp;&nbsp;├── helper.h<br>
&nbsp;&nbsp;&nbsp;├── runner.h<br>
&nbsp;&nbsp;&nbsp;├── scheduler.h<br>
&nbsp;&nbsp;&nbsp;└── scheduler_helper.h<br>
├── obj<br>
└── src<br>
&nbsp;&nbsp;&nbsp;&nbsp;├── a3<br>
&nbsp;&nbsp;&nbsp;&nbsp;├── getters.c<br>
&nbsp;&nbsp;&nbsp;&nbsp;├── helper.c<br>
&nbsp;&nbsp;&nbsp;&nbsp;├── input1<br>
&nbsp;&nbsp;&nbsp;&nbsp;├── input2<br>
&nbsp;&nbsp;&nbsp;&nbsp;├── main.c<br>
&nbsp;&nbsp;&nbsp;&nbsp;├── makefile<br>
&nbsp;&nbsp;&nbsp;&nbsp;├── runner.c<br>
&nbsp;&nbsp;&nbsp;&nbsp;├── scheduler.c<br>
&nbsp;&nbsp;&nbsp;&nbsp;└── scheduler_helper.c<br>

---

## Instructions to compile:

* navigate to 'src' directory and type command<br>
    &nbsp;&nbsp;&nbsp;```make```
* this generates executable named 'a3'
* feed input file as a paramenter while executing the output file<br>
    &nbsp;&nbsp;```./a3 input1```

---

## What has been tried:
(in order mentioned below)

* taskset read
* utilization calculated
* hyper-period calculated
* job-list created
* scheduling has been tried

-----------------------------------------------------------------

## What works:

* hyper-period computation
* utilization computation

## What does not work:

* scheduling of jobs get's in an infinite loop
> issue: unable to fetch next decision point correctly

-----------------------------------------------------------------

## What approach?

* instead of making a queue of ready jobs, I have tried to simulate the same using next_decision_point() function in scheduler.c and scheduler_helper.c
* the major bug exists in these two files only.

---
## Required Makefile changes

* You might need to change the makefile content accordingly.<br>
* See the directory structure and place files accordingly for this makefile to run.
* change the compiler name in the begining of the makefile to the one you are using.<br>&nbsp;&nbsp;&nbsp;example:<br>
> replace<br>&nbsp;&nbsp;&nbsp;&nbsp;```gcc-9```<br>
> with <br>&nbsp;&nbsp;&nbsp;&nbsp;```gcc```
