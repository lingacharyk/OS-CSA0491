
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

sem_t chopsticks[N]; 


void* philosopher(void* arg)
{
    int id = *((int*)arg);
    while (1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1);

        printf("Philosopher %d is hungry...\n", id);


        sem_wait(&chopsticks[id]); 
        sem_wait(&chopsticks[(id + 1) % N]); 

        printf("Philosopher %d is eating...\n", id);
        sleep(1);

      
        sem_post(&chopsticks[id]); 
        sem_post(&chopsticks[(id + 1) % N]);
    }
    return NULL;
}

int main()
{
    int i;

  
    for (i = 0; i < N; i++) {
        sem_init(&chopsticks[i], 0, 1);
    }

    pthread_t threads[N];
    int ids[N];

 
    for (i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }

  
    for (i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
Footer
