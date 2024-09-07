#ifndef VECTOR_ITERATOR_H 
#define VECTOR_ITERATOR_H
#include <iterator>
template <typename vector>
class vector_iterator {
public:
        typedef typename vector::value_type value_type;
        typedef value_type* pointer;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef std::random_access_iterator_tag iterator_category;
        typedef std::ptrdiff_t difference_type;

public:


    // Accesser
    const pointer base() { return ptr; }

    // Constructors.
    vector_iterator(pointer ptr = nullptr) : ptr(ptr) {}
    vector_iterator(const vector_iterator& rhs) : ptr(rhs.ptr) {}

    // Prefix-- // Note: Should return by reference (see pg. 506)
    vector_iterator& operator++() {
        ++ptr;
        return *this;
    }
    vector_iterator operator++(int) { // Should return by value (automatically const) (see book)
        vector_iterator iterator = *this;
        ++(*this);
        return iterator;
    }

    // Postfix--
    vector_iterator& operator--(){ --ptr; return *this; }

    vector_iterator operator--(int) { // Should return by value (see book)
        vector_iterator iterator = *this;
        --(*this);
        return iterator;
    }

    // Index operator.
    reference operator[](int pos) {
        return *(ptr + pos);
    }
    const_reference operator[] (int pos) const { return *(ptr + pos); }
    pointer operator->() const {
        return ptr;
    }

    // Dereference operator.
    reference operator*() const {
        return *ptr;
    }

    // Arithmetic operators.  
    vector_iterator& operator+=(difference_type n) {
        ptr += n;
        return *this;
    }
    vector_iterator& operator-=(difference_type n) {
        ptr-= n;
        return *this;
    }
    vector_iterator operator+(difference_type n) const {
        return vector_iterator(ptr+n);
    }
    const vector_iterator operator-(difference_type n) const {
        return vector_iterator(ptr - n);
    }
    difference_type operator-(const vector_iterator& rhs) {
        return ptr - rhs.ptr;
    }

    // rhs objects
    friend vector_iterator operator+(difference_type n, const vector_iterator& rhs ) {
        return vector_iterator(rhs.ptr + n);
    }
    friend vector_iterator operator-(difference_type n, const vector_iterator& rhs) {
        return vector_iterator(rhs.ptr - n);
    }
    

    bool operator==(const vector_iterator<vector>& rhs) {
        return (ptr == rhs.ptr);
    }
    bool operator!=(const vector_iterator<vector>& rhs) {
        return !(ptr == rhs.ptr);
    }
    bool operator>(const vector_iterator<vector>& rhs) {
        return (ptr > rhs.ptr);
    }
    bool operator<(const vector_iterator<vector>& rhs) {
        return !(ptr < rhs.ptr);
    }
    bool operator>=(const vector_iterator<vector>& rhs) {
        return !(ptr >= rhs.ptr);
    }
    bool operator<=(const vector_iterator<vector>& rhs) {
        return !(ptr > rhs.ptr);
    }
private:
        pointer ptr;
};



#endif
