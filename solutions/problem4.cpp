#include <iostream>
#include <vector>
#include <math.h>

bool is_palindrome(int n) {
    std::vector<unsigned char> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    size_t len = digits.size();
    for (int i = 0; i < len / 2; i++) {
        if (digits[i] != digits[len - i - 1])
            return false;
    }
    return true;
}

int max_palindrome(size_t digits) {
    size_t min = pow(10, digits - 1);
    size_t max = pow(10, digits);
    int max_pal = 0;
    for (int i = min; i < max; i++) {
        for (int j = i; j < max; j++) {
            int prod = i * j;
            if (prod > max_pal && is_palindrome(prod)) {
                max_pal = prod;
            } 
        }
    }
    return max_pal;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: this program accepts at least one argument" << std::endl; 
        return 1;
    }
    size_t digits;
    for (int i = 1; i < argc; i++) {
        try {
            digits = std::stoul(argv[i]);
        }
        catch (...) {
            std::cerr << "Invalid integer input: " << argv[i] << std::endl;
            continue;
        }
        std::cout << digits << ((digits == 1) ? " digit: " : " digits: ") << max_palindrome(digits) << std::endl;
    }
    return 0;
}