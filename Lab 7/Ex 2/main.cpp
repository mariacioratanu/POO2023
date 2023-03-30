#include <iostream>
#include "VectorTemplate.h"
#include <cstring>

template <typename T>
inline bool callbackSortFunction(T obj1, T obj2)
{
    //a callback function=passed as an argument to another function, and called by that function to perform a specific task
    //template function
    //returns true if obj1 is less than obj2
    return obj1<obj2;
}

inline bool callbackLastDigits(int obj1, int obj2)
{
    //takes two arguments of type int
    //checks if two integers have the same last digit
    return obj1%10==obj2%10;
}

inline bool callbackFirstIndexOf(std::string obj1, std::string obj2)
{
    //takes two arguments of type std::string
    //checks if two strings have the same second character and are not equal to each other
    return obj1[1]==obj2[1]&&obj1!=obj2;
}

int main()
{
    //two Vector objects - one for storing integers and one for storing characters
    Vector<int> vecInt;
    Vector<char> vecChar;

    int i;
    //push 15 characters and integers into their respective Vector objects:
    for(i=0;i<15;i++)
    {
        vecChar.push(char('A' + i));
        vecInt.push(i);
    }
    vecChar.print(); //prints the char vector (print() method)
    vecInt.print();
    std::cout<<"The last element from the integer vector is "<<vecInt.pop()<<std::endl; //pop()=removes and returns the last element from the integer vector
    vecInt.remove(2);//removes the element at index 2
    for(i=0;i<5;i++)
        vecInt.pop(); //5 elements are popped off the VecInt
    vecInt.insert(2, -10); //inserts the value -10 at index 2 (insert() method)
    vecInt.print(); //prints the updated elements
    int X=vecInt.get(6); //retrieves the element at index 6, which is then assigned to the variable X
    std::cout<<"Ref vector: "<<X<<std::endl; //prints X
    vecInt.set(1, 20); //sets the value of the element at index 1 to 20
    vecInt.sort(callbackSortFunction); //passes in the callbackSortFunction as the sorting function
    vecInt.insert(5, 30); //inserts the value 30 at index 5
    vecInt.print(); //prints the updated elements
    std::cout<<"The number of elements in the integer vector is "<<vecInt.count()<<std::endl;//counts the number of elements
    std::cout<<vecInt.firstIndexOf(13, callbackLastDigits)<<std::endl; //finds the index of the first occurrence of the value 13, using callbackLastDigits
    Vector<std::string> vecStr; //Vector object is created to store strings
    vecStr.push("Maria");
    vecStr.push("Ionut");
    vecStr.push("Ioana");
    vecStr.sort(); //sorts the strings alphabetically
    std::cout<<vecStr.firstIndexOf(vecStr.get(0), callbackFirstIndexOf)<<std::endl; //finds the index of the first occurrence of the string that matches the first element of the vecStr object
    vecStr.print(); //prints the updated elements
    Vector<bool> vecResize; //new Vector object is created to store boolean values
    int actual_size=vecResize.getAllocatedSize();
    for(i=1;i<=50; i++)
    {
        vecResize.push(true); //push 50 boolean values into the vecResize object
        if(actual_size!=vecResize.getAllocatedSize()) //getAllocatedSize() method is called to retrieve the current allocated size of the vector
        {
            // the allocated size has changed from the previous iteration
            std::cout<<"Pentru a introduce al "<<i<<"-lea element am crescut spatiul alocat de la "<<actual_size<<" la "<<vecResize.getAllocatedSize()<<"."<<std::endl;
            actual_size=vecResize.getAllocatedSize();
        }
    }
    return 0;
}
