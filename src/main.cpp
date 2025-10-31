#include "../include/vector.hpp"
#include <iostream>

int main() {
    my_vector<int> custom_vector = {1, 2, 3, 4, 5};

    std::cout << "my vector size: " << custom_vector.size() << std::endl;
    std::cout << "my vector total capacity: " << custom_vector.capacity() << std::endl;

    std::cout << "my vector front reference: " << custom_vector.front() << std::endl;
    std::cout << "my vector back reference: " << custom_vector.back() << std::endl;

    for (size_t i = 0; i < custom_vector.size(); i++) {
        std::cout << "index " << i << " = " << custom_vector.index(i) << std::endl;
    }

    return 0;
}
