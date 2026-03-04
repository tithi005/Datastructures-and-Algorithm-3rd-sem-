#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

int isfull() {
    return top == SIZE - 1;
}

int isempty() {
    return top == -1;
}

void push(int x) {
    if (isfull()) {
        printf("\nStack is full");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (isempty()) {
        printf("\nStack is empty");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isempty()) {
        printf("\nThe stack is empty");
        return -1;
    }
    return stack[top];
}

void showstack() {
    if (isempty()) {
        printf("\nStack is empty");
        return;
    }
    printf("\nThe stack is:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int x, v;
    while (1) {
        printf("\nPress 1 to push an element");
        printf("\nPress 2 to pop an element");
        printf("\nPress 3 to peek an element");
        printf("\nPress 4 to display");
        printf("\nPress 5 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &x);

        switch (x) {
            case 1:
                printf("\nEnter the element to be pushed: ");
                scanf("%d", &v);
                push(v);
                break;
            case 2:
                v = pop();
                if (v != -1) {
                    printf("\nThe popped element is %d", v);
                }
                break;
            case 3:
                v = peek();
                if (v != -1) {
                    printf("\nThe top element is %d", v);
                }
                break;
            case 4:
                showstack();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
}