#include <iostream>
#include "Map.h"

int main()
{
    // Create a map with integer keys and constant char* values
    Map<int, const char*> m;

    // Add three key-value pairs to the map
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    // Create another map with the same key-value pairs as the first map
    Map<int, const char*> t;
    t[10] = "C++";

    // Check if the first map includes the second map
    std::cout << std::boolalpha << m.Includes(t) << "\n";

    // Iterate over the first map using a range-based for loop
    // The loop variable is a structured binding that captures
    // the key, value, and index of each key-value pair
    for (auto [key, value, index] : m)
    {
        // Print the index, key, and value of each pair
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    // Update the value of the second key in the map
    m[20] = "result";

    // Iterate over the updated map and print the key-value pairs
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    // Exit the program
    return 0;
}
