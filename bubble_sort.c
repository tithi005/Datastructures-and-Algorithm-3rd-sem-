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

void bubble_sort(int a[],int n){
    int swap = 0;
    for(int i = 0;i<n;i++){
        swap = 1;
        for(int j = 0; j<n-i-1 ; j++){
            if(a[j]>a[j+1]){
                swap = 0;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

}

int main(){
    int x,v; int n;
    int a[100];
    printf("\n------MENU------\n");
    printf("\n1.array input");
    printf("\n2.array display");
    printf("\n3.sort the array using bubble sort:");
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
               bubble_sort(a, n);
                printf("\nThe Array is sorted using bubble sort\n");
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