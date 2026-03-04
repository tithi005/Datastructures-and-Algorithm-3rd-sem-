#include<stdio.h>
#include<stdlib.h>
typedef struct link{
    struct link *next;
    int data;
}node;

node *front = NULL;
node *rear = NULL;

node *getnode(int x){
    node *newnode = (node*)malloc(sizeof(node));
    if(!newnode){
        printf("\n memory allocation failed");
    } else{
        newnode->next = NULL;
        newnode->data = x;
    }
    return newnode;
}

void enqueue(int x){
    node *n1 = getnode(x);
    n1->data = x;
    if(rear == NULL){
        rear = front = n1;
    } else{
        rear->next = n1;
        rear = rear->next;
    }
}

int dequeue(){
    if(front == NULL){
        printf("\n The queue is empty");
        return -1;
    }

    node *temp = front;
    front = front->next;
    int x = temp->data;
    free(temp);
    return x;
}

void display(){
    if(front == NULL){
        printf("\n The queue is empty");
        return;
    }
    node *temp = front;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice, x;
    while(1){
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Display");
        printf("\n 4. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\n Enter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                x = dequeue();
                if(x != -1){
                    printf("\n Dequeued element is %d", x);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\n Invalid choice! Please try again.");
        }
    }
    return 0;
}