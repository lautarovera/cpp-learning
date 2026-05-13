#include <iostream>
#include <cstddef>   // std::size_t

struct ManagedBuffer {
    char*       data;
    std::size_t size;

    ManagedBuffer(std::size_t n) : size(n), data(new char[n]) {
        std::cout << "Buffer acquired (" << n << " bytes)\n";
    }

    ~ManagedBuffer() {
        delete[] data;
        std::cout << "Buffer released\n";
    }

    void fill(char c) {
        for (std::size_t i = 0; i < size; i++)
            data[i] = c;
    }

    char at(std::size_t i) const { return data[i]; }
};

int main() {
    std::cout << "--- entering inner block ---\n";
    {
        ManagedBuffer b(8);
        b.fill('A');
        std::cout << b.at(0) << "\n";
    }
    std::cout << "--- after inner block ---\n";

    ManagedBuffer b(4);
    b.fill('Z');
    std::cout << b.at(3) << "\n";

    std::cout << "--- end of main ---\n";
}
