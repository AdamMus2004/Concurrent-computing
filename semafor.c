/*#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
int n = 0;
sem_t sem;

void* watek(void* arg) {
for (int i = 0 ; i< 100000; i++) {
   sem_wait(&sem);
    n++;
    sem_post(&sem);
}
return NULL;
}

int main(){
pthread_t t1,t2;
sem_init(&sem,0,1);

pthread_create(&t1,NULL,watek,NULL);
pthread_create(&t2,NULL,watek,NULL);

pthread_join(t1, NULL);
pthread_join(t2, NULL);

sem_destroy(&sem);
printf("n = %d\n", n);

return 0;
}*/

