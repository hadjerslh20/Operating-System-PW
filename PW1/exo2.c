#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void * display_message(void *arg) {
    printf("Hello World!\n");
    printf("PID:%d\n",getpid());
    printf("ID:%p\n",(void*)pthread_self());
    return NULL;
}

int main() {
    int numOfth;
    printf("Enter your namber of threads:");
    scanf("%d",&numOfth);
    pthread_t threads[numOfth]; // array to store all threads
    for(int i=0 ; i<numOfth ; i++) {
        pthread_create(&threads[i], NULL, display_message, NULL);
    }
    for(int i=0 ; i<numOfth ; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
// this is the output
/*
Hello World!
PID:64766
ID:0x7af4934be6c0
Hello World!
PID:64766
ID:0x7af492cbd6c0
Hello World!
PID:64766
ID:0x7af4924bc6c0

*/
