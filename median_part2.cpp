#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::vector<int> nums;
    int num;

    std::cout << "Enter the numbers (press CTRL+D to stop):" << std::endl;
    while (std::cin >> num) {
        // Add the number to the list
        nums.push_back(num);

        // Sort the list
        std::sort(nums.begin(), nums.end());

        // Find the median
        double median;
        if (nums.size() % 2 == 0) {
            median = (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2.0;
        } else {
            median = nums[nums.size() / 2];
        }

        // Print the updated median
        std::cout << "[";
        for (int i = 0; i < nums.size(); i++) {
            std::cout << nums[i];
            if (i < nums.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "] " << std::fixed << std::setprecision(1) << median << std::endl;
    }

    return 0;
}
