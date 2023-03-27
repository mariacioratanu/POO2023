#include "Fiat.h"

Fiat::Fiat() : Car(50, 10)
{
    this->average_speed[(int) Weather::Rain]=100;
    this->average_speed[(int) Weather::Snow]=30;
    this->average_speed[(int) Weather::Sunny]=155;
}

const char* Fiat::getName()
{
    return "Fiat";
}

double Fiat::getFuelCapacity()
{
    return this->fuel_capacity;
}

double Fiat::getFuelConsumption()
{
    return this->fuel_consumption;
}

double Fiat::getAverageSpeed(Weather weather)
{
    return this->average_speed[(int)weather];
}
