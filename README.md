# Barrier-Synchronization-With-MultipleThreads
Operating system project that let user to sync the barrier with multi threads



# Problem  Statement 
A barrier is a tool for synchronizing the activity of a number of threads. When a thread reaches abarrier point, it cannot proceed until all other threads have reached this point as well. When the last thread reaches the barrier point, all threads are released and can resume concurrent execution. Assume that the barrier is initialized to N —thenumber of threads that must wait at the barrier point.

init(N);

Each thread then performs some work until it reaches the barrier point:

/* do some work for awhile */

barrier point();

/* do some work for awhile */

Using synchronization tools described in this chapter, construct a barrier that implements the following API:

•int init(int n)—Initializesthe barrier to the speciﬁed size.

•int barrier point(void)—Identiﬁesthe barrier point.

All threads are released from the barrier when the last thread reaches this point. The return value of each function is used to identify error conditions. Each function will return 0 under normal operation and will return −1 if an error occurs. A testing harness is provided in the source code download to test your implementation of the barrier


# Solution 

instead of making a new barrier i used an object of pthread that is pthread_object

source:- https://docs.oracle.com/cd/E19253-01/816-5137/gfwek/index.html

1.pthread_barrier_wait();
2.pthread_barrier_init();
