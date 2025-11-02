/*#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int n = 0;

void* watek(void* arg) {
for (int i = 0 ; i< 100000; i++) {
    n++;
}
return NULL;
}

int main(){
pthread_t t1,t2;

pthread_create(&t1,NULL,watek,NULL);
pthread_create(&t2,NULL,watek,NULL);

pthread_join(t1, NULL);
pthread_join(t2, NULL);

printf("n = %d\n", n);

return 0;
}*/
