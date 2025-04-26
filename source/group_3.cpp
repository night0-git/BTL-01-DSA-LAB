#include "group_3.h"

// Radix sort
int findMax(const vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(vector<int>& arr, long long exp) {
    int n = arr.size();
    vector<int> res(n);
    vector<int> count(10, 0);
    
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        res[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = res[i];
    }
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    bool already_sorted = true;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1]) {
            already_sorted = false;
            break;
        }
    }
    if (already_sorted) return;
    
    int mx = findMax(arr);
    for (long long exp = 1; mx / exp > 0; exp *= 10) {
        if (exp > INT_MAX / 10) break;
        countingSort(arr, exp);
    }
}

// Counting sort
void countSort(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return;

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

    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }
}
