/*
Array 1 [-1, 3, 8, 2, 9, 5]
Array 2 [4 , 1, 2, 10, 5, 20]
*/
#include<stdio.h>
#include<stdlib.h>

void printClosest(int arr1[], int n1, int arr2[], int n2, int x)
{
    int res_1=-1, res_2=-1;
    int diff = __INT_MAX__;
    int i=0, j=0;

    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            if(abs(arr1[i]+arr2[j]-x) < diff)
            {
                res_1 = i;
                res_2 = j;
                diff = abs(arr1[i]+arr2[j]-x);
            }
        }
    }

    if(res_1==-1 || res_2 ==-1)
        printf("Something went wrong");

	printf(" \nThe closest pair is [%d]%dand [%d]%d \n",res_1, arr1[res_1],res_2, arr2[res_2]);
}

// Driver program to test above functions
int main()
{
    int arr1[] = {-1, 3, 8, 2, 9, 5}, target = 15;
    int arr2[] = {4, 1, 2, 10, 5, 20};

	int n1 = sizeof(arr1)/sizeof(arr1[0]);

	int n2 = sizeof(arr1)/sizeof(arr2[0]);
	printClosest(arr1, 6,arr2, 6, target);
	return 0;
}
