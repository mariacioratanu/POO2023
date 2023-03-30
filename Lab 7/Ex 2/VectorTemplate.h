#pragma once
#include <iostream>
#include <cstring>

//declares a templated class called Vector
template <class T>
class Vector
{
  private:
    static const int INITIAL_ALLOCATED_SIZE=1; //this constant is used to set the initial size of the array
    T* arr; //pointer to the array itself
    int size; //number of elements in the array
    int allocated_size; //size of the array
    void resize(int new_allocated_size) //the new size of the array
    {
        //used to resize the array when it runs out of space
        int i;
        T* old_arr=arr;
        arr=new T[new_allocated_size];
        for(i=0;i<allocated_size;i++)
            arr[i]=old_arr[i]; //copies the elements from the old array to the new array
        delete[] old_arr; //deletes the old array
        allocated_size=new_allocated_size;
    }
  public:
    Vector():size(0), allocated_size(INITIAL_ALLOCATED_SIZE), arr(new T[INITIAL_ALLOCATED_SIZE]) {} //the constructor for the Vector class
    ~Vector() // the destructor for the Vector class
    {
        delete[] arr;
    }

    void push(const T& item) //push method (to add an element at the end of the vector)
    {
        //item=the element to add
        if(size==allocated_size) //if the array is full
            resize(allocated_size*2); //it is automatically resized to double its current size
        arr[size++]=item; //adds the element to the end of the array
    }

    T pop() //pop method (to return the last element from the vector)
    {
        if(size>0)
        {
            T temporary=arr[size-1]; //the last element in the vector is removed
            size--;
            return temporary; //the value of the removed element is returned
        }
    }

    bool remove(int index) //delete/remove method (deletes/removes an element from a specific index in the vector)
    {
        if(index<0 || size<=index) //checks if it is a valid index
            return false;
        //the element at that index is removed from the vector by shifting all elements after it one index to the left:
        for(; index<size-1; index++)
            arr[index]=arr[index+1];
        size--;
        return true;
    }

    bool insert(int index, T value) //insert method (insert an element at a specific index)
    {
        int k;
        if(index<0 || size<index)
            return false;
        if(size==allocated_size) //if the size of the vector is equal to the allocated size
            resize(allocated_size*2); //calls the resize function to double the allocated siz
        for(k=size;k>index;k--)
            arr[k]=arr[k-1]; //shifts all elements from the specified index one index to the right
        arr[index]=value; //inserts the value at the specified index
        size++;
        return true;
    }

    //sort method (sort all elements in the vector==>use a callback function to provide a way to compare two elements. If the callback function is not present (nullptr), operator< is used)
    void sort(bool (*callback)(T, T)=nullptr)
    {
        //takes a callback function that compares two elements of the vector and determines their order
        //if no callback function is provided, it assumes a default "less than" comparison
        int i, j;
        // bubble sort:
        for(i=0;i<size-1;i++)
        {
            for(j=i+1;j<size;j++)
            {
                //using either the provided or the default comparison function
                if(callback==nullptr && arr[i]>arr[j] || callback!=nullptr && callback(arr[i], arr[j]))
                    std::swap(arr[i], arr[j]);
            }
        }
    }

    const T& get(int index) //get method (returns a constant reference to an object from the vector)
    {
        if(0<=index && index<size) //if the index is valid
            return arr[index]; //returns the element at that index in the vector
    }

    bool set(int index, T obj) //set method (set an object to a specific index-->that index must be already used by another object)
    {
        //the index must already exist in the vector
        if(index<0 || size<index) //the index is valid
            return false;
        arr[index]=obj; //sets the element at the specified index to the specified value
        return true;
    }

    //firstIndexOf method (given an object and a callback function, find the first index of the element from the vector that is equal (according to the callback function) with the given
    //parameter. If the callback function is nor present (nullptr), operator== is used.
    int firstIndexOf(const T& obj, bool (*callback)(T, T)=nullptr)
    {
        //callback function that determines equality between elements in the vector
        int i;
        for(i=0;i<size;i++)
        {
            //searches for the first occurrence of the object in the vector using the provided or default comparison function
            if(callback==nullptr && arr[i]==obj || callback!=nullptr && callback(obj, arr[i]))
                return i;//returns the index of that occurrence
        }
        return -1;
    }

    int count() //count method (returns the number of elements in the vector)
    {
        return size; //returns the current size of the vector
    }

    void print() //prints the contents of the vector to the console
    {
        int i;
        if(size==0)
            return;
        std::cout<<"Vector=(";
        for(i=0;i<size;i++)
        {
            std::cout<<arr[i]; //prints each element to the console
            if(i!=size-1) //if the current element is not the last element of the vector, it prints a comma and a space
                std::cout<<", ";
        }
        std::cout<<")\n"; //prints the closing ) and a newline
    }

    int getAllocatedSize()
    {
        //returns the size of the allocated memory block for the vector
        return allocated_size;
    }
};
