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