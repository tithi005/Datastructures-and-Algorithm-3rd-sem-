#include<stdio.h>
#include<stdlib.h>
typedef struct link{
    int data;
    struct link *next;
} node;

node *start = NULL;
node *getnode(int x){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void insertnode_first(int x){
    node *n1 = getnode(x);
    scanf("%d", &n1->data);
    if(!n1){
        printf("Memory allocation failed");
        return ;
    }
    n1->next = start;
    start = n1;
}

void insertnode_last(int x){
    node *n1 = getnode(x);
    scanf("%d", &n1->data);
    if(!n1){
        printf("Memory allocation failed");
        return ;
    }
    if(start == NULL){
        start = n1;
        return;
    }
    node *temp = start;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n1;
}

void display(){
    node *temp = start;
    while(temp->next!= NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void delete_first(){
    if(start == NULL){
        printf("List is empty");
        return;
    }
    node *temp = start;
    start = start->next;
    free(temp);
}

void delete_last(){
    if(start == NULL){
        printf("List is empty");
        return;
    }
    if(start->next == NULL){
        free(start);
        start = NULL;
        return;
    }
    node *temp = start;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

int main(){
    int choice, x;
    while(1){
        printf("1. Insert at first\n2. Insert at last\n3. Display\n4. Delete first\n5. Delete last\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to insert: ");
                insertnode_first(x);
                break;
            case 2:
                printf("Enter the value to insert: ");
                insertnode_last(x);
                break;
            case 3:
                display();
                break;
            case 4:
                delete_first();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}