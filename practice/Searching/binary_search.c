#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void binarysearch(int* arr, int key) {
    int low = 0;
    int high = 9;  
    int mid = (low + high) / 2;
    
    while (low <= high) {
        if (arr[mid] == key) {
            printf("Element found at pos %d\n", mid);
            return;
        }
        else if (arr[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
        mid = (low + high) / 2; 
    }
    printf("Element not found\n");
}

int main() {
    printf("\nBinary Search\n");
    
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};  
    printf("\nGiven array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    int key;
    printf("\nEnter key value: ");
    scanf("%d", &key);
    
    binarysearch(arr, key);  
    
    return 0;
}
