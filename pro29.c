#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int fill = 0;
int use = 0;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void *producer(void *arg) {
    while (1) {
        int i;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        for (i = 0; i < BUFFER_SIZE; i++) {
            if (buffer[i] == -1) {
                buffer[i] = i;
                break;
            }
        }
        fill++;
        printf("Produced item %d\n", buffer[i]);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *arg) {
    while (1) {
        int i;
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        for (i = 0; i < BUFFER_SIZE; i++) {
            if (buffer[i] != -1) {
                printf("Consumed item %d\n", buffer[i]);
                buffer[i] = -1;
                break;
            }
        }
        use++;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    int i;
    for (i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = -1;
    }

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
Footer
