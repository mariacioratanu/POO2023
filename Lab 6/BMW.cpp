#include "BMW.h"

BMW::BMW() : Car(50, 8)
{
    this->average_speed[(int) Weather::Rain]=35;
    this->average_speed[(int) Weather::Snow]=20;
    this->average_speed[(int) Weather::Sunny]=50;
}

const char* BMW::getName()
{
    return "BMW";
}

double BMW::getFuelCapacity()
{
    return this->fuel_capacity;
}

double BMW::getFuelConsumption()
{
    return this->fuel_consumption;
}

double BMW::getAverageSpeed(Weather weather)
{
    return this->average_speed[(int)weather];
}
