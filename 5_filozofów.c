#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5 // liczba filozofów = liczba widelców

pthread_mutex_t widelec[N]; // każdy widelec to mutex
sem_t sem;                  // semafor ograniczający do 4 filozofów

void mysli(int id) {
    printf("Filozof %d: mysli\n", id+1);
    sleep(rand() % 2 + 1);
}

void je(int id) {
    printf("Filozof %d: je\n", id+1);
    sleep(rand() % 2 + 1);
}

void* filozof(void* arg) {
    int id = *(int*)arg;
    int lewy = id;
    int prawy = (id + 1) % N;

    while (1) {
        mysli(id);

        sem_wait(&sem); // 🔒 dopuszczamy max 4 filozofów do stołu

        pthread_mutex_lock(&widelec[lewy]);
        pthread_mutex_lock(&widelec[prawy]);

        je(id);

        pthread_mutex_unlock(&widelec[prawy]);
        pthread_mutex_unlock(&widelec[lewy]);

        sem_post(&sem); // 🔓 zwalniamy miejsce przy stole
    }
}

int main() {
    srand(time(NULL));
    pthread_t t[N];
    int id[N];

    sem_init(&sem, 0, N - 1); // tylko 4 filozofów może siadać naraz

    for (int i = 0; i < N; i++)
        pthread_mutex_init(&widelec[i], NULL);

    for (int i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&t[i], NULL, filozof, &id[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    sem_destroy(&sem);
    for (int i = 0; i < N; i++)
        pthread_mutex_destroy(&widelec[i]);

    return 0;
}
