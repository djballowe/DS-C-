#include "../include/vector.hpp"
#include <iostream>

int main() {
    my_vector<std::string> custom_vector;
    std::string v_string = "test-string";
    std::string v_string_2 = "test-string-2";

    custom_vector.push_back(v_string);
    custom_vector.push_back(v_string_2);

    for (size_t i = 0; i < custom_vector.size(); i++) {
        std::cout << custom_vector.index(i) << std::endl;
    }

    custom_vector.clear();

    std::cout << custom_vector.index(1) << std::endl;

    return 0;
}
