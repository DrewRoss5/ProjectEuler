#include <iostream>

int main(int argc, char** argv){
    int target {1000}, sum {0}, curr {1};
    // initialize the target
    if (argc > 1)
        target = std::atoi(argv[1]);
    // find our solution
    while (curr * 3 < target){
        sum += (curr * 3);
        if (curr < (target / 5) && curr % 3 > 0)
            sum += (curr * 5);
        curr++;

    }
    std::cout << "Result: " << sum << std::endl;
} 
