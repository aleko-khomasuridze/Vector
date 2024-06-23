#ifndef VECTOR_H
#define VECTOR_H

#include <Arduino.h>

#define DEBUG_MODE

/**
 * @brief A dynamic array (vector) class template for Arduino.
 * 
 * This class provides a simple implementation of a dynamic array (vector) with basic functionalities 
 * such as adding, removing, editing elements, and iterating over the elements. The class also supports 
 * debugging features that can be enabled with the DEBUG_MODE macro.
 * 
 * @tparam T The type of elements stored in the vector.
 */
template<typename T>
class vector {
public:
    vector();
    ~vector();
    
    /**
     * @brief Adds a new element to the end of the vector.
     * 
     * @param value The element to be added.
     */
    void PushBack(const T &value);

    /**
     * @brief Finds the index of the first occurrence of the specified element.
     * 
     * @param value The element to search for.
     * @return size_t The index of the element if found, otherwise -1.
     */
    size_t IndedxOf(const T &value);

    /**
     * @brief Removes the first occurrence of the specified element from the vector.
     * 
     * @param value The element to be removed.
     */
    void Remove(const T &value);

    /**
     * @brief Removes the element at the specified index from the vector.
     * 
     * @param index The index of the element to be removed.
     */
    void Remove(size_t index);

    /**
     * @brief Replaces the first occurrence of the specified element with a new value.
     * 
     * @param value The element to be replaced.
     * @param newValue The new value to replace the old element.
     */
    void Edit(const T &value, const T &newValue);

    /**
     * @brief Replaces the element at the specified index with a new value.
     * 
     * @param index The index of the element to be replaced.
     * @param newValue The new value to replace the old element.
     */
    void Edit(size_t index, const T &newValue);

    #if defined(DEBUG_MODE)
    /**
     * @brief Prints all elements in the vector to the specified stream.
     * 
     * @param console The stream to print the elements to (e.g., Serial).
     */
    void PrintAll(Stream& console);
    #endif

    /**
     * @brief Accesses the element at the specified index.
     * 
     * @param index The index of the element to access.
     * @return T& A reference to the element at the specified index.
     */
    T& operator[](size_t index);

    /**
     * @brief Accesses the element at the specified index (const version).
     * 
     * @param index The index of the element to access.
     * @return const T& A constant reference to the element at the specified index.
     */
    const T& operator[](size_t index) const;

    /**
     * @brief Gets the current number of elements in the vector.
     * 
     * @return size_t The number of elements in the vector.
     */
    size_t size() const;

    /**
     * @brief Clears all elements from the vector.
     */
    void clear();

    class iterator {
    public:
        iterator(T* ptr) : ptr(ptr) {}

        T& operator*() {
            return *ptr;
        }

        iterator& operator++() {
            ptr++; return *this;
        }

        bool operator!=(const iterator& other) const {
            return ptr != other.ptr;
        }

    private:
        T* ptr;
    };

    iterator begin() {
        return iterator(data);
    }
    iterator end() {
        return iterator(data + currentSize);
    }

    class const_iterator {
    public:
        const_iterator(const T* ptr) : ptr(ptr) {}

        const T& operator*() const {
            return *ptr;
        }

        const_iterator& operator++() {
            ptr++; return *this;
        }

        bool operator!=(const const_iterator& other) const {
            return ptr != other.ptr;
        }

    private:
        const T* ptr;
    };

    const_iterator begin() const { return const_iterator(data); }
    const_iterator end() const { return const_iterator(data + currentSize); }

private:
    T* data;
    size_t capacity;
    size_t currentSize;

    /**
     * @brief Increases the capacity of the vector when it is full.
     */
    void increaseCapacity();
};

#endif // VECTOR_H
