#pragma once

template <typename T>
class my_vector {
    public: 
        my_vector(T val);

        int size() const;

    private:
        int* init;
        

};

template <typename T>
my_vector<T>::my_vector(T val) : init([](T v) {
    return new int[v];
}(val)) {
}

template <typename T>
int my_vector<T>::size() const {
    return this->init[0];
}
