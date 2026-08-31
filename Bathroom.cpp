#include "Bathroom.h"
#include <iostream>

using namespace std;

Bathroom::Bathroom(string name, int capacity) : EventUnit(name, capacity)
{
    cleanliness = 100; // start clean
    previousCapacity = capacity;
}

Bathroom::~Bathroom() {}

void Bathroom::update(string noticeType)
{
    if (noticeType == "WEATHER_ALERT")
    {
        cleanliness -= 10;
        cout << "Bathroom " << getName() << " cleanliness decreased to " << cleanliness << " due to WEATHER ALERT." << endl;
    }
    else if (noticeType == "CAPACITY_ALERT")
    {
        if (getCapacity() > previousCapacity)
        {
            cleanliness -= 5;
            cout << "Bathroom " << getName() << " cleanliness decreased due to capacity." << endl;
        }
        else if (getCapacity() < previousCapacity)
        {
            cleanliness += 5;
            cout << "Bathroom " << getName() << " cleanliness increased due to capacity." << endl;
        }
        previousCapacity = getCapacity();
    }
    else if (noticeType == "EVACUATE")
    {
        close();
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

void Bathroom::reportStatus() const
{
    cout << "  - Bathroom: " << getName() << " | Capacity: " << getCapacity() << endl;
}

int Bathroom::getCapacity() const
{
    return EventComponent::getCapacity();
}

void Bathroom::open()
{
    cout << "Bathroom " << getName() << " is open." << endl;
}

void Bathroom::close()
{
    cout << "Bathroom " << getName() << " is closed." << endl;
}