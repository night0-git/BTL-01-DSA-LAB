#include "header.h"

// Radix sort
void radixSort (vector<int>& arr) {
    int mx = findMax(arr);
    for (int exp = 1; mx / exp > 0; exp *= 10) {
        arr = countingSort(arr, exp);
    }
}

// Counting sort
vector<int> countSort (vector<int>& arr) {
    int n = arr.size();
    int M = 0;
    for (int i = 0; i < n; i++)
        M = std::max(M, arr[i]);
    vector<int> count(M + 1, 0);
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= M; i++) {
        count[i] += count[i - 1];
    }
    vector<int> sorted(n);
    for (int i = n - 1; i >= 0; i--) {
        sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    return sorted;
}