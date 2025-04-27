#include "helper.h"

// swap two numbers
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

// generate a random array
vector<int> arrayInitRandom(int n, int k) {
    vector<int> arr;
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

// generate a sorted array
vector<int> arrayInitSorted(int n, int k) {
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(static_cast<int>(static_cast<long long>(i) * k / (n - 1)));
    }
    return arr;
}

// generate a reverse sorted array
vector<int> arrayInitReverseSorted(int n, int k) {
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(k - static_cast<int>(static_cast<long long>(i) * k / (n - 1)));
    }
    return arr;
}

// generate a nearly sorted array
vector<int> arrayInitNearlySorted(int n, int k) {
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        long long val = static_cast<long long>(i) * k / (n - 1);
        arr.push_back(static_cast<int>(val));
    }

    std::random_device rd;
    std::default_random_engine rng(rd());
    std::uniform_int_distribution<int> dist(0, n - 1);

    // swap 5% of elements
    int swapCount = n / 20;
    for (int i = 0; i < swapCount; i++) {
        int x = dist(rng);
        int y = dist(rng);
        swap(arr[x], arr[y]);
    }

    return arr;
}
