#pragma once
#ifndef LABORATOR_09_MAP_H
#define LABORATOR_09_MAP_H

#include "Pair.h"           // Include the header file that defines the Pair class
#include "MapIterator.h"    // Include the header file that defines the MapIterator class

// Define a templated Map class with key type K and value type V
template <class K, class V>
class Map {
    const static int DEFAULT_CAPACITY = 2;  // Define a constant for the default capacity of the map
    int size;               // Keep track of the number of elements in the map
    int capacity;           // Keep track of the current capacity of the map
    void resize();          // Helper function to resize the map when needed
    Pair<K, V>* pairs;      // Pointer to the array of Pair objects that represent the key-value pairs in the map

public:
    Map();                  // Default constructor that initializes the map with a default capacity and empty Pair array
    ~Map();                 // Destructor that frees the memory allocated for the Pair array
    void Set(K key, V value);           // Set a key-value pair in the map
    bool Get(const K& key, V& value);   // Get the value associated with a given key
    int Count() const;                  // Get the number of key-value pairs in the map
    void Clear();                       // Remove all key-value pairs from the map
    bool Delete(const K& key);          // Remove a key-value pair from the map by key
    bool Includes(Map<K, V>& map);      // Check if another map is included in this map
    Pair<K, V> At(int index);           // Get the key-value pair at a given index in the map
    V& operator[](const K& key);        // Access the value associated with a given key using [] operator

    MapIterator<K, V> begin();          // Get an iterator pointing to the first key-value pair in the map
    MapIterator<K, V> end();            // Get an iterator pointing to one past the last key-value pair in the map
};

template<class K, class V>
Map<K, V>::Map() : size(0), capacity(DEFAULT_CAPACITY), pairs(new Pair<K, V>[DEFAULT_CAPACITY]) {}

template<class K, class V>
Map<K, V>::~Map() {
    delete[] pairs;     // Deallocate the memory used for the Pair array
}

template<class K, class V>
void Map<K, V>::Set(K key, V value) {
    // Check if the key already exists in the map, and update the value if it does
    for (int i = 0;i < size;i++)
        if (pairs[i].key == key)
        {
            pairs[i].value = value;
            return;
        }

    // If the key does not exist, add a new key-value pair to the map
    if (size == capacity) resize();
    pairs[size++] = { key, value };
}

template<class K, class V>
void Map<K, V>::resize() {
    capacity *= 2;      // Double the current capacity
    auto* new_pairs = new Pair<K, V>[capacity];    // Allocate a new Pair array with the new capacity
    for (int i = 0;i < size;i++)                    // Copy the existing key-value pairs to the new array
        new_pairs[i] = pairs[i];
    delete[] pairs;     // Deallocate the memory used for the old Pair array
    pairs = new_pairs;  // Point the pairs pointer to the new Pair array

}

template<class K, class V>
bool Map<K, V>::Get(const K& key, V& value) {
    // loop through each element in the map
    for (int i = 0;i < size;i++)
    {
        // if the key matches the input key
        if (pairs[i].key == key)
        {
            // update the value of the pair and return true
            pairs[i].value = value;
            return true;
        }
    }
    // key not found, return false
    return false;
}

template<class K, class V>
int Map<K, V>::Count() const {
    // simply return the size of the map
    return size;
}

template<class K, class V>
void Map<K, V>::Clear() {
    // reset the size and capacity
    size = 0;
    capacity = DEFAULT_CAPACITY;
    // delete the pairs array
    delete[]pairs;
}

template<class K, class V>
bool Map<K, V>::Delete(const K& key) {
    // loop through each element in the map
    for (int i = 0;i < size;i++)
    {
        // if the key matches the input key
        if (pairs[i].key == key)
        {
            // shift all elements after this one down by one
            for (int k = i;k < size - 1;k++)
                pairs[k] = pairs[k + 1];
            // decrease the size and return true
            size--;
            return true;
        }
    }
    // key not found, return false
    return false;
}

template<class K, class V>
bool Map<K, V>::Includes(Map<K, V>& map) {
    int matches = 0;
    // loop through each element in the input map
    for (int i = 0;i < map.size;i++)
    {
        // loop through each element in this map
        for (int j = 0;j < this->size;j++)
            // if the key-value pair in the input map matches the key-value pair in this map
            if (map.At(i).key == this->pairs[j].key && map.At(i).value == this->pairs[j].value)
                matches++;
    }
    // if the number of matches equals the size of the input map, return true
    return matches == map.size;
}

template<class K, class V>
V& Map<K, V>::operator[](const K& key) {
    // loop through each element in the map
    for (int i = 0;i < size;i++)
        // if the key matches an existing key in the map, return its value
        if (pairs[i].key == key) return pairs[i].value;
    // key not found, resize the map if necessary and add the new pair
    if (size == capacity) resize();
    pairs[size++].key = key;
    return pairs[size - 1].value;
}

template<class K, class V>
MapIterator<K, V> Map<K, V>::begin() {
    // create a new iterator at the beginning of the map
    MapIterator<K, V> tmp;
    tmp.pairs = &pairs[0];
    return tmp;
}

template<class K, class V>
MapIterator<K, V> Map<K, V>::end() {
    // create a new iterator at the end of the map
    MapIterator<K, V> tmp;
    tmp.pairs = &pairs[this->size];
    return tmp;
}

// Returns the Pair at the given index in the Map's internal array.
// Assumes that the index is within the bounds of the array.
// The Pair contains both the key and the value of the element at the given index.
template<class K, class V>
Pair<K, V> Map<K, V>::At(int index) {
    return pairs[index];
}

#endif
