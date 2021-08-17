//three integer that multiply to 20 in c
// 2,4,1,6,5,40,-1


#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i=0,j=0,k=0;
    int size =7;
    int target = 20;
    int arr[] = {2,4,1,6,5,40,-1};
    for(i=0;i<size;i++){

        for(j=0;j<size;j++){
        
            for(k=0;k<size;k++){
                
                if(i==j || j==k || k==i || (i==j && j==k && k==i)){
                    break;     
                }
                if( (arr[i]*arr[j]*arr[k]) == target)
                {
                    printf("%d * %d * %d = %d", arr[i],arr[j],arr[k], target);
                    return 0;                
                }
            }
        }    
    }

    
}
