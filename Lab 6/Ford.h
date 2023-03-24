#pragma once
#include "Car.h"
#include "Weather.h"

//a class called Ford which is derived from the base class Car
//the Ford class inherits all of its non-private members and can also add its own member functions and variables
class Ford : public Car
{
  public:
    Ford();
    double getAverageSpeed(Weather) override;
    const char* getName() override;
    double getFuelCapacity() override;
    double getFuelConsumption() override;
};
