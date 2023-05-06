#pragma once

#ifndef LABORATOR_09_MAPITERATOR_H
#define LABORATOR_09_MAPITERATOR_H

#include "Pair.h"

// This class extends the Pair class by including an index attribute.
// This index is used to keep track of the position of a pair in the Map's pairs array.
template <class K, class V>
class ExtendedPair {
public:
    K key;
    V value;
    int index;
    ExtendedPair() {}
    ExtendedPair(const K& k, const V& v, int i) : key(k), value(v), index(i) {}
};

// This class provides an iterator for the Map class.
template <class K, class V>
class MapIterator {
public:
    Pair<K, V>* pairs;  // Pointer to the pairs array of the Map
    int index;  // Current index of the iterator

    // Default constructor for the MapIterator class
    MapIterator();

    // Overloads the prefix increment operator (++)
    // Moves the iterator to the next pair in the Map's pairs array
    MapIterator<K, V>& operator++();

    // Overloads the inequality operator (!=)
    // Compares two MapIterators by comparing their pairs pointers
    bool operator!=(MapIterator<K, V>& it);

    // Overloads the dereference operator (*)
    // Returns an ExtendedPair object containing the current Pair object and its index
    ExtendedPair<K, V> operator*();
};

// Definition of the prefix increment operator (++), which moves the iterator to the next pair in the Map's pairs array
template<class K, class V>
MapIterator<K, V>& MapIterator<K, V>::operator++() {
    pairs++;  // Moves the pointer to the next Pair object
    index++;  // Increases the index of the iterator
    return *this;
}

// Definition of the default constructor for the MapIterator class
template<class K, class V>
MapIterator<K, V>::MapIterator() {
    index = 0;
}

// Definition of the inequality operator (!=), which compares two MapIterators by comparing their pairs pointers
template<class K, class V>
bool MapIterator<K, V>::operator!=(MapIterator<K, V>& it) {
    return it.pairs != this->pairs;
}

// Definition of the dereference operator (*), which returns an ExtendedPair object containing the current Pair object and its index
template<class K, class V>
ExtendedPair<K, V> MapIterator<K, V>::operator*() {
    return ExtendedPair<K, V>{ pairs->key, pairs->value, index };
}

#endif
