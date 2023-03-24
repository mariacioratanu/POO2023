#pragma once
#include "Car.h"
#include "Weather.h"

class Toyota : public Car
{
  public:
    Toyota();
    double getAverageSpeed(Weather) override;
    const char* getName() override;
    double getFuelCapacity() override;
    double getFuelConsumption() override;
};
