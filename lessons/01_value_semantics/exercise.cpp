#include <iostream>
#include <string>
#include <vector>

// TODO 1: swap two ints using references (no pointers)
void swap_values(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// TODO 2: print a string by const reference
void describe(const std::string& s) {
    std::cout << s << std::endl;
}

// TODO 3: increment every element of the vector in place
void increment_all(std::vector<int>& v) {
    for (int& x : v)
    {
        x++;
    }
}

int main() {
    // Test swap_values
    int x = 10, y = 20;
    swap_values(x, y);
    std::cout << "x=" << x << " y=" << y << "\n";  // expected: x=20 y=10

    // Test describe
    std::string msg = "hello from C++";
    describe(msg);

    // Test increment_all
    std::vector<int> nums = {1, 2, 3, 4, 5};
    increment_all(nums);
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n";  // expected: 2 3 4 5 6
}
