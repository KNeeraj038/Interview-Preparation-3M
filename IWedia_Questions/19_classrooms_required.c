/*
Array intervals (start, end).
Given array of time interval (start, end) for classroom lectures (possibly overlapping).
Find the min number of rooms required.
For ex: given [(30,73),(0,30),(60,130)]  answer:2
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int start; 
    int end;
}interval;

typedef struct {
    int room_number;
    interval Interval;
}rooms;


void check_room_needed(interval *in, int size)
{
    rooms *Room=malloc(size * sizeof(rooms));
    
    int i=0,j=0;
    int max_room_count = 1;
    
    Room[0].room_number = 1;
    Room[0].Interval = in[0]; 
    
    for(i=1;i<size;i++){
        
        for(j=0;j<max_room_count;j++){
            if(Room[j].Interval.end < in[i].start){
                max_room_count++;
                Room[max_room_count].Interval = in[i];
                Room[max_room_count].room_number = max_room_count;
                break;
            }else{
                Room[max_room_count].Interval.end = in[i].end;
            }
        }
    }
    printf("\nTotal rooms required %d", max_room_count);
}

int main()
{
    int intervals = 3;
    scanf("%d", &intervals);

    interval *Interval = malloc(intervals * sizeof(interval));
    int i=0;
    for(i=0;i<intervals;i++)
    {
        int start =0,end =0;
        printf("Enter Intervals of (start, end)-%d: ",i);
        scanf("%d %d",&start,&end);
        
        Interval[i].start =  start;
        Interval[i].end =  end;
    }
    for(i=0;i<intervals;i++)
    {
        int start =0,end =0;
        start=Interval[i].start ;
        end = Interval[i].end;
        printf("(%d, %d) , ",start,end);
    }
    check_room_needed(Interval,intervals);
    printf("\n");
}
