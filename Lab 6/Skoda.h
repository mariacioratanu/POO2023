#pragma once
#include "Car.h"
#include "Weather.h"

class Skoda : public Car
{
  public:
    Skoda();
    double getAverageSpeed(Weather) override;
    const char* getName() override;
    double getFuelCapacity() override;
    double getFuelConsumption() override;
};

