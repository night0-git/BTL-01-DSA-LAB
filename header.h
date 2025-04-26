#include <iostream>
#include <vector>
#include <random>   // for arrayInit
#include <chrono>   // for arrayInit
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

// Helper functions
void swap (int& a, int& b);
bool isSorted (vector<int> arr);
vector<int> arrayInit(int n, int k);
int binarySearch (vector<int> arr, int value, int l, int r);
void merge (vector<int>& arr, int l, int m, int r);
void heapify (vector<int>& arr, int n, int last);
vector<int> countingSort(vector<int>& arr, int exp);
int findMax(vector<int>& arr);

// Group 1:
void selectionSort (vector<int>& arr);
void insertionSort (vector<int>& arr);
void binaryInsertionSort (vector<int>& arr);
void bubbleSort (vector<int>& arr);
void shakerSort (vector<int>& arr);
void shellSort (vector<int>& arr); 

// Group 2:
void heapSort (vector<int>& arr);
void mergeSort (vector<int>& arr, int l, int r);
void quickSort (vector<int>& arr, int l, int r);

// Group 3:
void radixSort (vector<int>& arr);
vector<int> countSort(vector<int>& arr);

// Time measurer
template <typename Func, typename... Args> double measureExecutionTime(Func func, Args &&...args) {
  auto start = std::chrono::high_resolution_clock::now();

  func(std::forward<Args>(args)...);

  auto end = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return duration.count() / 1000.0;
}