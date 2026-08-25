#include <iostream>
#include <cstddef>

size_t sum_square(size_t n) {
    size_t sum = (n + n * n) / 2;
    return sum * sum;
}

size_t square_sum(size_t n) {
    size_t sum = 1;
    for (int i = 2; i <= n; i++) 
        sum += i * i;
    return sum;

}

int main() {
    std::cout << sum_square(100) - square_sum(100) << std::endl;
    return 0;
}