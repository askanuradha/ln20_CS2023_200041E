#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    const int MAX_SIZE = 100; // Maximum size of the array
    int arr[MAX_SIZE]; // Declare an array to store the integers
    int size = 0; // Initialize the size of the array to 0

    std::string input;
    std::cout << "Enter the numbers separated by spaces: ";
    std::getline(std::cin, input); // Get the input as a string

    std::stringstream ss(input); // Create a stringstream object from the input string
    double num;
    while (ss >> num && size < MAX_SIZE) { // Read numbers from the stringstream and store them in the array
        arr[size++] = num;
    }

    // Sort the array
    std::sort(arr, arr + size);

    // Find the median
    double median;
    if (size % 2 == 0) { // If the size is even, find the average of the two middle elements
        median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else { // If the size is odd, take the middle element
        median = arr[size / 2];
    }

    std::cout << "The median is: " << median << std::endl;

    return 0;
}
