#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Simple solution if only '(', ')' are used in expression and also has some loop holes.
// assuming only '()' in the expression.


int p_count = 0;

void checkString(char * str)
{   
    int i=0;
    for(i=0;;i++)
    {
        if(*(str+i) == '\0'){
            printf("Broke out.");
            break;
        }else
        {
            printf("\nttt %c",*(str+i));
            
            switch (*(str+i))
            {
            case '(':
                    p_count++;
                    printf("\n)@ %d: ",i);
                break;
            case ')':
                    printf("\n(@ %d: ",i);
                    p_count--;
                break;

            default:
                    printf("\ndefault@ %d: ",i);
                break;
            }
        }
        
    }

    if(p_count == 0)
    {
        printf("Balanced");
    }
}

int main()
{
    char *str = malloc(10*sizeof(char));

    strcpy(str, "(())");
    checkString(str);
    printf("\n");
    return EXIT_SUCCESS;
}