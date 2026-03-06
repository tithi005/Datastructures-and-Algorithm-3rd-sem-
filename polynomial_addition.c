#include <stdio.h>
#include <stdlib.h>

typedef struct slink {
    int coeff;
    int exp;
    struct slink *next;
} node;

node *getnode(int c, int e) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->coeff = c;
    newnode->exp = e;
    newnode->next = NULL;
    return newnode;
}

void insert_term(node **start, int c, int e) {
    if (c == 0) return; // Ignore zeros

    if (*start == NULL || (*start)->exp < e) {
        node *n1 = getnode(c, e);
        n1->next = *start;
        *start = n1;
        return;
    }
    if ((*start)->exp == e) {
        (*start)->coeff += c;
        return;
    }
    node *temp = *start;
    while (temp->next != NULL && temp->next->exp > e) {
        temp = temp->next;
    }
    if (temp->next != NULL && temp->next->exp == e) {
        temp->next->coeff += c;
    } 
    else {
        node *n1 = getnode(c, e);
        n1->next = temp->next;
        temp->next = n1;
    }
}
node* add_polynomials(node *start1, node *start2) {
    node *result = NULL;
    node *temp;
    temp = start1;
    while (temp != NULL) {
        insert_term(&result, temp->coeff, temp->exp);
        temp = temp->next;
    }
    temp = start2;
    while (temp != NULL) {
        insert_term(&result, temp->coeff, temp->exp);
        temp = temp->next;
    }

    return result;
}

void display(node *start) {
    if (start == NULL) {
        printf("0\n");
        return;
    }
    
    node *temp = start;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL && temp->next->coeff > 0) {
            printf(" + ");
        } else if (temp->next != NULL) {
            printf(" "); 
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int choice, c, e;

    while (1) {
        printf("\n1. Insert Poly 1 | 2. Insert Poly 2 | 3. Display | 4. Add | 5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Coefficient and Exponent: ");
                scanf("%d %d", &c, &e);
                insert_term(&poly1, c, e);
                break;
            case 2:
                printf("Enter Coefficient and Exponent: ");
                scanf("%d %d", &c, &e);
                insert_term(&poly2, c, e);
                break;
            case 3:
                printf("\nPoly 1: "); display(poly1);
                printf("Poly 2: "); display(poly2);
                break;
            case 4:
                result = add_polynomials(poly1, poly2);
                printf("\nResult: "); display(result);
                result = NULL; 
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}