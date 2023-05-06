#pragma once
#ifndef LABORATOR_09_PAIR_H // Header guard to prevent redefinition errors
#define LABORATOR_09_PAIR_H

// A template class for a key-value pair
template <class K, class V>
class Pair {
public:
    K key; // A public member variable for the key
    V value; // A public member variable for the value

    // Default constructor
    Pair() {}

    // Constructor that initializes the key and value
    Pair(K key, V value) : key(key), value(value) {}
};

#endif
