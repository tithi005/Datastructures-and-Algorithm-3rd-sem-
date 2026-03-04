#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int circularqueue[SIZE];
int front = -1;
int rear = -1;

int isfull() {
    return (rear + 1) % SIZE == front;
}

int isempty() {
    return front == -1;
}

void enqueue(int x) {
    if (isfull()) {
        printf("\nCircular Queue is full");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    circularqueue[rear] = x;
}

int dequeue() {
    if (isempty()) {
        printf("\nCircular Queue is empty");
        return -1;
    }
    int value = circularqueue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return value;
}

int peek() {
    if (isempty()) {
        printf("\nCircular Queue is empty");
        return -1;
    }
    return circularqueue[front];
}

void showcircularqueue() {
    if (isempty()) {
        printf("\nCircular Queue is empty");
        return;
    }
    printf("\nThe circular queue is:\n");
    int i = front;
    while (1) {
        printf("%d\n", circularqueue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
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
                printf("\nEnter the element to enqueue: ");
                scanf("%d", &v);
                enqueue(v);
                break;
            case 2:
                v = dequeue();
                if (v != -1) {
                    printf("\nDequeued element: %d\n", v);
                }
                break;
            case 3:
                v = peek();
                if (v != -1) {
                    printf("\nFront element: %d\n", v);
                }
                break;
            case 4:
                showcircularqueue();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice, please try again.");
        }
    }
    return 0;
}