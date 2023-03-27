#pragma once
#include "Car.h"
#include "Weather.h"

class Fiat : public Car
{
  public:
    Fiat();
    double getAverageSpeed(Weather) override;
    const char* getName() override;
    double getFuelCapacity() override;
    double getFuelConsumption() override;
};

