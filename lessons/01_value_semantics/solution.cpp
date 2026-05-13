#include <iostream>
#include <string>
#include <vector>
#include <utility>   // std::swap

void swap_values(int& a, int& b) {
    std::swap(a, b);
}

void describe(const std::string& s) {
    std::cout << s << "\n";
}

void increment_all(std::vector<int>& v) {
    for (int& x : v)
        x++;
}

int main() {
    int x = 10, y = 20;
    swap_values(x, y);
    std::cout << "x=" << x << " y=" << y << "\n";

    std::string msg = "hello from C++";
    describe(msg);

    std::vector<int> nums = {1, 2, 3, 4, 5};
    increment_all(nums);
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n";
}
