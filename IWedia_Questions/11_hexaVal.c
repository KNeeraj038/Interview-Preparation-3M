/*

QUESTION:

#define getLastN(num)

#include <stdio.h>
int main(){
    int y =0xABCD; 

    int x = getLastN(y,4);  // n=4, expected o/p is 0xD
                            // n=8, expected o/p is 0xCD
                            // n=8, expected o/p is 0xBCD
}

*/


//ANSWER
#define getLastN(num,n) (num & (1<< n) -1)

#include <stdio.h>
int main(){
    int y =0xABCD; 

    int x = getLastN(y,4);  // n=4, expected o/p is 0xD
    printf("\n%#X",x);
    x = getLastN(y,8);  // n=8, expected o/p is 0xCD
    printf("\n%#X",x);
    x = getLastN(y,12);  // n=8, expected o/p is 0xBCD
    printf("\n%#X",x);
    printf("\n");

}