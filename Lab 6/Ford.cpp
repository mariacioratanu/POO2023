#include "Ford.h"

Ford::Ford() : Car(52, 6.5) //fuel capacity=52 and fuel consumption=6.5L/100km
{
    //the constructor for the Ford class
    this->average_speed[(int) Weather::Rain]=38; //km/h
    this->average_speed[(int) Weather::Snow]=55;
    this->average_speed[(int) Weather::Sunny]=86;
}

const char* Ford::getName()
{
    return "Ford";
}

double Ford::getFuelCapacity()
{
    return this->fuel_capacity;
}

double Ford::getFuelConsumption()
{
    return this->fuel_consumption;
}

double Ford::getAverageSpeed(Weather weather)
{
    return this->average_speed[(int) weather];
}
