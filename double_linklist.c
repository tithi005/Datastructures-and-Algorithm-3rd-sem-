#include<stdio.h>
#include<stdlib.h>
typedef struct dlink{
    struct dlink *prev;
    struct dlink *next;
    int data;
} node;

node *start = NULL;

node *getnode(int x){
    node *newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("\n Memory allocation failed");
    }
    else{
        newnode->data = x;
        newnode->prev = newnode->next = NULL;
    }
    return newnode;
}

void insertnode_first(int x){
    node *n1 = getnode(x);
    if(!n1){
        printf("\nMemory allocation failed");
        return;
    }
    if(start==NULL){
        start = n1;
        return;
    }
    n1->next = start;
    start->prev = n1;
    start = n1;
}

void insertnode_last(int x){
    node *n1 = getnode(x);
    if(!n1){
        printf("\n Memory allocation failed");
        return;
    }
    if(start==NULL){
        start = n1;
        return;
    }
    node *l = start;
    while(l->next != NULL){
        l = l->next;
    }
    l->next = n1;
    n1->prev = l;
}

void deletenode_first(int x){
    if(start == NULL){
        printf("\n List is empty");
        return;
    }
    node *temp = start;
    if(start->next == NULL){
        start = NULL;
    } else {
        start = start->next;
        start->prev = NULL;
    }
    free(temp);
    printf("\n Node with data %d deleted from the beginning", x);
}

void deletenode_last(int x){
    if(start == NULL){
        printf("\n List is empty");
        return;
    }
    node *temp = start;
    if(start->next == NULL){
        start = NULL;
        free(temp);
        printf("\n Node with data %d deleted from the end", x);
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("\n Node with data %d deleted from the end", x);
}

void display(){
    if(start == NULL){
        printf("\n List is empty");
        return;
    }
    node *temp = start;
    printf("\n List elements: ");
    while(temp != NULL){
        printf("%d<-> ", temp->data);
        temp = temp->next;
    }
}

int main(){
    printf("\n-----MENU-----");
    printf("\n1. Insert node at the beginning");
    printf("\n2. Insert node at the end");
    printf("\n3. Delete node from the beginning");
    printf("\n4. Delete node from the end");
    printf("\n5. Display the list");
    printf("\n6. Exit");
    int choice, data;
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter data to insert at the beginning: ");
                scanf("%d", &data);
                insertnode_first(data);
                break;
            case 2:
                printf("\nEnter data to insert at the end: ");
                scanf("%d", &data);
                insertnode_last(data);
                break;
            case 3:
                printf("\nEnter data to delete from the beginning: ");
                scanf("%d", &data);
                deletenode_first(data);
                break;
            case 4:
                printf("\nEnter data to delete from the end: ");
                scanf("%d", &data);
                deletenode_last(data);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice, please try again.");
        }
    }
}