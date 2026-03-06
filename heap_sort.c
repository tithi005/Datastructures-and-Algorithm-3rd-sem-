#include<stdio.h>
#include<stdlib.h>

void array_input(int a[],int n){
    printf("\nEnter %d elements into the array",n);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&a[i]);
    }
}

void array_display(int a[],int n){
    printf("\nThe sorted array is ...\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int arr[], int n, int i) {
    int largest = i;       
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0);   
    }
}

int main(){
    int x,v; int n;
    int a[100];
    printf("\n------MENU------\n");
    printf("\n1.array input");
    printf("\n2.array display");
    printf("\n3.sort the array using merge sort:");
    printf("\n4.exit");
    while(1){
        printf("\nEnter your choice:");
        scanf("%d",&x);
        switch(x){
            case 1:{
                printf("Enter the size of the array:");
                scanf("%d",&n);
                array_input(a,n);
                break;
            }
            case 2:{
                array_display(a,n);
                break;
            }
            case 3:{
               heapSort(a, n);
                printf("\nThe Array is sorted using heap sort\n");
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