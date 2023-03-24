#include "Dacia.h"

Dacia::Dacia() : Car(60, 9)
{
    this->average_speed[(int)Weather::Rain]=80;
    this->average_speed[(int) Weather::Snow]=40;
    this->average_speed[(int) Weather::Sunny]=100;
}

const char* Dacia::getName()
{
    return "Dacia";
}

double Dacia::getFuelCapacity()
{
    return this->fuel_capacity;
}

double Dacia::getFuelConsumption()
{
    return this->fuel_consumption;
}

double Dacia::getAverageSpeed(Weather weather)
{
    return this->average_speed[(int)weather];
}
