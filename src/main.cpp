#include "../include/vector.hpp"
#include <iostream>

int main() {
    my_vector<int> test_vector(2);

    std::cout << "my vector size: " << test_vector.size() << std::endl;
    std::cout << "my vector total capacity: " << test_vector.capacity() << std::endl;

    for (size_t i = 0; i < test_vector.size(); i++) {
        std::cout << "index " << i << " = " << test_vector.index(i) << std::endl;
    }

    return 0;
}
