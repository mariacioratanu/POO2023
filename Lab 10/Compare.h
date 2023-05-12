#pragma once

// Define a new class called "Compare"
class Compare {
public:
    // Declare a pure virtual function called "CompareElements"
    // that takes two void pointers as arguments and returns an integer
    // This function is declared pure virtual by using "= 0" at the end,
    // which means it has no implementation in this class
    virtual int CompareElements(void* e1, void* e2) = 0;
};