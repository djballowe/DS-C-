#pragma once
#include <initializer_list>
#include <iostream>
#include <memory>

template <typename T> class my_vector {
  public:
    my_vector();
    my_vector(std::initializer_list<T> vals);

    ~my_vector();

    size_t size() const;
    size_t capacity() const;

    T &index(int idx) const;

    T &front() const;
    T &back() const;

  private:
    std::allocator<int> block;
    int *head;
    size_t m_capacity;
    size_t length;
};

template <typename T> my_vector<T>::my_vector() : block(), head(nullptr), length(0), m_capacity(0) {}

template <typename T>
my_vector<T>::my_vector(std::initializer_list<T> vals)
    : block(), head(block.allocate(vals.size() * 2)), length(vals.size()), m_capacity(vals.size() * 2) {
    size_t idx = 0;
    for (const T &val : vals) {
        block.construct(head + (idx++), val);
    }
}

template <typename T> my_vector<T>::~my_vector() {
    for (size_t i = 0; i < this->length; i++) {
        this->block.destroy(this->head + i);
    }
    block.deallocate(this->head, this->m_capacity);
}

template <typename T> size_t my_vector<T>::size() const { return this->length; }

template <typename T> size_t my_vector<T>::capacity() const { return this->m_capacity; }

template <typename T> T &my_vector<T>::index(int idx) const { return *(this->head + idx); }

template <typename T> T &my_vector<T>::back() const { return *(this->head + this->length - 1); }

template <typename T> T &my_vector<T>::front() const { return *(this->head); }
