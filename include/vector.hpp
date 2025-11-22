#pragma once
#include <cstring>
#include <initializer_list>
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
    // add r value push back

    void clear();

  private:
    std::allocator<T> block;
    T *head;
    size_t m_capacity;
    size_t v_length;

    void add_element_no_resize(const T &val);
    void add_element_resize(const T &val);
};

template <typename T> my_vector<T>::my_vector() : block(), head(nullptr), v_length(0), m_capacity(0) {}

template <typename T>
my_vector<T>::my_vector(std::initializer_list<T> vals)
    : block(), head(block.allocate(vals.size() * 2)), v_length(vals.size()), m_capacity(vals.size() * 2) {
    size_t idx = 0;
    for (const T &val : vals) {
        block.construct(head + (idx++), val);
    }
}

template <typename T> my_vector<T>::~my_vector() {
    for (size_t i = 0; i < this->v_length; i++) {
        this->block.destroy(this->head + i);
    }
    block.deallocate(this->head, this->m_capacity);
}

template <typename T> size_t my_vector<T>::size() const { return this->v_length; }

template <typename T> size_t my_vector<T>::capacity() const { return this->m_capacity; }

template <typename T> T &my_vector<T>::index(int idx) const { return *(this->head + idx); }

template <typename T> T &my_vector<T>::back() const { return *(this->head + this->v_length - 1); }

template <typename T> T &my_vector<T>::front() const { return *(this->head); }

template <typename T> void my_vector<T>::pop_back() {
    this->block.destroy(this->head + this->v_length - 1);
    this->v_length--;
}

template <typename T> void my_vector<T>::push_back(const T &val) {
    if (this->v_length != this->m_capacity) {
        this->add_element_no_resize(val);
    } else {
        this->add_element_resize(val);
    }
    return;
}

template <typename T> void my_vector<T>::clear() {
    std::destroy(this->head, this->head + this->v_length);
    this->v_length = 0;
}

// private helpers
template <typename T> void my_vector<T>::add_element_no_resize(const T &val) {
    this->v_length++;
    block.construct(this->head + this->v_length - 1, val);
}

template <typename T> void my_vector<T>::add_element_resize(const T &val) {
    std::allocator<T> new_block;
    size_t new_cap = this->m_capacity == 0 ? 2 : this->m_capacity * 2;
    T *new_head = new_block.allocate(new_cap);

    std::uninitialized_move(this->head, this->head + this->v_length, new_head);

    for (size_t i = 0; i < this->v_length; i++) {
        this->block.destroy(this->head + i);
    }
    this->block.deallocate(this->head, this->m_capacity);

    this->block = new_block;
    this->head = new_head;
    this->m_capacity = new_cap;
    this->v_length++;
    block.construct(this->head + this->v_length - 1, val);

    return;
}
