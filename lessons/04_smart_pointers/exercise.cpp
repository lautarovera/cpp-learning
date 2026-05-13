#include <iostream>
#include <memory>
#include <string>
#include <cstddef>

// ---------------------------------------------------------------
// Part 1: unique_ptr basics
// ---------------------------------------------------------------

// TODO: return a unique_ptr<char[]> of n bytes
std::unique_ptr<char[]> make_buffer(std::size_t n) {
    return std::make_unique<char[]>(n);
}

// A pretend C API that takes a raw pointer (doesn't own it)
void c_api_fill(char* buf, std::size_t n, char c) {
    for (std::size_t i = 0; i < n; i++) buf[i] = c;
}

// ---------------------------------------------------------------
// Part 2: Rule of Zero — rewrite ManagedBuffer with unique_ptr
// ---------------------------------------------------------------

struct ManagedBuffer {
    std::size_t size;
    // TODO: replace char* data with unique_ptr<char[]> data
    std::unique_ptr<char[]> data;

    ManagedBuffer(std::size_t n) : size(n), data(std::make_unique<char[]>(n)) {}
    // TODO: remove all five special members and let the compiler handle it
};

// ---------------------------------------------------------------
// Part 3: shared_ptr — shared ownership
// ---------------------------------------------------------------

struct Config {
    std::string value;

    Config(std::string v) : value(std::move(v)) {
        std::cout << "Config created: " << value << "\n";
    }
    ~Config() { std::cout << "Config destroyed: " << value << "\n"; }
};

struct Worker {
    std::string name;
    // TODO: hold a shared_ptr<Config>
    std::shared_ptr<Config> config;

    Worker(std::string n, std::shared_ptr<Config> cfg) : name(std::move(n)), config(std::move(cfg)) {
        config = cfg;
        std::cout << "Worker " << name << " created\n";
    }
    ~Worker() { std::cout << "Worker " << name << " destroyed\n"; }
};

// ---------------------------------------------------------------
int main() {
    std::cout << "=== Part 1 ===\n";
    // TODO: call make_buffer(8), fill via c_api_fill using .get(), read back
    auto a = make_buffer(8);
    c_api_fill(a.get(), 8, 'X');
    std::cout << a[0] << "\n";

    std::cout << "\n=== Part 2 ===\n";
    // TODO: create a ManagedBuffer, verify move works, verify copy doesn't compile
    auto b = std::move(a);

    std::cout << "\n=== Part 3 ===\n";
    // TODO: create shared Config, give to two Workers in a nested scope,
    //       destroy first worker, verify Config still alive,
    //       destroy second worker, verify Config freed
    auto cfg = std::make_shared<Config>("prod");

    {
        Worker alpha("alpha", cfg);
        {
            Worker beta("beta", cfg);
        }

        std::cout << "Config still alive: " << cfg->value << "\n";
    }
}
