#include "vector.h"

template<typename T>
vector<T>::vector() : data(nullptr), capacity(0), currentSize(0) {}

template<typename T>
vector<T>::~vector() {
    delete[] data;
}

template<typename T>
void vector<T>::PushBack(const T &value) {
    if (currentSize == capacity) {
        increaseCapacity();
    }
    data[currentSize++] = value;
}

template <typename T>
size_t vector<T>::IndedxOf(const T &value) {
    for (size_t index = 0; index < currentSize; index++){
        if (data[index] == value) {
            #if defined(DEBUG_MODE)
                Serial.println("Item found on index: " + String(index));
            #endif
            return index;
        }
    }
    #if defined(DEBUG_MODE)
        Serial.println("Item not found in this vector!");
    #endif
    return -1;
}

template <typename T>
void vector<T>::Remove(const T &value) {
    size_t index = this->IndedxOf(value);
    
    for (size_t i = index; i < this->currentSize; i++) 
        data[i] = data[i+1];
     
    --this->currentSize;
}

template <typename T>
void vector<T>::Remove(size_t index) {
    if (index >= currentSize) 
        #if defined(DEBUG_MODE)
        Serial.println("Index out of range!");
        #endif
    
}

template <typename T>
void vector<T>::Edit(const T &value, const T &newValue) {
    size_t index = this->IndedxOf(value);
    data[index] = newValue;
}

template <typename T>
void vector<T>::Edit(size_t index, const T &newValue) {
    if (index >= currentSize) 
        #if defined(DEBUG_MODE)
        Serial.println("Index out of range!");
        #endif

    data[index] = newValue;
}

#if defined(DEBUG_MODE)
template <typename T>
void vector<T>::PrintAll(Stream& console) {
    for(size_t i = 0; i < currentSize; i++)
        console.println(data[i]);
}
#endif


template<typename T>
T& vector<T>::operator[](size_t index) {
    if (index >= currentSize) {
        return data[0]; // Returning first element as a fall-back scenario.
    }
    return data[index];
}

template<typename T>
const T& vector<T>::operator[](size_t index) const {
    if (index >= currentSize) {
        static const T dummy{};
        return dummy;
    }
    return data[index];
}

template<typename T>
size_t vector<T>::size() const {
    return currentSize;
}

template<typename T>
void vector<T>::increaseCapacity() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    T* newData = new T[capacity];
    for (size_t i = 0; i < currentSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

template<typename T>
void vector<T>::clear() {
    delete[] data;
    data = nullptr;
    capacity = 0;
    currentSize = 0;
}

template class vector<String>;
template class vector<char>;
template class vector<int>;
template class vector<float>;
template class vector<double>;
template class vector<bool>;
