#include<stdio.h>
#include<stdlib.h>

// series: 0 1 1 2 3 5

int fibo(int n)
{
    int f0=0,f1=1;
    
    int i=0;
    int fnext = 0;
    printf("Fibo: %d --> %d ",f0,f1);
    for(i=2;i<n;i++)
    {
        fnext = f0 + f1;
        f0 = f1;
        f1 = fnext;
        printf("--> %d ",fnext);
    }
}
int fib_rec(int n)
{
    if(n<=1)
        return n;
    return fib_rec(n-1) + fib_rec(n-2);
}

int main()
{
    fibo(10);
    printf("\n");
    
    int i=0;
    printf("Fibo: %d --> %d ",0,1);
    for(i=2;i<10;i++){
        int res = fib_rec(i);
        printf("--> %d",res);
    }

    printf("\n");
    return EXIT_SUCCESS;
}