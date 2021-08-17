//9_aaacbbea_to_a3c1b2e1a1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void do_parsing(char * str)
{
    int i=0;
    char to_match = *(str);
    int count =1;

    char *str_res;
    for(i=1;i<strlen(str)+1;i++){
        if(to_match == *(str+i)){
            count++;
        }else{
            printf("%c%d",to_match,count);
            to_match = *(str+i);
            count = 1;
        }
    }

}

int main()
{
    char *str = "aaacbbea";
    do_parsing(str);
    printf("\n");
}