#include "group_1.h"

// Selection sort
void selectionSort (vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

// Insertion sort
void insertionSort (vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int index = i;
        int value = arr[i];
        while (index > 0 && arr[index - 1] > value) {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = value;
    }
}

// Binary insertion sort
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

void binaryInsertionSort (vector<int>& arr) {
    int n = arr.size();
    int i, j, ValueToInsert, index;
    for (int i = 1; i < n; i++) {
        ValueToInsert = arr[i];
        j = i - 1;
        index = binarySearch(arr, ValueToInsert, 0, j);
        while (j >= index) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = ValueToInsert;
    }
}

// Bubble Sort
void bubbleSort (vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Shaker sort
void shakerSort (vector<int>& arr) {
    int l = 0, r = arr.size() - 1;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = l; i < r; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                flag = true;
            }
        }
        r--;
        if (flag == false) {
            break;
        }
        flag = false;
        for (int i = r; i > l; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                flag = true;
            }
        }
        l++;
        if (flag == false) {
            break;
        }
    }
}

// Shell sort
void shellSort (vector<int>& arr) {
    int n = arr.size();
    int interval, i, j;
    for(interval = n/2; interval > 0; interval /= 2) {
        for(i = interval; i < n; i++){
            int swap_value = arr[i];
            for(j = i; j >= interval && arr[j - interval] > swap_value; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = swap_value;
        }
    }
}