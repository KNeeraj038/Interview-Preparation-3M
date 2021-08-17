/*
Array 1 [-1, 3, 8, 2, 9, 5]
Array 2 [4, 1, 2, 10, 5, 20]
*/
#include<stdio.h>
#include<stdlib.h>

void printClosest(int arr1[], int n1, int arr2[], int n2, int x)
{
	int res_l, res_r; // To store indexes of result pair

	// Initialize left and right indexes and difference between
	// pair sum and x
	int l = 0, r = n1-1, diff = __INT_MAX__;

	// While there are elements between l and r
	while (r > l)
	{
        // Check if this pair is closer than the closest pair so far
        if (abs(arr1[l] + arr2[r] - x) < diff)
        {
            res_l = l;
            res_r = r;
            diff = abs(arr1[l] + arr2[r] - x);
        }

        // If this pair has more sum, move to smaller values.
        if (arr1[l] + arr2[r] > x)
            r--;
        else
            l++;
	}

	printf(" The closest pair is %d and %d",arr1[res_l],arr2[res_r]);
}

// Driver program to test above functions
int main()
{
	// int arr[] = {10, 22, 28, 29, 30, 40}, target = 54;
    // Array 1 [-1, 3, 8, 2, 9, 5]
    // Array 2 [4, 1, 2, 10, 5, 20]
    int arr1[] = {-1, 3, 8, 2, 9, 5}, target = 15;;
    int arr2[] = {4, 1, 2, 10, 5, 20};

	int n1 = sizeof(arr1)/sizeof(arr1[0]);

	int n2 = sizeof(arr1)/sizeof(arr2[0]);
	printClosest(arr1, n1,arr2, n2, target);
	return 0;
}
