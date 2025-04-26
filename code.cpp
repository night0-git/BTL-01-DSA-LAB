#include "header.h"
using namespace std;

// Helper function
    void swap (int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Check sorted
    bool sorted (vector<int> arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    // binaryInsertionSort
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

    // mergeSort
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

    // heapSort
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
    // radixSort
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

    int findMax(vector<int>& arr) {
        int mx = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > mx) {
                mx = arr[i];
            }
        }
        return mx;
    }

// Group 1
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

void bubbleSort (std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

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

// Group 2:
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

void mergeSort (vector<int>& arr, int l, int r) {
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

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

// Group 3
void radixSort (vector<int>& arr) {
    int mx = findMax(arr);
    for (int exp = 1; mx / exp > 0; exp *= 10) {
        arr = countingSort(arr, exp);
    }
}


vector<int> countSort (vector<int>& arr) {
    int n = arr.size();
    int M = 0;
    for (int i = 0; i < n; i++)
        M = max(M, arr[i]);
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


// Array generator
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
