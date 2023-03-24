#include "Skoda.h"

Skoda::Skoda() : Car(50, 10)
{
    this->average_speed[(int) Weather::Rain]=100;
    this->average_speed[(int) Weather::Snow]=30;
    this->average_speed[(int) Weather::Sunny]=155;
}

const char* Skoda::getName()
{
    return "Skoda";
}

double Skoda::getFuelCapacity()
{
    return this->fuel_capacity;
}

double Skoda::getFuelConsumption()
{
    return this->fuel_consumption;
}

double Skoda::getAverageSpeed(Weather weather)
{
    return this->average_speed[(int)weather];
}
