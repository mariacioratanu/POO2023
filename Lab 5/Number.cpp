#include "Number.h"
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

void Number::calculateDecimal()
{   //converts a number represented in a given base into its decimal equivalent
    int i, sub;
    decimal=0;
    for(i=0, sub;i<vector_size; i++)
    {
        if('0'<=vector[i] && vector[i]<='9') //the character is a digit
            sub=48; //ASCII value of '0'
        else //the character is a letter
            sub=55; //ASCII value of 'A' minus 10(A=11)
        decimal=decimal+(vector[i]-sub)*pow(base, vector_size-i-1);
    }
}

char* Number::processingVector(unsigned new_decimal, unsigned new_base)
{
    //converts a decimal number (new_decimal) into a new base
    //calculates the number of digits required to represent the number in the new base:
    int size_required=floor(log10(new_decimal)/log10(new_base))+1;
    char* vec=new char[size_required+1];
    long long unsigned aux=new_decimal;
    int index=size_required-1;
    while(aux>0)
    {
        int rest=aux%new_base;
        if(0<=rest && rest<=9)
            vec[index]='0'+rest;
        else
            vec[index]='A'-10+rest;
        aux/=new_base;
        index--;
    }
    vec[size_required]='\0';
    return vec;
}

Number::Number(const char* value, int base) : base(base), vector_size(strlen(value))
{
    //used to create a new Number object from a character array that represents a number in a given base
    this->vector=new char[vector_size+1]; //+1 for the null character at the end of the string
    strcpy(vector, value); //copy the contents of the value array
    this->calculateDecimal();
}

Number::Number(long long unsigned value) : base(10), vector_size(0), decimal(value)
{
    //used to create a new Number object from a decimal integer value
    this->SwitchBase(base); //base=10 -> this call will set the vector member variable to the decimal value
}

Number::Number(const Number& obj)
{
    //used to create a new Number object that is a copy of an existing Number object
    *this=obj; //the same values as the original object
}

Number::Number(Number&& obj) : base(obj.base), vector_size(obj.vector_size), decimal(obj.decimal)
{
    //move constructor
    //used to create a new Number object by "stealing" the resources
    //of an existing Number object (that object is a temporary object or it is no longer needed)
    char* temp=obj.vector;
    obj.vector=nullptr;
    this->vector=temp;
}

Number::~Number()
{
    //destructor
    //to ensure that no memory leaks occur when the Number object is destroyed
    delete[] this->vector;
}

void Number::SwitchBase(int newBase)
{
    //used to convert a number from its current base to a new base
    //calculates the number of digits required to represent the Number object in the new base:
    int size_required=floor(log10(this->decimal)/log10(newBase))+1;
    if(size_required!=this->vector_size) //if the size required for the new representation is different from the current size of the vector
    {
        if(this->vector!=nullptr)
            delete this->vector; //dellocates the old vector
        this->vector=new char[size_required+1]; //allocates a new vector
        this->vector_size=size_required;
    }
    long long unsigned aux=this->decimal;
    int index=vector_size-1;
    //actual base conversion:
    while(aux>0)
    {
        int rest=aux%newBase;
        if(0<=rest && rest<=9)
            vector[index]='0'+rest; 
        else
            vector[index]='A'-10+rest;
        aux/=newBase;
        index--;
    }
    this->vector[vector_size]='\0';
    this->base=newBase;
}

void Number::Print() const //the function does not modify the state of the Number object
{
    //prints the contents of the vector member variable and a newline
    std::cout<<this->vector<<endl;
}

int Number::GetDigitsCount() const
{
    //returns the number of digits in the vector member variable
    return this->vector_size;
}

int Number::GetBase() const
{
    //returns the value of the "base" of the object pointed to by the "this" pointer
    return this->base;
}

//if used in a prefix form it will remove the first (most significant digit) from the number;
Number& Number::operator--()
{
    //defines the pre-decrement operator (--)
    char* new_vector = new char[this->vector_size + 1];
    strcpy(new_vector, this->vector);
    delete []  this->vector; //deallocates the old vector
    this->vector = new char[this->vector_size]; //creates a new char array with a size one less than the old vector
    strcpy(this->vector, new_vector + 1); //removes the first character from the vector
    this->vector_size--; //the new size of the vector
    delete [] new_vector;

    this->calculateDecimal();
    return *this;
}

//if used in a post-fix form it will remove the last (least significant) digit from the number;
Number& Number::operator--(int)
{
    //defines the post-decrement operator (--)
    char* new_vector=new char[this->vector_size+1]; //allocates a new char array with the same size as the current vector
    strcpy(new_vector, this->vector);
    new_vector[this->vector_size-1]='\0'; //sets the second-to-last character to '\0' to remove the last character
    delete[] this->vector;
    this->vector=new char[this->vector_size];
    strcpy(this->vector, new_vector);
    this->vector_size--;
    delete[] new_vector;

    this->calculateDecimal();
    return *this;
}

char Number::operator[](int index) const
{
    //the function returns the char value at that index in the vector
    if(0<=index && index<this->vector_size)
        return this->vector[index];
    return '?'; //index is not within the valid range of indices for the vector
}

//comparison operator functions:
bool Number::operator>(const Number& obj) const
{
    //compares the decimal values of two Number objects
    //returns true if the decimal value of the current object is greater than the decimal value of the argument object
    return this->decimal>obj.decimal;
}

bool Number::operator>=(const Number& obj) const
{
    //greater than or equal to
    return *this>obj || *this==obj;
}

bool Number::operator<(const Number& obj) const
{
    //less than
    return !(*this>=obj);
}

bool Number::operator<=(const Number& obj) const
{
    //less than or equal to
    return *this<obj || *this==obj;
}

bool Number::operator==(const Number& obj) const
{
    //equal
    return this->decimal==obj.decimal;
}

bool Number::operator!=(const Number& obj) const
{
    //not equal
    return *this==obj;
}

void Number::operator=(const Number& obj)
{
    //defines the copy assignment operator (=), creating a deep copy of the vector 
    if(this->vector_size!=obj.vector_size) //checks whether the current object has a different size than the object being copied
    {
        //deletes the current vector and allocates a new one 
        delete[] this->vector;
        this->vector=new char[obj.vector_size+1];
    }
    //sets the base, vector_size, and decimal of the current object to the corresponding values of the other object
    this->base=obj.base;
    this->vector_size=obj.vector_size;
    this->decimal=obj.decimal;
    strcpy(this->vector, obj.vector);
}

void Number::operator=(long long unsigned value)
{
    //defines the assignment operator (=)
    this->vector_size=0; //clears the vector member variable
    this->base=10; //sets the base to 10 (decimal)
    this->decimal=value; //sets the decimal member variable to the input value
    this->SwitchBase(this->base);//converts the decimal value to a specific base
}

void Number::operator=(const char* value)
{
    delete [] this->vector; //first deletes the existing vector array
    this->vector_size=strlen(value);
    this->vector=new char[vector_size+1]; //allocates a new char array with a size of vector_size+1
    this->base=10; //the value string is assumed to be in base 10
    strcpy(vector, value);
    this->calculateDecimal();
}

Number operator+(const Number& lfs, const Number& rhs)
{
    //takes two Number objects, lfs and rhs and returns their sum
    int new_base=std::max(lfs.base, rhs.base); //finds the maximum base of the two numbers 
    char* temporary_vector = Number::processingVector(lfs.decimal+rhs.decimal, new_base); //takes the sum of the decimal parts of the two numbers and returns the sum in the given base
    Number instance{ temporary_vector, new_base };
    delete[] temporary_vector;
    return instance;
}

Number operator-(const Number& lfs, const Number& rhs)
{
    //takes two Number objects, lfs and rhs and returns their difference
    int new_base=std::max(lfs.base, rhs.base); //finds the maximum base of the two numbers
    char* temporary_vector = Number::processingVector(lfs.decimal-rhs.decimal, new_base);

    Number instance{ temporary_vector, new_base };
    delete[] temporary_vector;
    return instance;
}
