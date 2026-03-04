#include<stdio.h>
#include<stdlib.h>
#define SIZE 30
char stack[SIZE];
int top = -1;

int isfull(){
    return top == SIZE - 1;
}

void push(char x){
    if(isfull()==1){
        printf("\nStack is full");
        return;
    }
    stack[++top] = x;
}

int isempty(){
    return top ==-1;
}

char pop(){
    if(isempty()==1){
        printf("\nStack is Empty");
        return -1;
    }
    char x = stack[top--];
    return x;
}

int preced(char ch){
    if(ch == '^'){
        return 3;
    }
    else if(ch == '/' || ch == '*'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    else
        return 0;
}

void infix_to_postfix(char infix[]) {
    char postfix[SIZE], ch, temp;
    int i = 0, j = 0;

    while (infix[i] != '\0' && infix[i] != '\n') {
        ch = infix[i];
        switch (ch) {
            case '(':
                push(ch);
                break;
            case ')':
                while (!isempty() && (temp = pop()) != '(') {
                    postfix[j++] = temp;
                }
                break;
            case '^':
            case '/':
            case '*':
            case '+':
            case '-':
                while (!isempty() && preced(ch) <= preced(stack[top])) {
                    postfix[j++] = pop();
                }
                push(ch);
                break;
            default:
                postfix[j++] = ch;
        }
        i++;
    }

    while (!isempty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("\nPostfix Expression = %s", postfix);
}

int main(){
    char infix[SIZE];
    printf("\nEnter a valid infix expression enclosed in ():");
    gets(infix);
    infix_to_postfix(infix);
    return 0;
}