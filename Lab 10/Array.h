#pragma once
#include "Compare.h"
#include "ArrayIterator.h"
#include <algorithm>

template <class T>
class Array {
private:
    T** List; // pointer list to objects of type T*

    int Capacity; // list capacity

    int Size; // number of elements in the list

    void Resize(); // function for resizing the list


public:
    Array(); // list is not allocated, Capacity and Size = 0

    ~Array(); // destructor

    Array(int capacity); // list is allocated with 'capacity' elements

    Array(const Array<T>& otherArray); // copy constructor

    T& operator[](int index); // throws exception if index is out of range

    const Array<T>& operator+=(const T& newElem); // add a T element at the end of the list and return this

    const Array<T>& Insert(int index, const T& newElem); // add an element at position index, return this. If
    // index is invalid throw an exception

    const Array<T>& Insert(int index, const Array<T> otherArray); // add a list at position index, return this.
    // If index is invalid throw an exception

    const Array<T>& Delete(
        int index); // delete an element from position index, return this. If index is invalid throw an exception

    bool operator=(const Array<T>& otherArray);

    void Sort(); // sorts using the comparison between elements from T

    void Sort(int (*compare)(const T&, const T&)); // sorts using a comparison function

    void Sort(Compare* comparator); // sorts using a comparator object

    // search functions - return the position of the element or -1 if it doesn't exist

    int BinarySearch(const T& elem); // search an element using binary search in Array

    int BinarySearch(
        const T& elem,
        int (*compare)(const T&, const T&)); // search an element using binary search and a comparison function

    int BinarySearch(const T& elem, Compare* comparator); // search an element using binary search and a comparator

    int Find(const T& elem); // search an element in Array

    int Find(const T& elem, int (*compare)(const T&, const T&)); // search an element using a comparison function

    int Find(const T& elem, Compare* comparator); // search an element using a comparator

    int GetSize(); // return Size

    int GetCapacity(); // return Capacity

    ArrayIterator<T> GetBeginIterator(); // return an iterator to the beginning of the list

    ArrayIterator<T> GetEndIterator(); // return an iterator to the end of the list

};

// called when the array's capacity is exceeded and the array's capacity is doubled and the memory is reallocated
template <class T>
inline void Array<T>::Resize() {
    Capacity = 2;
    T* NewList = new T * [Capacity];
    for (int i = 0; i < Size; i++)
        NewList[i] = List[i];
    delete[] List;
    List = NewList;
}

// Template definition for the Array class, which is a generic class for managing an array of T type elements
template <class T>
inline Array<T>::Array() : Capacity(0), Size(0) {
}

// The destructor of the Array class
template <class T>
inline Array<T>::~Array() {
    for (int i = 0; i < Size; i++)
        delete[] List[i];
    delete[] List;
}

// Constructor of the Array class, which initializes an instance of the Array class with a certain capacity
template <class T>
inline Array<T>::Array(int capacity) : Size(0), Capacity(capacity), List(new T* [capacity]) {
}

//A copy constructor that copies all the elements from otherArray into the newly created Array
template <class T>
inline Array<T>::Array(const Array<T>& otherArray) {
    for (int i = 0; i < Size; i++)
        delete[] List[i];
    delete[] List;
    Capacity = otherArray.Capacity;
    Size = otherArray.Size;
    List = new T * [Capacity];
    for (int i = 0; i < Size; i++)
        List[i] = otherArray.List[i];
}

//An overloaded subscript operator that returns a reference to the element at the given index
template <class T>
inline T& Array<T>::operator[](int index) {
    if (index < 0 || index >= Size)
        throw "Index is out of range!";
    return List[index];
}

// Adds a new element to the end of the array and returns a reference to the updated Array
template <class T>
inline const Array<T>& Array<T>::operator+=(const T& newElem) {
    if (Size == Capacity) Resize();
    List[Size++] = newElem;
    return *this;
}

//Inserts a new element at the specified index and returns a reference to the updated Array
template <class T>
inline const Array<T>& Array<T>::Insert(int index, const T& newElem) {
    if (index < 0 || index > Size)
        throw "Index is out of range!";
    if (Size == Capacity) Resize();
    for (int j = Size; j > index; j--)
        List[j] = List[j - 1];
    Size++;
    return *this;
}

//Inserts all the elements of otherArray into the Array starting at the specified index and returns a reference to the updated Array
template <class T>
inline const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray) {
    if (index < 0 || index > Size)
        throw "Index is out of range!";
    for (int i = 0; i < otherArray.Size; i++)
        this->Insert(index + i, otherArray[i]);
}

//Removes the element at the specified index and returns a reference to the updated Array
template <class T>
inline const Array<T>& Array<T>::Delete(int index) {
    if (index < 0 || index > Size)
        throw "Index is out of range!";
    delete[] List[index];
    for (int k = index; k < Size - 1; k++)
        List[index] = List[index + 1];
    Size--;
}

//Assigns the elements of otherArray to the current Array
template <class T>
inline bool Array<T>::operator=(const Array<T>& otherArray) {
    for (int i = 0;i < Size;i++) {
        this->Delete(i);
    }
    Size = Capacity = 0;
    for (int i = 0;i < otherArray.Size;i++) {
        this->Insert(i, otherArray[i]);

    }
}

//Sorts the elements of the array in ascending order using the < operator
template <class T>
inline void Array<T>::Sort() {
    for (int i = 0;i < Size - 1;i++) {
        for (int j = i + 1;j < Size;j++)
            if (List[i] > List[j]) {
                std::swap(List[i], List[j]);
            }
    }
}

//Sorts the elements of the array in ascending order using the comparison function compare
template <class T>
inline void Array<T>::Sort(int (*compare)(const T&, const T&)) {
    for (int i = 0; i < Size - 1; i++) {
        for (int j = i + 1; j < Size; j++)
            if (compare(List[i], List[j])) {
                std::swap(List[i], List[j]);
            }
    }
}

//Sorts the elements of the array in ascending order using the comparator object comparator
template <class T>
inline void Array<T>::Sort(Compare* comparator) {
    for (int i = 0; i < Size - 1; i++) {
        for (int j = i + 1; j < Size; j++)
            if (comparator->CompareElements(List[i], List[j])) {
                std::swap(List[i], List[j]);
            }
    }
}

//Searches for elem in the array using the binary search algorithm and returns its index
template <class T>
inline int Array<T>::BinarySearch(const T& elem) {
    int start = 0, end = Size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (List[mid] == elem)
            return mid;
        else if (List[mid] < elem)
            start = mid + 1;
        else
            end = mid - 1;
    }
}

//Searches for elem in the array using the binary search algorithmand the comparison function compare, and returns its index
template <class T>
inline int Array<T>::BinarySearch(const T& elem, int (*compare)(const T&, const T&)) {
    int start = 0, end = Size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (compare(List[mid], elem) == 0)
            return mid;
        else if (compare(List[mid], elem) == -1)
            start = mid + 1;
        else
            end = mid - 1;
    }
}

//Searches for elem in the array using the binary search algorithm and the comparator object comparator, and returns its index
template <class T>
inline int Array<T>::BinarySearch(const T& elem, Compare* comparator) {
    int start = 0, end = Size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (comparator->CompareElements(List[mid], elem) == 0)
            return mid;
        else if (comparator->CompareElements(List[mid], elem) == -1)
            start = mid + 1;
        else
            end = mid - 1;
    }
}

//Searches for the first occurrence of elem in the array and returns its index, or -1 if it is not found
template <class T>
inline int Array<T>::Find(const T& elem) {
    for (int i = 0; i < Size; i++)
        if (List[i] == elem)
            return i;
    return -1;
}

//Searches for the first occurrence of elem in the array using the comparison function compare and returns its index, or -1 if it is not found
template <class T>
inline int Array<T>::Find(const T& elem, int (*compare)(const T&, const T&)) {
    for (int i = 0; i < Size; i++)
        if (compare(List[i], elem))
            return i;
    return -1;
}

//Template function that finds an element in an array and returns its index
template <class T>
inline int Array<T>::Find(const T& elem, Compare* comparator) {
    for (int i = 0; i < Size; i++)
        if (comparator->CompareElements(List[i], elem))
            return i;
    return -1;
}

//Template function that returns the size of the array
template <class T>
inline int Array<T>::GetSize() {
    return Size;
}

//Template function that returns the capacity of the array
template <class T>
inline int Array<T>::GetCapacity() {
    return Capacity;
}

//Template function that returns an ArrayIterator pointing to the first element of the array
template <class T>
inline ArrayIterator<T> Array<T>::GetBeginIterator() {
    ArrayIterator tmp;
    tmp.Item = &List[0];
    return tmp;
}

//Template function that returns an ArrayIterator pointing to the element one past the last element of the array
template <class T>
inline ArrayIterator<T> Array<T>::GetEndIterator() {
    ArrayIterator tmp;
    tmp.Item = &List[Size];
    return tmp;
}



