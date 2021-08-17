#include<stdio.h>
#include<stdlib.h>

// Degree(hr) = H×(360/12) + (M×360)/(12×60)
// Degree(min) = M×(360/60)
#define MIN(x,y) (x>y)?y:x

int calculate_angle(int hrs, int mins)
{
    // Validate Input.
    if(hrs < 0 || mins < 0 || hrs >12 || mins>60)
        printf("Wrong Input");

    if(hrs == 12)
        hrs = 0;
    if(mins == 60)
    {
        mins = 0;
        hrs +=1;
        if(hrs > 12)
            hrs -= 12;
    }

    int hrs_deg = hrs * (360/12) + (mins*360)/(12*60);
    int mins_deg = mins * (360/60);

    //angle bet. hrs and mins
    int angle = abs(hrs_deg - mins_deg);

    // Minimum possible angle.
    int min_angle =  MIN(360-angle, angle);
    return min_angle;
}

int main()
{
    printf("\n %d",calculate_angle(9,60));
    printf("\n %d",calculate_angle(9,30));
    printf("\n %d",calculate_angle(3,30));
    printf("\n %d",calculate_angle(5,30));
    printf("\n %d",calculate_angle(9,30));
    printf("\n %d",calculate_angle(12,00));

    printf("\n");
}