// Add two numbers given in linklist 
// Example: num1 = 123 in 3->2->1 and num2 = 456 in 6->5->4

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* head_1 = NULL;
struct Node* head_2 = NULL;

void insert_at_first(struct Node** head, int data){
    
    struct Node* new_node = malloc(sizeof( struct Node));
    new_node->data = data;

    if(head == NULL){
        *head = new_node;
        (*head)->next = NULL;
    } else {
        new_node->next = *head;
        *head = new_node;
    }
}

void print_ll(struct Node *head){
    struct Node* temp = head;
    
    while(temp != NULL)
    {
        printf("  %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* add_number(struct Node *head_1, struct Node *head_2)
{
    struct Node* temp1 = head_1;
    struct Node* temp2 = head_2;
    
    struct Node* res = NULL;
    struct Node* res_curr = NULL;
    

    int sum = 0, carry = 0;

    while(temp1 != NULL || temp2 != NULL)
    {    
        sum = carry 
              + (temp1 ? temp1->data : 0) 
              + (temp2 ? temp2->data : 0); 
        
        carry = sum >=10 ? 1 : 0;

        sum =  sum % 10;

        // Insert Node.
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = sum;
        new_node->next = NULL;
        
        if(res == NULL)
        {
            res = new_node;
        }else{
            if(res_curr == NULL){
                res_curr = new_node;
                res->next = res_curr;
            }else{
                res_curr->next = new_node;
            }
        }
        
    }

    if(carry >0){
        // Insert new if carry is there Node.
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = sum;
        new_node->next = NULL;
        res_curr->next = new_node;
    }

    return res;
}

int main()
{
    insert_at_first(&head_1, 1);
    insert_at_first(&head_1, 2);
    insert_at_first(&head_1, 3);

    insert_at_first(&head_2, 4);
    insert_at_first(&head_2, 5);
    insert_at_first(&head_2, 6);

    print_ll(head_1);

    print_ll(head_2);
    printf("-------------------");

    struct Node* addition = add_number(head_1, head_2);
    print_ll(addition);
    
    printf("\n");
    return EXIT_SUCCESS;
}
