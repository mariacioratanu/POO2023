#pragma once
#include "Car.h"
#include "Weather.h"

//a class called Seat which is derived from the base class Car
//the Seat class inherits all of its non-private members and can also add its own member functions and variables
class Seat : public Car
{
  public:
    Seat();
    double getAverageSpeed(Weather) override;
    const char* getName() override;
    double getFuelCapacity() override;
    double getFuelConsumption() override;
};
