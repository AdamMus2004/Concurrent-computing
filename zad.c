/*
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void* funkcja_watku(void* arg) {
int id = *(int*)arg;
printf("Watek %d: dziala\n",id);
pthread_exit(NULL);
}

int main() {
pthread_t watek1, watek2;
int id1 = 1, id2=2;

pthread_create(&watek1, NULL, funkcja_watku, &id1);
pthread_create(&watek2, NULL, funkcja_watku, &id1);

pthread_join(watek1, NULL);
pthread_join(watek2, NULL);

printf("Watek glowny: koniec programu.\n");

return 0;
}*/
