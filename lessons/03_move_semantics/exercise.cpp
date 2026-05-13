#include <iostream>
#include <cstddef>
#include <cstring>   // std::memcpy

struct ManagedBuffer {
    std::size_t size;
    char*       data;

    // Constructor
    ManagedBuffer(std::size_t n) : size(n), data(new char[n]) {
        std::cout << "constructed (" << n << " bytes)\n";
    }

    // Destructor
    ~ManagedBuffer() {
        // TODO: guard against nullptr, then delete[]
        delete [] data;
        std::cout << "destructed\n";
    }

    // TODO: copy constructor
    ManagedBuffer(const ManagedBuffer& other) : size(other.size), data(new char[other.size]) {
        std::memcpy(data, other.data, size);
        std::cout << "copy constructed (" << size << " bytes)\n";
    }

    // TODO: copy assignment
    ManagedBuffer& operator=(const ManagedBuffer& other) {
        if (this != &other)
        {
            delete [] data;
            size = other.size;
            data = new char[other.size];
            if (data != nullptr)
            {
                std::memcpy(data, other.data, size);
                std::cout << "copy assigned (" << size << " bytes)\n";
            }
        }

        return *this;
    }

    // TODO: move constructor (noexcept)
    ManagedBuffer(ManagedBuffer&& other) noexcept : size(other.size), data(other.data) {
        other.size = 0;
        other.data = nullptr;
        std::cout << "move constructed (" << size << " bytes)\n";
    }

    // TODO: move assignment (noexcept)
    ManagedBuffer& operator=(ManagedBuffer&& other) noexcept {
        if (this != &other)
        {
            delete [] data;
            size = other.size;
            data = other.data;
            other.size = 0;
            other.data = nullptr;
            std::cout << "move assigned (" << size << " bytes)\n";
        }

        return *this;
    }

    void fill(char c) {
        for (std::size_t i = 0; i < size; i++) data[i] = c;
    }

    char at(std::size_t i) const { return data[i]; }
};

int main() {
    // --- copy ---
    ManagedBuffer a(4);
    a.fill('A');
    ManagedBuffer b = a;   // copy constructor
    b.fill('B');
    std::cout << "a[0]=" << a.at(0) << " b[0]=" << b.at(0) << "\n";  // A B — independent

    // --- move ---
    ManagedBuffer c(8);
    c.fill('C');
    ManagedBuffer d = std::move(c);   // move constructor
    std::cout << "c.size=" << c.size << " d[0]=" << d.at(0) << "\n";  // 0  C

    // --- move assignment ---
    ManagedBuffer e(4);
    e.fill('E');
    e = std::move(d);   // move assignment
    std::cout << "e[0]=" << e.at(0) << "\n";  // C
}
