#include <iostream>

u_int64_t even_fibs(int max){
    u_int64_t sum{2}, curr{3}, prev{2}, tmp;
    while (curr < max){
        tmp = curr + prev;
        prev = curr;
        curr = tmp;
        if (curr % 2 == 0 && curr < max)
            sum += curr;
    }
    return sum;
}

int main(int argc, char** argv){
    int target {4000000};
    // initialize the target
    if (argc > 1)
        target = std::atoi(argv[1]);
    // find our solution
    std::cout << "Result: " << even_fibs(target) << std::endl;
}   