// C++ program to find the length of the longest substring
// without repeating characters
// #include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(x,y) x>y?x:y

int longestUniqueSubsttr(char* str)
{
	int n = strlen(str);
	int res = 0; // result

	for (int i = 0; i < n; i++) {
		
		// Note : Default values in visited are false
		// vector<bool> visited(256);
        int visited[256];
		for (int j = i; j < n; j++) {

			// If current character is visited
			// Break the loop
			if (visited[str[j]] == 1)
				break;

			// Else update the result if
			// this window is larger, and mark
			// current character as visited.
			else {
				res = MAX(res, j - i + 1);
				visited[str[j]] = 1;
			}
		}

		// Remove the first character of previous
		// window
		visited[str[i]] = 0;
	}
	return res;
}

// Driver code
int main()
{
	// char *str = "geeksforgeeks";
	char *str = "xyzxyzyy";

	int len = longestUniqueSubsttr(str);
    printf("\nLength of the longest substring without repeating characters: %d\n", len);
	return 0;
}
