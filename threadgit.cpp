#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include<semaphore.h>
sem_t s;
pthread_barrier_t mybarrier;

int shared=1;
void* threadFn(void *id_ptr) {
  int thread_id = *(int*)id_ptr;
  int wait_sec = 3 + rand() % 5;
  printf("thread %d: Wait for %d seconds.\n", thread_id, wait_sec);

  sleep(wait_sec);
  printf("thread %d: I'm ready...\n", thread_id);

  pthread_barrier_wait(&mybarrier);
int y;
sem_wait(&s);
y=shared;
y++;
shared=y;
sem_post(&s);
  printf("thread %d: going!\n", thread_id);
  return NULL;
}


int main() {
  int i;
  sem_init(&s,0,1);
  int THREAD_COUNT;
  printf("enter the number of thread you want to create\n");
  scanf("%d",&THREAD_COUNT);
  pthread_t ids[THREAD_COUNT];
  int short_ids[THREAD_COUNT];

  srand(time(NULL));
  pthread_barrier_init(&mybarrier, NULL, THREAD_COUNT + 1);

  for (i=0; i < THREAD_COUNT; i++) {
    short_ids[i] = i;
    pthread_create(&ids[i], NULL, threadFn, &short_ids[i]);
    
  }

  printf("main() is ready.\n");

  pthread_barrier_wait(&mybarrier);

  printf("main() is going!\n");

  for (i=0; i < THREAD_COUNT; i++) {
    pthread_join(ids[i], NULL);
  }

  pthread_barrier_destroy(&mybarrier);
printf("Shared value is %d\n",shared);
  return 0;
}
