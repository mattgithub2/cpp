#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <initializer_list>
#include <ostream>
#include "vector_iterator.h"


template <typename Tp, typename Alloc = std::allocator<Tp>>
class vector {
public:
    typedef Tp value_type;
    typedef Alloc allocator_type;
    typedef std::size_t size_type;
    typedef const value_type& const_reference;
    typedef value_type& reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef vector_iterator<vector<value_type>> iterator;
    typedef vector_iterator<vector<value_type>> const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::ptrdiff_t difference_type;

public:
    // Constructors.
    vector(size_type sz = 0) : m_size(0), m_capacity(sz), m_data(nullptr) {}

    vector(size_type sz, value_type elem) : m_size(sz), m_capacity(sz), m_data(new Tp[sz]){
        std::fill(m_data, m_data+m_size, elem);
    }
    vector(std::initializer_list<Tp> l) : m_size(l.size()), m_capacity(l.size()), m_data(new Tp[m_size]){
            std::copy(l.begin(), l.end(), m_data);
    }
    vector(const vector<Tp>& rhs) : m_size(rhs.size()), m_capacity(rhs.capacity()), m_data(nullptr){
        if (m_capacity > 0) {
            m_data = new Tp[rhs.m_capacity];
            std::copy(rhs.begin(), rhs.end(), m_data);
        }
    }
    vector(vector<int>&& rhs) noexcept : m_size(rhs.m_size), m_capacity(rhs.m_capacity), m_data(rhs.m_data) {
        rhs.m_size = 0;
        rhs.m_capacity = 0;
        rhs.m_data = nullptr;
    }
    vector<Tp>& operator=(const vector &rhs) {
        if (this == &rhs) {
            return *this; 
        }
        delete[] m_data;

        m_size = rhs.m_size;
        m_capacity = rhs.m_capacity;
        m_data = new Tp[m_capacity];

        std::copy(rhs.begin(), rhs.end(), m_data);

        return *this;
    }
    vector<Tp>& operator=(vector<Tp> &&rhs) noexcept {
        if (this != &rhs) {
            delete[] m_data;
            m_size = rhs.m_size;
            m_capacity = rhs.m_capacity;
            m_data = rhs.m_data;

            rhs.m_size = 0;
            rhs.m_capacity = 0;
            rhs.m_data = nullptr;
        }

        return *this;
    }

    ~vector() { delete[] m_data; }
    // Capacity.
    size_type size() const { return m_size; }
    size_type max_size() const { return m_size; }
    size_type capacity() const { return m_capacity; }
    bool empty() { return (m_size == 0); }



    void resize(size_type sz) {
        if (sz > m_size) {
            if (sz > m_capacity) {
                (sz > m_capacity * 2) ? reserve(sz) : reserve(m_capacity * 2);
            }
            size_type n_fill = sz - m_size;
            std::fill_n(m_data+m_size, n_fill, value_type());
            m_size = sz;
        } 
        if (sz < m_size) {
            for (size_type i = sz; i < m_size; ++i) {
                m_data[i].~value_type();
            }
            m_size = sz;
        }
    }
    void reserve(size_type new_capacity) { 
        if (new_capacity > m_capacity) {
            pointer new_array = new value_type[new_capacity];

            std::move(m_data, m_data+m_size, new_array);

            delete[] m_data;
            m_data = new_array;
            m_capacity = new_capacity;
        }
    }
    void shrink_to_fit() {
        if (m_size != m_capacity) {
            pointer new_array = new Tp[m_size];
            std::move(m_data, m_data+m_size, new_array);

            delete[] m_data;
            m_data = new_array;
            m_capacity = m_size;
        }
    }
    // TODO (Element access)
    value_type& operator[](size_type i) {
        return m_data[i];
    }
    const value_type& operator[](size_type i) const {
        return m_data[i];
    }

    value_type& at(size_type i) {
        // Out of bounds / sanity check
        if (i > m_size || i < 0) {
            throw(std::out_of_range("vector::at"));
        }
        return m_data[i];
    }
    value_type& 
    front()  { return m_data[0]; } 

    const value_type& 
    front() const { return m_data[0]; } 

    value_type& back()  { return m_data[m_size - 1]; } 
    const value_type& back() const { return m_data[m_size - 1]; } 



    // TODO (Modifiers)
    iterator erase(iterator pos) {
         
    }
    void push_back(value_type elem) {
        if (m_size == m_capacity) {
            (m_size > 0) ? reserve(m_capacity * 2) : reserve(1);
        } 
        m_data[m_size] = elem;
        ++m_size;
    }
    void pop_back() { 
        m_data[m_size - 1].~value_type();
        --m_size;
    }
    /*
     * Assigns n elements with value m
     * if n is greater than capacity, capacity = n, size = n
     * if n is less than capacity, capacity stays the same, size changes to n
     *
     */
    void swap(vector &other) {

        pointer tmp_data = m_data; 
        m_data = other.m_data;
        other.m_data = tmp_data;

        std::swap(m_capacity, other.m_capacity);
        std::swap(m_size, other.m_size);


    }
    void assign(size_type sz, value_type elem) {
        if (sz > m_capacity) {
            value_type* new_array(new value_type[sz]);
            m_capacity = sz;
            delete[] m_data;
            m_data = new_array;
        }

        std::fill(m_data, m_data+sz, elem);

        for (size_type i = sz; i < m_size; ++i) {
            m_data[i].~value_type();
        }

        m_size = sz;
    }
    void clear() {
        while (m_size > 0) {
            pop_back();
        }
    }

    template < typename... Args>
    iterator emplace(const_iterator position, Args&&... args) {

        // May require reallocation if container is full
       
        difference_type offset = position - begin();
        
        if (m_size == m_capacity) {
            (m_capacity > 0) ? reserve(m_capacity * 2) : reserve(1);
        }

        // Move elements to the right 
        for (ptrdiff_t i = static_cast<ptrdiff_t>(m_size); i > offset; --i) {
            m_data[i] = std::move(m_data[i - 1]);
        }

        // in place construction using placement new
        new (m_data + offset) value_type(std::forward<Args>(args)...); 

        ++m_size;

        return iterator(m_data + offset);
    }

    template <typename... Args>
    reference emplace_back(Args&&... args) {
        if (m_size == m_capacity)  {
            (m_capacity) ? reserve(m_capacity * 2 ) : reserve(1);
        }

        new (m_data + m_size) value_type(std::forward<Args>(args)...);

        ++m_size;
        return back();
    }
    iterator insert(iterator position, const value_type &T) {

        if (m_size == m_capacity) { 
            difference_type offset = position - begin();
            reserve( m_capacity > 0 ? m_capacity *2 : 1);
            position = m_data + offset;
        }
        // for (auto it = end(); it != position;) {
        //     *(it) = *(--it);
        // }
        for (iterator it = end(); it != position; --it) {
            *(it) = *(it - 1);
        }
        *position = T;
        ++m_size;
        return position;
    }

    // Iterators.
    iterator begin() { return iterator(m_data); }
    iterator end() { return iterator(m_data+m_size); }
    const_iterator begin() const { return m_data;}
    const_iterator end() const {return m_data+m_size;}
    const_iterator cbegin() const { return begin();}
    const_iterator cend() const { return end();}
    reverse_iterator rbegin() { return std::reverse_iterator<iterator>(end());}
    reverse_iterator rend() { return std::reverse_iterator<iterator>(begin());}
    const_reverse_iterator rbegin() const {return std::reverse_iterator<const_iterator>(end());}
    const_reverse_iterator rend() const { return std::reverse_iterator<const_iterator>(begin());}

private:
    size_type m_size;
    size_type m_capacity;
    pointer m_data;
};

template <typename Tp>
inline bool operator==(vector<Tp>& lhs, vector<Tp> &rhs) {
    if (lhs.m_size == rhs.m_size) {
        return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
}
template<typename Tp>
inline bool operator!=(vector<Tp>& lhs, vector<Tp>& rhs) {
    return !(lhs == rhs);
}

#endif
