#include<stdio.h>
#include<math.h>
#define SIZE 30
float stack[SIZE];
int top = -1;

int isfull(){
    return top == SIZE-1;
}
void push(float x){
    if(isfull()==1){
        printf("\nStack is Full");
        return;
    }
    stack[++top]=x;
}

int isempty(){
    return top == -1;
}

float pop(){
    if(isempty()==1){
        printf("\nStack is Empty");
        return -1;
    }
    float x = stack[top--];
    return x;
}

float postfix_evaluation(char infix[], float value[]){
    char ch ;
    int i = 0;
    float op1 , op2 ;
    while(infix[i] !='\0'){
        ch = infix[i];
        if(ch>='A' && ch <= 'Z'|| ch>='a' && ch <= 'z'){
            push(value[i]);
        }
        else{
            op2 = pop();
            op1 = pop();
            switch(ch){
                case '^': push(pow(op1,op2)); break;
                case '+': push(op1+op2); break;
                case '-': push(op1-op2); break;
                case '*': push(op1*op2); break;
                case '/': push(op1/op2); break;
            }
        }
        i++;
    }
    return pop();
}

int main(){
    char infix[SIZE];
    float value[SIZE];
    printf("Enter the postfix expression: ");
    fgets(infix, SIZE, stdin);
    printf("Enter the values for the variables (A=0, B=1, C=2, ...): ");
    for(int i = 0; i < SIZE; i++){
        value[i] = 0;
    }
    for(int i = 0; infix[i] != '\0' && infix[i] != '\n'; i++){
        if((infix[i]>='A' && infix[i] <= 'Z') || (infix[i]>='a' && infix[i] <= 'z')){
            printf("%c: ", infix[i]);
            scanf("%f", &value[i]);
        }
    }
    float result = postfix_evaluation(infix, value);
    printf("The result of the postfix expression is: %.2f\n", result);
    return 0;
}