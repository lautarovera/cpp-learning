#include <iostream>

// TODO: implement ManagedBuffer
// - constructor(int size): allocate, print "Buffer acquired (N bytes)"
// - destructor: release, print "Buffer released"
// - void fill(char c): fill every byte with c
// - char at(int i) const: return byte at index i

struct ManagedBuffer {
    // your fields here
    std::size_t data_size;
    char *data;

    // your methods here
    ManagedBuffer(std::size_t size) : data_size(size), data(new char[size]) {
        std::cout << "Buffer acquired (" << size << " bytes)\n";
    }

    ~ManagedBuffer() {
        delete [] data;
        std::cout << "Buffer released\n";
    }

    void fill(char c) {
        for (unsigned int i = 0; i < data_size; i++)
        {
            data[i] = c;
        }
    }

    char at(int i) const
    {
        return data[i];
    }
};

int main() {
    std::cout << "--- entering inner block ---\n";
    {
        // TODO: create a ManagedBuffer of 8 bytes
        // fill it with 'A', print at(0)
        // let it go out of scope here
        ManagedBuffer buffer(8);
        buffer.fill('A');
        std::cout << buffer.at(0) << "\n";
    }
    std::cout << "--- after inner block ---\n";

    // TODO: create another ManagedBuffer of 4 bytes, fill with 'Z', print at(3)
    // it should destruct when main returns

    ManagedBuffer another_buffer(4);
    another_buffer.fill('Z');
    std::cout << another_buffer.at(3) << "\n";

    ManagedBuffer a(8);
    ManagedBuffer b = a; 

    std::cout << "--- end of main ---\n";
}
