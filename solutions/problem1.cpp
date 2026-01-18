#include <iostream>

int main(int argc, char** argv){
    int target {1000}, sum {0};
    // initialize the target
    if (argc > 1)
        target = std::atoi(argv[1]);
    // find our solution
    for (int i = 0; i < target; i++){
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    std::cout << "Result: " << sum << std::endl;
    
}