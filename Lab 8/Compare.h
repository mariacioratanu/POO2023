//this class allows the priority queue to sort its elements in descending order by the value of the integer associated with each key-value pair
//when the priority queue is constructed, an instance of this class is passed as a template argument to the priority queue to define how the elements should be sorted
#pragma once
#include <utility> //for std::pair
#include <string>

using std::pair;
using std::string;

//defines a class Compare with a single method operator()
class Compare
{
  public: //the operator() method takes two arguments -> two key-value pairs where the key is a string and the value is an integer:
    //returns a true or false, indicating whether the first pair is greater than the second pair
    bool operator()(const pair<string, int>& pairOne, const pair<string, int>& pairTwo);
};
