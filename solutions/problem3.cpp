#include <iostream>
#include <math.h>
#include <stdint.h>

uint32_t max_prime_factor(size_t n) {
    uint32_t max_factor = (n % 2 == 0 && n != 2) ? 2 : 1;
    for (uint32_t i = 3; i < sqrt(n) + 1; i += 2) {
        if (n % i == 0 && max_prime_factor(i) == 1)
            max_factor = i;
    }
    return max_factor;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: This program expects at least one argument.";
        return 1;
    }
    uint32_t max_factor;
    size_t target;
    for (int i = 1; i < argc; i++) {
        try {
            target = std::stoul(argv[i]);
        }
        catch (...) {
            std::cerr << "Invalid integer input: " << argv[i] << std::endl;
            continue;
        }
        max_factor = max_prime_factor(target);
        if (max_factor == 1)
            std::cout << target << " is prime." << std::endl;
        else
            std::cout << target << ": " << max_factor << std::endl;
    }
    return 0;
}