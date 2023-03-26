#include <iostream>

float operator""_Kelvin(unsigned long long int kelvin)
{
    return static_cast<float>(kelvin-273.15);
}

float operator""_Fahrenheit(unsigned long long int fahrenheit)
{
    return static_cast<float>((fahrenheit-32)/1.8);
}

int main()
{
    float a=300_Kelvin;
    float b=120_Fahrenheit;
    std::cout<<"300 degrees Kelvin is "<<a<<" degrees Celsius"<< std::endl;
    std::cout<<"120 degrees Fahrenheit is "<<b<<" degrees Celsius"<< std::endl;
    return 0;
}
