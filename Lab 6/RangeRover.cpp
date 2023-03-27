#include "RangeRover.h"

RangeRover::RangeRover() : Car(54, 4)
{
    this->average_speed[(int) Weather::Rain]=45;
    this->average_speed[(int) Weather::Snow]=85;
    this->average_speed[(int) Weather::Sunny]=135;
}

const char* RangeRover::getName()
{
    return "RangeRover";
}

double RangeRover::getFuelCapacity()
{
    return this->fuel_capacity;
}

double RangeRover::getFuelConsumption()
{
    return this->fuel_consumption;
}

double RangeRover::getAverageSpeed(Weather weather)
{
    return this->average_speed[(int)weather];
}
