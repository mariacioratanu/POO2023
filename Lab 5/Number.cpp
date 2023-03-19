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
    int size_required=floor(log10(this->decimal)/log10(newBase))+1;
    if(size_required!=this->vector_size)
    {
        if(this->vector!=nullptr)
            delete this->vector;
        this->vector=new char[size_required+1];
        this->vector_size=size_required;
    }
    long long unsigned aux=this->decimal;
    int index=vector_size-1;
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

void Number::Print() const
{
    cout<<this->vector<<endl;
}

int Number::GetDigitsCount() const
{
    return this->vector_size;
}

int Number::GetBase() const
{
    return this->base;
}
//if used in a prefix form it will remove the first (most significant digit) from the number;
Number& Number::operator--()
{
    char* new_vector = new char[this->vector_size + 1];
    strcpy(new_vector, this->vector);
    delete []  this->vector;
    this->vector = new char[this->vector_size];
    strcpy(this->vector, new_vector + 1);
    this->vector_size--;
    delete [] new_vector;

    this->calculateDecimal();
    return *this;
}
//if used in a post-fix form it will remove the last (least significant) digit from the number;
Number& Number::operator--(int)
{
    char* new_vector=new char[this->vector_size+1];
    strcpy(new_vector, this->vector);
    new_vector[this->vector_size-1]='\0';
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
    if(0<=index && index<this->vector_size)
        return this->vector[index];
    return '?';
}

bool Number::operator>(const Number& obj) const
{
    return this->decimal>obj.decimal;
}

bool Number::operator>=(const Number& obj) const
{
    return *this>obj || *this==obj;
}

bool Number::operator<(const Number& obj) const
{
    return !(*this>=obj);
}

bool Number::operator<=(const Number& obj) const
{
    return *this<obj || *this==obj;
}

bool Number::operator==(const Number& obj) const
{
    return this->decimal==obj.decimal;
}

bool Number::operator!=(const Number& obj) const
{
    return *this==obj;
}

void Number::operator=(const Number& obj)
{
    if(this->vector_size!=obj.vector_size)
    {
        delete[] this->vector;
        this->vector=new char[obj.vector_size+1];
    }
    this->base=obj.base;
    this->vector_size=obj.vector_size;
    this->decimal=obj.decimal;
    strcpy(this->vector, obj.vector);
}

void Number::operator=(long long unsigned value)
{
    this->vector_size=0;
    this->base=10;
    this->decimal=value;
    this->SwitchBase(this->base);
}

void Number::operator=(const char* value)
{
    delete [] this->vector;
    this->vector_size=strlen(value);
    this->vector=new char[vector_size+1];
    this->base=10;
    strcpy(vector, value);
    this->calculateDecimal();
}

Number operator+(const Number& lfs, const Number& rhs)
{
    int new_base=std::max(lfs.base, rhs.base);
    char* temporary_vector = Number::processingVector(lfs.decimal+rhs.decimal, new_base);
    Number instance{ temporary_vector, new_base };
    delete[] temporary_vector;
    return instance;
}

Number operator-(const Number& lfs, const Number& rhs)
{
    int new_base=std::max(lfs.base, rhs.base);
    char* temporary_vector = Number::processingVector(lfs.decimal-rhs.decimal, new_base);

    Number instance{ temporary_vector, new_base };
    delete[] temporary_vector;
    return instance;
}
