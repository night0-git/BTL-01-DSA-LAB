#include "header.h"

// Heap sort
void heapSort (vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Merge sort
void mergeSort (vector<int>& arr, int l, int r) {
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick sort
void quickSort (vector<int>& arr, int l, int r) {
    if (l < r) {
        int i = l, j = r;
        int pivot = arr[l + (r - l)/ 2];
        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap (arr[i], arr[j]);
                i++; j--;
            }
        }
        if (i < r) {
            quickSort(arr, i, r);
        }   
        if (j > l) {
            quickSort(arr, l, j);
        }
    }   
}