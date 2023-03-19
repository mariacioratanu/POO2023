#pragma once

class Number
{
    //data members
  private:
    char* vector;
    int base;
    int vector_size;
    long long unsigned decimal;
    void calculateDecimal();
    static char* processingVector(unsigned new_decimal, unsigned new_base);

  public:
    Number(const char* value, int base=10); //base is between 2 and 16
    ~Number();

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const; //returns the number of digits for the current number
    int GetBase() const; //returns the current base

    //operators and copy/move constructor

    Number(long long unsigned value); //conversion constructor
    Number(const Number& obj); //copy constructor
    Number(Number &&obj); //move constructor

    //friend functions:
    friend Number operator+(const Number& lfs, const Number& rhs); //addition operator
    friend Number operator-(const Number& lfs, const Number& rhs); //subtraction operator

    //operators for decrementing:
    Number& operator--();
    Number& operator--(int);

    char operator[](int index) const; //index operator

    //relation operators (for comparisons):
    bool operator>(const Number& obj) const;
    bool operator>=(const Number& obj) const;
    bool operator<(const Number& obj) const;
    bool operator<=(const Number& obj) const;
    bool operator==(const Number& obj) const;
    bool operator!=(const Number& obj) const;

    //overloaded assignment operators
    void operator=(const Number& obj);
    void operator=(long long unsigned value);
    void operator=(const char * value);
};
