#pragma once
#include "Weather.h"
#include "Car.h"

class Circuit
{
  private:
    const static int MAX_SIZE=10; //the maximum number of cars that are allowed in the race
    double length; //the lenght of the Circuit
    Weather weather; //the current weather conditions
    Car* cars[10]; //the array of cars participating in the race
    int size=0; //the number of cars in the race
  public:
    Circuit(); //a constructor that initializes the circuit object
    void SetLength(double length);
    void SetWeather(Weather weather);
    bool AddCar(Car* car); //adds a Car object to the race
    void Race(); //starts the race
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};
