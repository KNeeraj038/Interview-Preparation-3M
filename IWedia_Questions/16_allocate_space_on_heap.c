#include<stdlib.h>
#include<stdio.h>

int main()
{
    int* A = (int*) calloc(1000,sizeof(int));
    
    if(A == NULL){
        printf("Memory issue.");
    }
    free(A);
}
