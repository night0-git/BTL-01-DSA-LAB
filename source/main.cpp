#include <iostream>
#include "group_1.h"
#include "group_2.h"
#include "group_3.h"
#include "helper.h"
#include "measureTime.h"
using std::cout, std::endl;

int main() {
    vector<int> range = {1, 2, 4, 6, 8, 10, 12, 14, 16, 20};
    for (int num : range) {
        // Generate a random array of size n with values between 0 and k
        vector<int> arr = arrayInitNearlySorted(num * 1000000, 1000000000);

        // Measure execution time 5 times and calculate the average
        double totalTime = 0.0;
        for (int i = 0; i < 5; i++) {
            // Create a copy of the array for each run
            vector<int> tempArr = arr;

            // Measure time
            totalTime += measureExecutionTime([&tempArr]() { radixSort(tempArr); });

            // Check if array is sorted successfully
            if (!isSorted(tempArr)) {
                cout << "Unsorted array detected." << endl;
                return 1;
            }
        }

        double averageTime = totalTime / 5.0;

        // Print the average time taken
        cout << "Average time taken to sort (5 runs, " << num << "*10^6 elements): " << averageTime << " ms" << endl;
    }
    return 0;
}