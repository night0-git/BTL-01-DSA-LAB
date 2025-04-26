#include "group_2.h"
#include "group_1.h" // use insertionSort for std::sort

// Heap sort
void heapify(vector<int>& arr, int n, int i) {
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

void heapSort(vector<int>& arr) {
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
void merge (vector<int>& arr, int l, int m, int r) {
    vector<int> x(arr.begin() + l, arr.begin() + m + 1);
    vector<int> y(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] <= y[j]) {
            arr[l] = x[i]; i++; l++;
        }
        else {
            arr[l] = y[j]; j++; l++;
        }
    }
    while (i < x.size()) {
        arr[l] = x[i]; i++; l++;
    }
    while (j < y.size()) {
        arr[l] = y[j]; j++; l++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Natural merge sort
void reverse(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp) {
    int i = left;
    int j = mid + 1;
    int index = 0;

    while (i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[index] = arr[i];
            i++;
        }
        else {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }

    while (i <= mid) {
        temp[index] = arr[i];
        index++;
        i++;
    }

    while (j <= right) {
        temp[index] = arr[j];
        index++;
        j++;
    }

    for (int i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

void naturalMergeSort(vector<int>& arr) { 
    int n = arr.size();
    if (n <= 1) {
        return;
    }
    
    bool sorted = false;
    vector<int> temp(n);
    
    while (!sorted) {
        int i = 0;
        int num = 0;
        vector<int> start(n);
        vector<int> end(n);
        
        while (i < n) {
            start[num] = i;

            if (i + 1 < n && arr[i] <= arr[i + 1]) {
                while (i + 1 < n && arr[i] <= arr[i + 1]) {
                    i++;
                }
            }
            else if (i + 1 < n && arr[i] > arr[i + 1]) {
                while (i + 1 < n && arr[i] > arr[i + 1]) {
                    i++;    
                }
                reverse(arr, start[num], i);
            }
            
            end[num] = i;
            num++;
            i++;
        }
        
        if (num == 1) {
            sorted = true;
            continue;
        }

        for (int width = 1; width < num; width *= 2) {
            for (int k = 0; k < num; k += 2 * width) {
                int left = start[k];
                int mid = end[k + width - 1];
                int right = (k + 2*width - 1 < num) ? end[k + 2*width - 1] : end[num - 1];
                
                if (mid < right) {
                    merge(arr, left, mid, right, temp);
                }
            }
        }
    }
}

// Quick sort
void quickSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int i = l, j = r;
        int pivot = arr[l + (r - l) / 2];
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

// std::sort
void sortRecursive(vector <int>& arr,int left, int right, int limit) {
    int size = right - left + 1;   
    if (size <= 16) {
        insertionSort(arr);
        return;
    }   

    if (limit == 0) {
        heapSort(arr);
        return;
    }

    if(left < right) {
        quickSort(arr, left, right);
    }
}

void stdsort(vector<int>& arr) {
    int limit = 2 * log2(arr.size());
    sortRecursive(arr, 0, arr.size()-1, limit);
}