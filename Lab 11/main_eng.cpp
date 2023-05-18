//!Exactly the same code as before, I just realised too late the code had to be written in English:)

#include <iostream>
#include <vector>
#include <cassert>


//Part I: Writing

//My sorting algorithm, containing the 5 errors
//Templated Selection Sort
//(I added the comments after sending it to my colleague)
template<typename T>
void selectionSortWithErrors(std::vector<T>& elements)
{
    int n=elements.size();
    int i, j;
    for(i=0; i<=n-1; i++) //Error 1: Used i<=n-1 instead of i<n-1
    {
        int minIndex=i-1; //Error 2: Used i-1 instead of i
        for(j=i; j<n; j++) //Error 3: Used j=i instead of j=i+1
        {
            if(elements[j]>elements[minIndex]) //Error 4: Used elements[j] > elements[minIndex] instead of elements[j] < elements[minIndex]
            {
                minIndex=j+1; //Error 5: Used j + 1 instead of j
            }
        }
        if(minIndex!=i)
            std::swap(elements[j], elements[i]);
    }
}

//Same Selection Sort function, but without errors
template<typename T>
std::vector<T> selectionSortCorrect(std::vector<T>& elements)
{
    int n=elements.size();
    int i, j;
    for(i=0; i<n-1; i++)
    {
        int minIndex=i;
        for(j=i+1; j<n; j++)
        {
            if(elements[j]<elements[minIndex])
            {
                minIndex=j;
            }
        }
        if(minIndex!=i)
            std::swap(elements[i], elements[minIndex]);
    }
}


//Part II: Testing

//My colleague's algorithm, with the 5 included errors:
//Insertion Sort
template<typename T>
void insertionSortWithErrors(std::vector<T>& elements)
{
    int n=elements.size(), i, j;
    for(i=1; i<n; i++)
    {
        T key=elements[i];
        j=i+1;
        while(j>=0 && elements[j]<key)
        {
            elements[j]=elements[j-1];
            j=j+1;
        }
        elements[j]=key;
    }
}

//My corrected version of my colleague's algorithm after testing:
template<typename T>
void insertionSortCorrect(std::vector<T>& elements)
{
    int n=elements.size(), i, j;
    for(i=1; i<n; i++)
    {
        T key=elements[i];
        j=i-1;
        while(j>=0 && elements[j]>key)
        {
            elements[j+1]=elements[j];
            j=j-1;
        }
        elements[j+1]=key;
    }
}


//Testing the algorithm and identifying errors
int main()
{
    //Vector of numbers for testing
    std::vector<int> numbers={5, 2, 7, 1, 9, 12, 4, 10, 11, 6};
    std::vector<int> numbersCopy=numbers; // Copy of the original vector

    //Insertion Sort with errors
    insertionSortWithErrors(numbers);
    std::cout<<"Insertion Sort with errors: ";
    for(const auto& num : numbers)
        std::cout<<num<<" ";
    std::cout<<std::endl;

    //Correct Insertion Sort
    insertionSortCorrect(numbersCopy);
    std::cout<<"Correct Insertion Sort: ";
    for(const auto& num : numbersCopy)
        std::cout<<num<<" ";
    std::cout<<std::endl;

    //Verification & error search
    int n=numbers.size(), i, j;

    //Test if the vector is sorted in ascending order
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            assert(numbers[i] <= numbers[j] && "not sorted in ascending order");
    std::cout<<"The vector is sorted in ascending order."<<std::endl;

    // Test if the vector has distinct elements
    for(i=0; i<n-1; i++)
        assert(numbers[i] != numbers[i+1] && "not distinct elements");
    std::cout<<"The vector has distinct elements."<<std::endl;

    // Check if the vector is identical to the correct result
    assert(numbers==std::vector<int>({1, 2, 4, 5, 6, 7, 9, 10, 11, 12}));

    // Other potentially relevant errors
    assert(numbers[0]<numbers[1]); // Error 1: Check if the first element is smaller than the second element
    assert(numbers[0]==numbers[1]); // Error 2: Check if the first element is equal to the second element
    assert(numbers[0]<numbers[2]); // Error 3: Check if the first element is smaller than the third element
    assert(numbers[0]==numbers[3]); // Error 4: Check if the first element is equal to the fourth element
    assert(numbers.size()==10); // Error 5: Check if the vector size is equal to 5

    std::cout<<"All tests passed successfully!"<<std::endl;

    return 0;
}
