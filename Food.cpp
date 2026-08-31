#include "Food.h"
#include <iostream>

using namespace std;

Food::Food() : EventUnit() {}

Food::Food(string name, int capacity) : EventUnit(name, capacity)
{
    foodLeft = 200; // Initial default food amount
    previousCapacity = capacity;
}

Food::~Food() {}

void Food::update(string noticeType)
{
    if (noticeType == "WEATHER_ALERT")
    {
        cout << "Food stall " << getName() << " is closing due to WEATHER ALERT!" << endl;
        close();
    }
    else if (noticeType == "CAPACITY_ALERT")
    {
        if (getCapacity() > previousCapacity)
        {
            cout << "Food stall " << getName() << " food levels decrease due to capacity." << endl;
            foodLeft = (foodLeft > 10) ? foodLeft - 10 : 0;
        }
        previousCapacity = getCapacity();
    }
    else if (noticeType == "GIVEAWAY")
    {
        if (getCapacity() < 100)
        {
            cout << "Food stall " << getName() << " capacity is low." << endl;
            foodLeft = (foodLeft > 20) ? foodLeft - 20 : 0;
        }
    }
    else if (noticeType == "EVACUATE")
    {
        close();
        foodLeft = 0;
        cout << "Food stall " << getName() << " is evacuated." << endl;
    }
    else if (noticeType == "OPEN")
    {
        open();
    }
    else if (noticeType == "CLOSE")
    {
        close();
    }
}

void Food::reportStatus() const
{
    cout << "  - Food: " << getName() << " | Capacity: " << getCapacity() << endl;
}

int Food::getCapacity() const
{
    return EventComponent::getCapacity();
}

void Food::open()
{
    cout << "Food unit " << getName() << " is open." << endl;
}

void Food::close()
{
    cout << "Food unit " << getName() << " is closed." << endl;
}