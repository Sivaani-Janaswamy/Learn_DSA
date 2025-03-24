#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("\nLinear Search\n");
    int key;
    int arr[10] = {1,20,30,23,25,21,44,31,35,90};
    printf("\nGiven array: ");
    for(int i = 0;i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Enter element to be searched: ");
    scanf("%d",&key);
    for(int i = 0;i < 10;i++){
       if(key == arr[i]){
        printf("Found at position: %d \n ",i);
        return 0;
       }
    }
    printf("Element not found.\n");
    return 0;
}