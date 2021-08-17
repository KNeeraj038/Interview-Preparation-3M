/*
Given an unordered list of flights taken by someone, each represented as (origin,
destination) pairs, and a starting airport, compute the person's itinerary. If no such itinerary
exists, return null. If there are multiple possible itineraries, return the lexicographically
smallest one. All flights must be used in the itinerary.
For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]
and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].
Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should
return null.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *start_point;
    char *end_point;
}Flights;

Flights *flights;

int* processing(char *start_point, int total_flight)
{
    int i=0;
    // char start = *start_point;
    int des = total_flight;

    int *res = malloc((total_flight)*sizeof(int));
    int next_index = -1;
    while(des >= 0)
    {
        // printf("\nchecking for %s", start_point);
        for(i=0;i<total_flight;i++)
        {
            // printf("\nMatching: %s, total flights: %d",flights[i].start_point, total_flight);
            if(strcmp(flights[i].start_point,start_point)==0)
            {
                // printf("\nMAtched for %s, [%d]", start_point, i);
                next_index =  i;
                break;
            }
            if(i==total_flight-1){
                return NULL;
            }
        }
        // if(i==total_flight)
        //     return NULL;

        if(next_index ==-1){
            printf("Something went wrong");
            return NULL;
        }

        // printf("\nNext index is : %d",next_index);
        // printf("  res [%d]",(total_flight-des));

        *(res+(total_flight-des)) = next_index; 
        start_point =  flights[next_index].end_point;
        des--;
        next_index = -1;
    }

    return res;
}   

int main()
{


    // case:1
    // int total_flights = 4;
    // char *start_point = "YUL";
    // char *start[] = {"SFO","YYZ","YUL","HKO"};
    // char *end[] =   {"HKO","SFO","YYZ","ORD"};
    
    // case:2
    // [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM',
    

    int total_flights = 2;
    char *start_point = "COM";  
    char *start[] = {"SFO","COM"};
    char *end[] =   {"COM","YYZ"};
    
    flights = malloc(total_flights * sizeof(Flights));
            
    int i=0;
    for(i=0;i<total_flights;i++)
    {
        flights[i].start_point = start[i];
        flights[i].end_point = end[i];
    }
    
    printf("\n");

    for(i=0;i<total_flights;i++){
        printf(" (%s,%s),",flights[i].start_point, flights[i].end_point);
    }
    int *res = processing(start_point, total_flights);

    printf("\n");
    if(res == NULL){
        printf("\n NULL");
    }else{
        for(i=0;i<total_flights;i++)
        {
            printf("--> %s",flights[*(res+i)].start_point);
        }
        printf("--> %s",flights[*(res+i)].end_point);
    }

    printf("\n");
    return EXIT_SUCCESS;
}