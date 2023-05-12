#pragma once

template <class T>
class ArrayIterator {
private:
    int Current; // current index in iteration
    T* Item; // pointer to the current element in iteration

public:
    ArrayIterator(); // default constructor for the iterator

    ArrayIterator& operator++(); // overloading the prefix ++ operator

    ArrayIterator& operator--(); // overloading the prefix -- operator

    bool operator=(ArrayIterator<T>& it); // overloading the = operator

    bool operator!=(ArrayIterator<T>& it); // overloading the != operator

    T* operator*(); // overloading the dereference operator *

    T* GetElement(); // function that returns the current element

};

template <class T>
inline ArrayIterator<T>::ArrayIterator() {
    Current = 0; // initialize the index to 0
}

template <class T>
inline ArrayIterator<T>& ArrayIterator<T>::operator++() {
    Current++; // increment the index
    return *this; // return the current iterator to enable chained iteration
}

template <class T>
inline ArrayIterator<T>& ArrayIterator<T>::operator--() {
    Current--; // decrement the index
    return *this; // return the current iterator to enable chained iteration
}

template <class T>
inline bool ArrayIterator<T>::operator=(ArrayIterator<T>& it) {
    return it.Item == this->Item; // return true if both iterators have the same pointer to the current item
}

template <class T>
inline bool ArrayIterator<T>::operator!=(ArrayIterator<T>& it) {
    return it.Item != this->Item; // return true if both iterators have different pointers to the current item
}

template <class T>
inline T* ArrayIterator<T>::operator*() {
    return *Item; // return pointer to the current item
}

template <class T>
inline T* ArrayIterator<T>::GetElement() {
    return Item; // return pointer to the current item
}
