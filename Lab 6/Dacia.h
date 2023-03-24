#pragma once
#include "Car.h"
#include "Weather.h"

class Dacia: public Car
{
  public:
    Dacia();
    double getAverageSpeed(Weather) override;
    const char* getName() override;
    double getFuelCapacity() override;
    double getFuelConsumption() override;
};
