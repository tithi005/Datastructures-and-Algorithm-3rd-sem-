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

void merge(int a[],int start , int mid , int end){
    int j = mid+1 , i = start;
    int temp[100];
    while(i<=mid && j<=end){
        if(a[i]<=a[j]){
            temp[i+j-mid-1] = a[i];
            i++;
        } else{
            temp[i+j-mid-1] = a[j];
            j++;
        }
    }
    while(i<=mid){
        temp[i+j-mid-1] = a[i];
        i++;
    }
    while(j<=end){
        temp[i+j-mid-1] = a[j];
        j++;
    }
    for(i=start;i<=end;i++){
        a[i] = temp[i];
    }
}

void merge_sort(int a[], int start , int end){
    int mid;
    if(start<end){
        mid = (start+end)/2;
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge(a,start,mid,end);
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
                merge_sort(a,0,n-1);
                printf("\nThe Array is sorted using merge sort\n");
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