#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void exch(int *, int, int);
void insertionSort(int *, int);
void selectionSort(int *, int);
void bubbleSort(int *, int);
void mergeSort(int *, int);
void quickSort(int *, int, int);
void heapSort(int *, int);
void outputArr(int *, int);

int main() {
    srand(time(NULL));
    int n = 20;
    int arr[n];
    for(int i = 0; i < n; i++) arr[i] = rand()%100 + 1;
    outputArr(arr, n);
    quickSort(arr, 0, n-1);
    outputArr(arr, n);
    return 0;
}

void insertionSort(int *arr, int size) {
    int pos, k, temp;
    for(k = 1; k < size; k++) {
        temp = arr[k];
        pos = k;
        while((pos > 0) && (arr[pos-1] > temp)) {
            arr[pos] = arr[pos-1];
            pos--;
        }
        arr[pos] = temp;
    }
}

void selectionSort(int *arr, int size) {
    int i, j, min, tmp;
    for(i = 0; i < size-1; i++) {
        min = i;
        for(j = i+1; j <= size-1; j++)
            if(arr[j] < arr[min])
                min = j;
        exch(arr, i, min);
    }
}

void bubbleSort(int arr[], int size) {
    int check = 1;
    for(int i = 0; i < size-1; i++) {
        check = 1;
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                exch(arr, j, j+1);
                check = 0;
            }
        }
        if(check) break;
    }
}

// void mergeSort(int *, int) {
    // hihi
// }

void quickSort(int *arr, int l, int r) {
    int pivot, i, j, temp;
    if(l >= r) return;
    i = l;
    j = r+1;
    pivot = arr[l];
    do {
        do i++; while(arr[i] < pivot);
        do j--; while(arr[j] > pivot);
        if(i < j) exch(arr, i, j);
    } while(i < j);
    exch(arr, l, j);
    quickSort(arr, l, j-1);
    quickSort(arr, j+1, r);
}

// void heapSort(int *, int) {
//     //hihi
// }

void exch(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void outputArr(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        if(i != 0 && i%10 == 0) printf("\n");
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}