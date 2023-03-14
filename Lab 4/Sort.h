#pragma once
#include <initializer_list>
using namespace std;
//class definition:

class Sort
{
    //add data members
    int* v;
    int size;
    int partition(int low, int high, bool ascending);
    void quickSort(int low, int high, bool ascending);

  public:
    //add contructors

    /*1. create the list that needs to be sorted out of random values within a specific
interval(min, max). The constructor will recieve 3 parameters(the number of elements
in the list, minimum value, maximum value). */
    Sort(int size, int minn, int maxx);
    /*2. create the list that needs to be sorted from an initialization list*/
    Sort(initializer_list<int> list);
    /*3. create the list that needs to be sorted from an existing vector (the constructor will have
two parameters - one being the vector, the other one being the number of elements from the vector)*/
    Sort(const int* vector, int size);
    /*4. create the list that needs to be sorted using variadic parameters (use va_args for this)*/
    Sort(int size, ...);
    /*5. create the list that needs to be sorted from a string (e.g. "10,40,100,5,70" -> each number is
separated from the rest of the number with a comma). It is assumed that the string is correctly written
(no space, only numerical characters and commas)*/
    Sort(const char* string);

    //funtions:
    
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int GetElementsCount(); //the number of elements
    int GetElementFromIndex(int index); //the element from a chosen index
};
