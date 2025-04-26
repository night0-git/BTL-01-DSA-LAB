#include "header.h"

// swap 2 numbers
void swap (int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// check if array is sorted
bool isSorted (vector<int> arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// array generator
std::vector<int> arrayInit(int n, int k) {
    std::vector<int> arr;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, k);
    for (int i = 0; i < n; i++) {
        int val;
        val = distrib(gen);
        arr.push_back(val);
    }
    return arr;
}

// helper for binaryInsertionSort
int binarySearch (vector<int> arr, int value, int l, int r) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == value) {
            return mid + 1;
        }
        else if (arr[mid] < value) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return l;
}

// helper for mergeSort
void merge (vector<int>& arr, int l, int m, int r) {
    vector<int> x(arr.begin() + l, arr.begin() + m + 1);
    vector<int> y(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0;
    while (i < x.size() && j < y.size()){
        if(x[i] <= y[j]){
            arr[l] = x[i]; i++; l++;
        }
        else{
            arr[l] = y[j]; j++; l++;
        }
    }
    while (i < x.size()){
        arr[l] = x[i]; i++; l++;
    }
    while (j < y.size()){
        arr[l] = y[j]; j++; l++;
    }
}

// helper for heapSort
void heapify (vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
// helper for radixSort
vector<int> countingSort(vector<int>& arr, int exp) {
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
    return res;
}

// helper for radixSort
int findMax(vector<int>& arr) {
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}
