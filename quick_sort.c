#include<stdio.h>
#include<stdlib.h>

void input_array(int a[], int n){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void display_array(int a[],int n){
    printf("\nThe sorted array is...\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}

int partition(int a[], int start , int end){
    int idx = start-1;
    int pivot = a[end];
    for(int j=start;j<end;j++){
        if(a[j]<=pivot){
            idx++;
            int temp = a[j];
            a[j] = a[idx];
            a[idx] = temp;
        }
    }
    idx++;
    int temp = a[end];
    a[end] = a[idx];
    a[idx] = temp;
    return idx;
}

void quick_sort(int a[], int start , int end){
    if(start<end){
        int pividx = partition(a , start , end);
        quick_sort(a , start , pividx-1);
        quick_sort(a , pividx+1 , end);
    }
}

int main(){
    int x,n;
    int a[100];
    printf("\n----MENU----\n");
    printf("\n1.array input:");
    printf("\n2.array display:");
    printf("\n3.sort elements using quicksort:");
    printf("\n4.exit");
    while(1){
        printf("\nEnter your choice:");
        scanf("%d",&x);
        switch(x){
            case 1:{
                printf("\nEnter the size of the array:");
                scanf("%d",&n);
                printf("\nEnter the elements into the array:");
                input_array(a,n);
                break;
            }
            case 2:{
                display_array(a,n);
                break;
            }
            case 3:{
                quick_sort(a,0,n-1);
                printf("\nThe elements are sorted using quick sort....\n");
                break;
            }
            case 4:{
                exit(0);
                break;
            }
            default:{
                printf("\n Invalid input !\n");
            }
        }
    }

    return 0;
}