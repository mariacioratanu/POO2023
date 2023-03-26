#include <iostream>

//two literal operators, _Kelvin and _Fahrenheit, which allow
//to write numeric literals suffixed with either _Kelvin or _Fahrenheit
//to represent temperatures in either Kelvin or Fahrenheit

float operator""_Kelvin(unsigned long long int kelvin) //the numeric value of the temperature in Kelvin
{
    return static_cast<float>(kelvin-273.15); //returns a float value(the temperature in Celsius)
}

float operator""_Fahrenheit(unsigned long long int fahrenheit) //the numeric value of the temperature in Fahrenheit
{
    return static_cast<float>((fahrenheit-32)/1.8); //returns a float value(the temperature in Celsius)
}

int main()
{
    float a=300_Kelvin;
    float b=120_Fahrenheit;
    std::cout<<"300 degrees Kelvin is "<<a<<" degrees Celsius"<< std::endl; //26.85 C
    std::cout<<"120 degrees Fahrenheit is "<<b<<" degrees Celsius"<< std::endl; //48.8889 C
    return 0;
}
