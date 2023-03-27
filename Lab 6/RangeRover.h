#pragma once

#include "Car.h"
#include "Weather.h"

class RangeRover : public Car
{
  public:
    RangeRover();
    double getAverageSpeed(Weather) override;
    const char* getName() override;
    double getFuelCapacity() override;
    double getFuelConsumption() override;
};
