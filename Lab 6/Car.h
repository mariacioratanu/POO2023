#pragma once
#include "Weather.h"
//the class has pure virtual functions, and it is expected to be derived by concrete car classes that implement the virtual functions
class Car
{
  protected:
    double fuel_capacity; //the fuel capacity of the car (in L)
    double fuel_consumption; //the fuel consumption of the car (L/100km)
    double* average_speed=new double[3]; //(Rain, Sunny, Snowy)

  public:
    Car(double fuel_capacity, double fuel_consumption) : fuel_capacity(fuel_capacity), fuel_consumption(fuel_consumption) {};
    //virtual member functions (expected to be implemented by any derived class):
    virtual const char* getName()=0;
    virtual double getFuelCapacity()=0;
    virtual double getFuelConsumption()=0; //per 100 kilometers
    virtual double getAverageSpeed(Weather weather)=0; //returns the average speed of the car in the given weather conditions
};

