// Readers-Writers Problem Program

#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

int count = 1;
int no_reader = 0;
sem_t wrt;
pthread_mutex_t mutex;


void *reader(void *rno) {


    phtread_mutex_lock(&mutex);
    no_reader++;

    if (no_reader == 1) {
        sem_wait(&wrt);

    }

    pthread_mutex_unlock(&mutex);

    printf("Reader %d: read count as %d\n", *((int *)rno), count);

    pthread_mutex_lock(&mutex);
    no_reader--;

    if (no_reader == 0) {
        sem_post(&wrt);

    }

    pthread_mutex_unlock(&mutex);

}

void *writer(void *writer_no) {
    sem_wait(&wrt);
    count = count * 2;
    printf("Writer %d modified count to %d\n", (*((int *)writer_no)), count);

    sem_post(&wrt);

}

void *reader(void *rno) {


    phtread_mutex_lock(&mutex);
    no_reader++;

    if (no_reader == 1) {
        sem_wait(&wrt);

    }

    pthread_mutex_unlock(&mutex);

    printf("Reader %d: read count as %d\n", *((int *)rno), count);

    pthread_mutex_lock(&mutex);
    no_reader--;
    if (no_reader == 0) {
        sem_post(&wrt);
    }

    pthread_mutex_unlock(&mutex);
}



int main() {

    pthread_t_read[200], write[100];
    pthread_mutex_init(&mutex, NULL);

    sem_init(&wrt, 0, 1);

    int a[200], p = 1;
    for (int i = 0; i < 200; i++) {
        a[i] = p;
        p++;
    }

    for (int i = 0; i < 200; i++) {
        pthread_create(&read[i], NULL, (void *reader), (void *)&a[i]);

    }

    for (int i = 0; i < 200; i++) {
        pthread_create(&write[i], NULL, (void *writer), (void *)&a[i]);

    }

    for (int i = 0; i < 200; i++) {
        pthread_join(read[i], NULL);
    }

    for (int i = 0; i < 100; i++) {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
