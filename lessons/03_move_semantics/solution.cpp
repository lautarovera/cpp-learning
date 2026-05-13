#include <iostream>
#include <cstddef>
#include <cstring>

// Rule of Five — manual resource management (the low-level building block)
struct ManagedBuffer {
    std::size_t size;
    char*       data;

    ManagedBuffer(std::size_t n) : size(n), data(new char[n]) {
        std::cout << "constructed (" << n << " bytes)\n";
    }
    ~ManagedBuffer() {
        delete[] data;
        std::cout << "destructed\n";
    }
    ManagedBuffer(const ManagedBuffer& o) : size(o.size), data(new char[o.size]) {
        std::memcpy(data, o.data, size);
        std::cout << "copy constructed (" << size << " bytes)\n";
    }
    ManagedBuffer& operator=(const ManagedBuffer& o) {
        if (this != &o) {
            delete[] data;
            size = o.size;
            data = new char[o.size];
            std::memcpy(data, o.data, size);
            std::cout << "copy assigned (" << size << " bytes)\n";
        }
        return *this;
    }
    ManagedBuffer(ManagedBuffer&& o) noexcept : size(o.size), data(o.data) {
        o.size = 0; o.data = nullptr;
        std::cout << "move constructed (" << size << " bytes)\n";
    }
    ManagedBuffer& operator=(ManagedBuffer&& o) noexcept {
        if (this != &o) {
            delete[] data;
            size = o.size; data = o.data;
            o.size = 0;    o.data = nullptr;
            std::cout << "move assigned (" << size << " bytes)\n";
        }
        return *this;
    }

    void fill(char c) { for (std::size_t i = 0; i < size; i++) data[i] = c; }
    char at(std::size_t i) const { return data[i]; }
};

// Rule of Zero — compose from types that manage themselves; write nothing
#include <vector>
struct SafeBuffer {
    std::vector<char> data;

    SafeBuffer(std::size_t n) : data(n) {}
    void fill(char c) { for (char& x : data) x = c; }
    char at(std::size_t i) const { return data[i]; }
    // copy, move, destruct: all correct for free
};

int main() {
    ManagedBuffer a(4); a.fill('A');
    ManagedBuffer b = a;
    b.fill('B');
    std::cout << "a[0]=" << a.at(0) << " b[0]=" << b.at(0) << "\n";

    ManagedBuffer c(8); c.fill('C');
    ManagedBuffer d = std::move(c);
    std::cout << "c.size=" << c.size << " d[0]=" << d.at(0) << "\n";

    ManagedBuffer e(4); e.fill('E');
    e = std::move(d);
    std::cout << "e[0]=" << e.at(0) << "\n";
}
