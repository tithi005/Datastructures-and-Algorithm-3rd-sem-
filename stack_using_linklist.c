#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node * next;
    int data;
}node;

node *top = NULL;

node *getnode(int x){
    node *newnode = (node*)malloc(sizeof(node));
    if(!newnode){
        printf("\n memory allocation failed !");
    } else{
        newnode->data = x;
        newnode->next = NULL;
    }
    return newnode;
}

void push(int x){
    node *n1 = getnode(x);
    if(!n1){
        printf("Memory allocation failed !");
        return;
    } else{
        n1->next = top;
        top = n1;
    }
}

void pop(int x){
    if(top == NULL){
        printf("\n Cannot pop element...stack is empty");
        return;
    }

    node *temp = top;
    printf("\n popped element is %d",temp->data);
    top = top->next;
    free(temp);
}

void display(){
    if(top == NULL){
        printf("\n Stack is empty");
        return;
    }
    node *temp = top;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice, x;
    while(1){
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Display");
        printf("\n 4. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\n Enter the element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop(x);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\n Invalid choice...try again!");
        }
    }
    return 0;
}