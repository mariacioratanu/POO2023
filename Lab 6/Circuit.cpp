#include "Circuit.h"
#include <iostream>

Circuit::Circuit():length(100), weather(Weather::Sunny)
{
    //the constructor is using a member initialization list to initialize the data members directly,
    //rather than assigning values to them inside the constructor body
}

void Circuit::SetLength(double length)
{
    //sets the length of the circuit to a specific value
    this->length=length;
}

void Circuit::SetWeather(Weather weather)
{
    //sets the weather to eaither sunny, snow or rain
    this->weather=weather;
}

bool Circuit::AddCar(Car* car)
{
    if(size==this->MAX_SIZE) //checks if the size of the cars array is equal to MAX_SIZE
        return false; //there are already enough cars in the race, so we cannot add a new one
    this->cars[size++]=car;
    return true; //the car was successfully added to the race
}

void Circuit::Race()
{
    //sorts the cars participating in the race based on their average speed in the current weather conditions
    int i, j;
    for(i=0;i<size-1;i++)
        for(j=i+1;j<size;j++)
            if(cars[i]->getAverageSpeed(weather)>cars[j]->getAverageSpeed(weather))
                std::swap(cars[i], cars[j]); //their positions are swapped
}

void Circuit::ShowFinalRanks()
{
    //displays the final ranking of cars that completed the race, based on their fuel capacity and fuel consumption
    int i;
    for(i=0;i<size;i++)
        //for each car, it checks whether its fuel capacity is greater than or equal to the fuel it would
        //consume to complete the race
        if(cars[i]->getFuelCapacity()>=(cars[i]->getFuelConsumption()*length)/100)
        //formula: fuel_needed=fuel_consumption*lenght/100
            std::cout<<cars[i]->getName()<<"\n"; //the car has enough fuel to finish the race
    std::cout<<std::endl;
}

void Circuit::ShowWhoDidNotFinish() //doesn't have enough fuel to finish the Circuit
{
    //comparing the car's fuel capacity with its fuel consumption rate and the length of the circuit
    int i;
    for(i=0;i<size;i++)
        if(cars[i]->getFuelCapacity()<(cars[i]->getFuelConsumption()*length)/100)
            std::cout<<"Cars that didn't finish"<<cars[i]->getName()<<"\n";
    std::cout<<std::endl;
}
