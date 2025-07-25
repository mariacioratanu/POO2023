#include <iostream>
#include "Weather.h"
#include "Circuit.h"
#include "Volvo.h"
#include "Seat.h"
#include "BMW.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Car.h"

int main()
{
    Circuit c;
    c.SetLength(100); //a circuit with a length of 100 km
    c.SetWeather(Weather::Sunny); //race weather conditions: rain
    c.AddCar(new Volvo());
    c.AddCar(new BMW());
    c.AddCar(new Seat());
    c.AddCar(new Fiat());
    c.AddCar(new RangeRover());
    c.Race();
    c.ShowFinalRanks();//it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest
    c.ShowWhoDidNotFinish();//it is possible that some cars don't have enough fuel to finish the circuit
    //formulas needed for calculating the results: time=distance/speed; fuel_needed=fuel_consumption/100*distance
    return 0;
}
