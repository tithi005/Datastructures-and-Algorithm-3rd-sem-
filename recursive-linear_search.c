#include<stdio.h>
#include<stdlib.h>

void array_input(int a[], int n){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void display_array(int a[], int n){
    printf("\nThe required array is...\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

int recursive_linear_search(int a[], int key, int index, int n){
    if(index == n){
        return -1;
    }
    if(a[index] == key){
        return index;
    }
    return recursive_linear_search(a, key, index + 1, n);
}

int main(){
    int x; int n; int key;
    int a[100];
    
    printf("\n------MENU------\n");
    printf("\n1.array input");
    printf("\n2.array display");
    printf("\n3.Search a particular element:");
    printf("\n4.exit");
    
    while(1){
        printf("\nEnter your choice:");
        scanf("%d",&x);
        switch(x){
            case 1:{
                printf("Enter the size of the array:");
                scanf("%d",&n);
                printf("\nEnter %d elements into the array:",n);
                array_input(a,n);
                break;
            }
            case 2:{
                display_array(a,n);
                break;
            }
            case 3:{
                printf("\nEnter the element to be searched:");
                scanf("%d",&key);
                int result = recursive_linear_search(a, key, 0, n);
                
                if(result == -1){
                    printf("Element %d is not present in the array.\n", key);
                } else{
                    printf("The element is found at position %d\n", result + 1);
                }
                break;
            }
            case 4:{
                exit(0);
            }
            default :{
                printf("\n invalid input !");
            }
        }
    }
    return 0;
}