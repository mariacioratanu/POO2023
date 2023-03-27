#include "Seat.h"

Seat::Seat() : Car(52, 6) //fuel capacity=52 and fuel consumption=6L/100km
{
    //the constructor for the Seat class
    this->average_speed[(int) Weather::Rain]=38; //km/h
    this->average_speed[(int) Weather::Snow]=55;
    this->average_speed[(int) Weather::Sunny]=86;
}

const char* Seat::getName()
{
    return "Seat";
}

double Seat::getFuelCapacity()
{
    return this->fuel_capacity;
}

double Seat::getFuelConsumption()
{
    return this->fuel_consumption;
}

double Seat::getAverageSpeed(Weather weather)
{
    return this->average_speed[(int) weather];
}
