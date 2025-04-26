#include "header.h"

int main() {
    std::vector<int> range = {1, 2, 4, 6, 8, 10, 12, 14, 16, 20};
    for (int num : range) {
        // Generate a random array of size 10 with values between 0 and 100
        std::vector<int> arr = arrayInit(num * 1000000, 1000000000);
        // Measure execution time 10 times and calculate the average
        double totalTime = 0.0;
        for (int i = 0; i < 5; i++) {
            // Create a copy of the array for each run
            std::vector<int> tempArr = arr;

            // Measure the time for bubbleSort
            totalTime += measureExecutionTime([&tempArr]() { quickSort(tempArr, 0, tempArr.size() - 1); });

            if (!sorted(tempArr)) {
                std::cout << "Unsorted array is detected." << std::endl;
                return 1;
            }
        }

        double averageTime = totalTime / 5.0;
        // Print the average time taken
        std::cout << "Average time taken to sort (5 runs, " << num << "*10^6 elements): " << averageTime << " ms" << std::endl;
    }
    return 0;
}