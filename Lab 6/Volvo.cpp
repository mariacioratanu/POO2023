#include "Volvo.h"

Volvo::Volvo() : Car(60, 9.5)
{
    this->average_speed[(int)Weather::Rain]=80;
    this->average_speed[(int) Weather::Snow]=40;
    this->average_speed[(int) Weather::Sunny]=100;
}

const char* Volvo::getName()
{
    return "Volvo";
}

double Volvo::getFuelCapacity()
{
    return this->fuel_capacity;
}

double Volvo::getFuelConsumption()
{
    return this->fuel_consumption;
}

double Volvo::getAverageSpeed(Weather weather)
{
    return this->average_speed[(int)weather];
}
