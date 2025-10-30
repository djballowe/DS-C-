#pragma once
#include <memory>

template <typename T> class my_vector {
  public:
    my_vector(T val);

    ~my_vector();

    size_t size() const;

    size_t capacity() const;

    T &index(int idx) const;

  private:
    std::allocator<int> block;
    int *head;
    size_t m_length;
    size_t length;
};

template <typename T> my_vector<T>::my_vector(T val) : block(), head(block.allocate(val * 2)), length(val), m_length() {
    this->m_length = val * 2;
    for (size_t i = 0; i < this->m_length; i++) {
        block.construct(head + i, 5);
    }
}

template <typename T> my_vector<T>::~my_vector() {
    for (size_t i = 0; i < this->length; i++) {
        this->block.destroy(this->head + i);
    }
    block.deallocate(this->head, this->m_length);
}

template <typename T> size_t my_vector<T>::size() const { return this->length; }

template <typename T> size_t my_vector<T>::capacity() const { return this->m_length; }

template <typename T> T &my_vector<T>::index(int idx) const { return *(this->head + idx); }
