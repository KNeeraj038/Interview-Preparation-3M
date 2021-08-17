// Implement function that examines if all the brackets are matched in the given string.
// char *str = "((({}){}){})"; // balanced
// char *str = "((({}){){})";  //unbalance

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int top;
    int size;
    char *exp;
}Exp;

int is_full(Exp *exp)
{
    return exp->top == exp->size-1;
}

int is_empty(Exp *exp)
{
    return exp->top == -1;
}

Exp * create_exp(int size)
{
    Exp *newExp = (Exp *)malloc(size * sizeof(Exp));
    newExp->size = size;
    newExp->exp = malloc(size * sizeof(newExp->exp));
    return newExp;
}

char pop_data(Exp *exp)
{
    if(is_empty(exp))
        return '\0';
    return exp->exp[exp->top--];
}

char peek_data(Exp *exp)
{
    if(is_empty(exp))
        return '\0';
    return exp->exp[exp->top];
}

void push_data(Exp *exp, char data)
{
    printf("\nPre-data %c",data);

    if(is_full(exp))
        return;
    printf(" --- data %c",data);
    exp->exp[++exp->top] = data;

}

void print_stack(Exp *exp)
{
    int i=0;
    int size = exp->top;
    printf("Size:[%d]  \n", size);
    
    for(i=0;i<=exp->top;i++)
    {
        printf("--> %c ",exp->exp[i]);
    }
}

int is_matching_pair(char pdata,char data)
{
    if(pdata == '(' && data == ')')
        return 1;
    if(pdata == '{' && data == '}')
        return 1;
    if(pdata == '[' && data == ']')
        return 1;
    return 0;
}

int main()
{
    int size = 100;
    Exp *exp = create_exp(size);

    // char *str = "((({}){}){})"; // balanced
    char *str = "((({}){){})";  //unbalance

    int i=0;
    printf("%s", str);
    for(i=0;i<strlen(str);i++){
        char data = *(str+i);
        switch(data){
            case '(':
            case '{':
            case '[':
                push_data(exp, data);
                break;
            case ')':
            case '}':
            case ']':{
                char pdata='\0';
                pdata = peek_data(exp);
                // if(pdata == data) printf("Equal");
                if(is_matching_pair(pdata,data))
                {
                    printf("\nbalanced %c ~ %c  poping out", pdata, data);
                    // pop_data(exp);
                    printf("popped %c ",pop_data(exp));
                }
                else{
                    printf("\nunbalance %c ~ %c", pdata, data);
                    return 0;
                }
                break;
            }
        }


    }
    print_stack(exp);

    printf("\n");
    return EXIT_SUCCESS;
}