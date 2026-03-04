#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void array_input(int a[], int *n){
    printf("Enter the size of the array:");
    scanf("%d",n);
    printf("Enter %d elements into the array:\n",*n);
    for(int i=0;i<*n;i++){
        scanf("%d",&a[i]);
    }
    return;
}

void array_display(int a[],int *n){
    printf("\n The elements in the array are:\n");
    for(int i=0;i<*n;i++){
        printf("%4d",a[i]);
    }
    return ;
}

void array_insert(int a[],int *n , int pos , int val){
    if(pos<0 || pos>*n){
        printf("\n Invalid position");
    }
    if(*n == MAX){
        printf("\noverflow!");
    }
    for(int i=*n-1;i>=pos;i--){
        a[i+1] = a[i];
    }
    a[pos] = val;
    *n = *n+1;
    return;
}

void array_delete(int a[] , int *n , int pos){
    if(pos<0 || pos>=*n){
        printf("\n Invalid input !");
        return;
    }
    if(*n == 0){
        printf("\n Underflow !");
        return;
    }
    for(int i=pos;i<*n-1;i++){
        a[i] = a[i+1];
    }

    *n = *n-1;
    return ;
}

void search_element(int a[] , int *n , int key){
    for(int i=0;i<*n;i++){
        if(a[i] == key){
            printf("\n Element found at index %d",i);
            return;
        }
    }
    printf("\n Element not found in the array");
    return;
}

void update_element(int a[] , int *n , int pos , int val){
    if(pos<0 || pos>=*n){
        printf("\n Invalid input !");
        return;
    }
    a[pos] = val;
    return;
}

int main(){
    printf("\n_____ MENU _____\n");
    printf("1. Input array\n");
    printf("2. Display array\n");   
    printf("3. Insert element\n");
    printf("4. Delete element\n");
    printf("5. Search element\n");
    printf("6. Update element\n");
    printf("7. Exit\n");
    int a[MAX],n=0,choice,pos,val,key;
    while(1){
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                array_input(a,&n);
                break;
            case 2:
                array_display(a,&n);
                break;
            case 3:
                printf("\n Enter the position and value to insert: ");
                scanf("%d%d",&pos,&val);
                array_insert(a,&n,pos,val);
                break;
            case 4:
                printf("\n Enter the position to delete: ");
                scanf("%d",&pos);
                array_delete(a,&n,pos);
                break;
            case 5:
                printf("\n Enter the element to search: ");
                scanf("%d",&key);
                search_element(a,&n,key);
                break;
            case 6:
                printf("\n Enter the position and new value to update: ");
                scanf("%d%d",&pos,&val);
                update_element(a,&n,pos,val);
                break;
            case 7:
                exit(0);
            default:
                printf("\n Invalid choice! Please try again.");
        }
}

}