#include <vector>
#include <random>
using std::vector;

// swap two elements
void swap(int& a, int& b);

// check if array is sorted
bool isSorted(vector<int> arr);

// generate a random array
vector<int> arrayInitRandom(int n, int k);

// generate a sorted array
vector<int> arrayInitSorted(int n);

// generate a reverse sorted array
vector<int> arrayInitReverseSorted(int n);

// generate a nearly sorted array
vector<int> arrayInitNearlySorted(int n, int k);