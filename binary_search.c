#include<stdio.h>
#include<stdlib.h>

void array_input(int a[], int n){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void array_display(int a[], int n){
    printf("\nThe required array is....\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}

int binary_search(int a[],int left , int right , int key){
    while(left<=right){
        int mid = left -(left-right)/2;
        if(a[mid] == key){
            return mid;
        }
        if(a[mid]<key){
            left = mid+1;
        } else{
            right = mid-1;
        }
    }
    return -1;
}

int main(){
    int x,v; int n; int key;
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
                array_display(a,n);
                break;
            }
            case 3:{
                printf("\nEnter the element to be searched:");
                scanf("%d",&key);
                int result = binary_search(a, 0, n - 1, key);
                if (result == -1) {
                 printf("Element %d is not present in the array.\n", key);
                } else {
                printf("Element %d found at index %d.\n", key, result);
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