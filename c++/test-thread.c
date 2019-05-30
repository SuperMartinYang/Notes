#include <pthread.h>
#include <stdio.h>
// init cond variable and mutex
pthread_mutex_t pm = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t odd_pc = PTHREAD_COND_INITIALIZER;
pthread_cond_t even_pc = PTHREAD_COND_INITIALIZER;


void* printOdd(){
    for (int i = 1; i < 100; i += 2){
        pthread_cond_wait(&odd_pc, &pm);
        printf("Print by Odd: %d\n", i);
        pthread_cond_broadcast(&even_pc);
    }
}

void* printEven(){
    for (int i = 0; i < 100; i += 2){
        printf("Print by Even: %d\n", i);
        pthread_cond_broadcast(&odd_pc);
        pthread_cond_wait(&even_pc, &pm);
    }
}

int main(){
    // 2 thread, one print odd, one print even
    pthread_t pid[] = {0, 1};
    // create thread
    pthread_create(&pid[1], NULL, printOdd, NULL);
    pthread_create(&pid[0], NULL, printEven, NULL);

    // join thread
    void * result;
    for (int i = 0; i < sizeof(pid); i++){
        pthread_join(pid[i], &result);
    }
    return 0;
}
