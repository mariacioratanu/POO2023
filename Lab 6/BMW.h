#pragma once
#include "Car.h"
#include "Weather.h"

class BMW : public Car
{
  public:
    BMW();
    double getAverageSpeed(Weather) override;
    const char* getName() override;
    double getFuelCapacity() override;
    double getFuelConsumption() override;
};
