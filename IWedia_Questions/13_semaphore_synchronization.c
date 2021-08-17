//13. [] Synchronize threads so print out is A1B2C3D4 using semaphores
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>

sem_t sem_alpha, sem_digit;

void *print_alpha(){
    char *alpha = "ABCD";
    int i=0;
    for(i=0;i<strlen(alpha);i++){
        sem_wait(&sem_alpha);
        printf("%c",*(alpha+i));
        sem_post(&sem_digit);
    }
}

void *print_digits(){
    char *digit = "1234";
    int i=0;
    for(i=0;i<strlen(digit);i++){
        sem_wait(&sem_digit);
        printf("%c",*(digit+i));
        sem_post(&sem_alpha);
    }
}

int main()
{
    pthread_t thread1, thread2;

    sem_init(&sem_alpha,0,1);
    sem_init(&sem_digit,0,0);
    // Creation
    pthread_create(&thread1,NULL, print_alpha, NULL);
    pthread_create(&thread2,NULL, print_digits, NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    printf("\n");
    return EXIT_SUCCESS;
}
