#include "Array.h"
#include "Compare.h"
#include "ArrayIterator.h"
#include <iostream>
using namespace std;

int main() {
    Array<int> arr(5); // create an array of integers with capacity 5

    // Add some elements to the array using the += operator
    arr += 3;
    arr += 5;
    arr += 1;
    arr += 4;
    arr += 2;

    // Print the array using iterators
    ArrayIterator<int> itr = arr.GetBeginIterator();
    while (itr != arr.GetEndIterator()) {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;

    // Sort the array using the default comparison function
    arr.Sort();
    itr = arr.GetBeginIterator();
    while (itr != arr.GetEndIterator()) {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;

    // Search for an element using the binary search algorithm
    int index = arr.BinarySearch(4);
    if (index == -1) {
        cout << "Element not found." << endl;
    }
    else {
        cout << "Element found at index " << index << "." << endl;
    }

    // Delete an element from the array
    arr.Delete(2);
    itr = arr.GetBeginIterator();
    while (itr != arr.GetEndIterator()) {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;

    return 0;
}
