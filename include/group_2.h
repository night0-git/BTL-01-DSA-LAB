#include <vector>
#include "helper.h"
using std::vector;

// Heap sort
void heapify(vector<int>& arr, int n, int i);
void heapSort(vector<int>& arr);

// Merge sort
void merge(vector<int>& arr, int l, int m, int r);
void mergeSort(vector<int>& arr, int l, int r);

// Natural merge sort
void reverse(vector <int>& arr, int start, int end);
void merge(vector <int>& arr, int left, int mid, int right, vector <int>& temp);
void naturalMergeSort(vector <int>& arr);

// Quick sort
void quickSort(vector<int>& arr, int l, int r);

// std::sort
void sortRecursive(vector <int>& arr,int left, int right, int limit);
void stdsort(vector<int>& arr);