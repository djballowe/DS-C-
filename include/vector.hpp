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

    void pop_back();
    void push_back(const T &val);

  private:
    std::allocator<int> block;
    int *head;
    size_t m_capacity;
    size_t v_size;

    void add_element_no_resize(T &val);
    void add_element_resize(T &val);
};

template <typename T> my_vector<T>::my_vector() : block(), head(nullptr), v_size(0), m_capacity(0) {}

template <typename T>
my_vector<T>::my_vector(std::initializer_list<T> vals)
    : block(), head(block.allocate(vals.size() * 2)), v_size(vals.size()), m_capacity(vals.size() * 2) {
    size_t idx = 0;
    for (const T &val : vals) {
        block.construct(head + (idx++), val);
    }
}

template <typename T> my_vector<T>::~my_vector() {
    for (size_t i = 0; i < this->v_size; i++) {
        this->block.destroy(this->head + i);
    }
    block.deallocate(this->head, this->m_capacity);
}

template <typename T> size_t my_vector<T>::size() const { return this->v_size; }

template <typename T> size_t my_vector<T>::capacity() const { return this->m_capacity; }

template <typename T> T &my_vector<T>::index(int idx) const { return *(this->head + idx); }

template <typename T> T &my_vector<T>::back() const { return *(this->head + this->v_size - 1); }

template <typename T> T &my_vector<T>::front() const { return *(this->head); }

template <typename T> void my_vector<T>::pop_back() {
    this->block.destroy(this->head + this->v_size - 1);
    this->v_size = this->v_size - 1;
}

template <typename T> void my_vector<T>::push_back(const T &val) {
    if (this->m_capacity != 0) {
        this->add_element_no_resize(val);
    } else {
        this->add_element_resize(val);
    }
    return;
}

// private helpers
template <typename T> void my_vector<T>::add_element_no_resize(T &val) {
    block.construct(this->head + this->v_size - 1, val);
    this->v_size++;
}
