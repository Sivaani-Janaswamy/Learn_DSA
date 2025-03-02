#include<stdio.h>
#include<stdlib.h>

#include <stdio.h>

void alternates(int arr[], int n) {
    for(int i = 0; i < n; i += 2) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    alternates(arr, size);
    return 0;
}