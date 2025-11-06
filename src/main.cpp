#include "../include/vector.hpp"
#include <iostream>

int main() {
    my_vector<int> custom_vector = {1};

    std::cout << "my vector size: " << custom_vector.size() << std::endl;
    std::cout << "my vector total capacity: " << custom_vector.capacity() << std::endl;

    std::cout << "my vector front reference: " << custom_vector.front() << std::endl;
    std::cout << "my vector back reference: " << custom_vector.back() << std::endl;

    for (size_t i = 0; i < custom_vector.size(); i++) {
        std::cout << "index " << i << " = " << custom_vector.index(i) << std::endl;
    }

    custom_vector.pop_back();
    std::cout << "pop vector" << std::endl;

    for (size_t i = 0; i < custom_vector.size(); i++) {
        std::cout << "index " << i << " = " << custom_vector.index(i) << std::endl;
    }

    int one = 1;
    int two = 2;
    int three = 3;
    custom_vector.push_back(one);
    std::cout << "push vector not at capacity" << std::endl;

    for (size_t i = 0; i < custom_vector.size(); i++) {
        std::cout << "index " << i << " = " << custom_vector.index(i) << std::endl;
    }

    custom_vector.push_back(two);
    custom_vector.push_back(three);
    std::cout << "push vector at at capacity" << std::endl;

    for (size_t i = 0; i < custom_vector.size(); i++) {
        std::cout << "index " << i << " = " << custom_vector.index(i) << std::endl;
    }

    std::cout << "my vector total capacity: " << custom_vector.capacity() << std::endl;

    return 0;
}
