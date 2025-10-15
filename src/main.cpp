#include "../include/vector.hpp"
#include <iostream>

int main () {
    my_vector<int> test_vector(5);

    std::cout << test_vector.size() << std::endl;

    return 0;
}
