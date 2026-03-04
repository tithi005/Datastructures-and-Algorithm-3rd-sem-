#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
node *head = NULL;
node *getnode(){
    node *newnode = (node*)malloc(sizeof(node));
    printf("\n Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return newnode;
}

void insert_end(){
    node *newnode = getnode();
    if(head == NULL){
        head = newnode;
        head->next = head;
    }
    else{
        node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    return ;
}

void display(){
    if(head == NULL){
        printf("\n List is empty!");
        return;
    }
    node *temp = head;
    printf("\n The elements in the circular linked list are:\n");
    do{
        printf("%4d",temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}

void insert_begin(){
    node *newnode = getnode();
    if(head == NULL){
        head = newnode;
        head->next = head;
    }
    else{
        node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }

    return ;
}   

void delete_end(){
    if(head == NULL){
        printf("\n List is empty!");
        return;
    }
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }
    node *temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
    return ;
}

void delete_begin(){
    if(head == NULL){
        printf("\n List is empty!");
        return;
    }
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }
    node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    node *todelete = head;
    temp->next = head->next;
    head = head->next;
    free(todelete);
    return ;
}

int main(){
    printf("\n_____ MENU _____\n");
    printf("1. Insert at end\n");
    printf("2. Insert at beginning\n");
    printf("3. Delete from end\n");
    printf("4. Delete from beginning\n");
    printf("5. Display the list\n");
    printf("6. Exit\n");
    int choice;
    while(1){
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert_end();
                    break;
            case 2: insert_begin();
                    break;
            case 3: delete_end();
                    break;
            case 4: delete_begin();
                    break;
            case 5: display();
                    break;
            case 6: exit(0);
            default: printf("\n Invalid choice! Please try again.");
        }
    }
    return 0;
}

