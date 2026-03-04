#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;

int isfull() {
    return rear == SIZE - 1;
}

int isempty() {
    return front == -1 || front > rear;
}


void enqueue(int x) {
    if (isfull()) {
        printf("\nQueue is full");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = x;
}

int dequeue() {
    if (isempty()) {
        printf("\nQueue is empty");
        return -1;
    }
    return queue[front++];
}

int peek() {
    if (isempty()) {
        printf("\nQueue is empty");
        return -1;
    }
    return queue[front];
}

void showqueue() {
    if (isempty()) {
        printf("\nQueue is empty");
        return;
    }
    printf("\nThe queue is:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}

int main() {
    int x, v;
    while (1) {
        printf("\nPress 1 to enqueue an element");
        printf("\nPress 2 to dequeue an element");
        printf("\nPress 3 to peek an element");
        printf("\nPress 4 to display");
        printf("\nPress 5 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &x);
        
        switch (x) {
            case 1:
                printf("\nEnter the element to be enqueued: ");
                scanf("%d", &v);
                enqueue(v);
                break;
            case 2:
                v = dequeue();
                if (v != -1) {
                    printf("\nThe dequeued element is %d", v);
                }
                break;
            case 3:
                v = peek();
                if (v != -1) {
                    printf("\nThe front element is %d", v);
                }
                break;
            case 4:
                showqueue();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}   