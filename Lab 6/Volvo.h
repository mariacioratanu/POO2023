#pragma once
#include "Car.h"
#include "Weather.h"

class Volvo: public Car
{
  public:
    Volvo();
    double getAverageSpeed(Weather) override;
    const char* getName() override;
    double getFuelCapacity() override;
    double getFuelConsumption() override;
};
