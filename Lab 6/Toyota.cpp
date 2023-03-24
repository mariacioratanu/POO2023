#include "Toyota.h"

Toyota::Toyota() : Car(54, 4)
{
    this->average_speed[(int) Weather::Rain]=45;
    this->average_speed[(int) Weather::Snow]=85;
    this->average_speed[(int) Weather::Sunny]=135;
}

const char* Toyota::getName()
{
    return "Toyota";
}

double Toyota::getFuelCapacity()
{
    return this->fuel_capacity;
}

double Toyota::getFuelConsumption()
{
    return this->fuel_consumption;
}

double Toyota::getAverageSpeed(Weather weather)
{
    return this->average_speed[(int)weather];
}
