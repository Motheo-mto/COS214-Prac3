#include "Merch.h"
#include <iostream>

using namespace std;

Merch::Merch() {}

Merch::Merch(string name, int capacity) : EventUnit(name, capacity)
{
    stockLevel = 500; // Initialize with some default stock
    previousCapacity = capacity;
}

Merch::~Merch() {}

void Merch::update(string noticeType)
{
    if (noticeType == "WEATHER_ALERT")
    {
        cout << "Merch stand " << getName() << " is closing due to WEATHER_ALERT." << endl;
        close();
    }
    else if (noticeType == "CAPACITY_ALERT")
    {
        if (getCapacity() > previousCapacity)
        {
            cout << "Merch stand " << getName() << " stock decreases due to capacity increment." << endl;
            stockLevel = (stockLevel > 10) ? stockLevel - 10 : 0;
        }
        previousCapacity = getCapacity();
    }
    else if (noticeType == "GIVEAWAY")
    {
        if (stockLevel > 200)
        {
            cout << "Merch stand " << getName() << " is giving away items!" << endl;
            stockLevel -= 20;
        }
    }
    else if (noticeType == "EVACUATE")
    {
        close();
        stockLevel = 0;
        cout << "Merch stand " << getName() << " is evacuated and stock set to 0." << endl;
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

void Merch::reportStatus() const
{
    cout << "  - Merch: " << getName() << " | Stock Level: " << stockLevel << endl;
}

int Merch::getCapacity() const
{
    return EventComponent::getCapacity();
}

void Merch::open()
{
    cout << "Merch unit " << getName() << " is open." << endl;
}

void Merch::close()
{
    cout << "Merch unit " << getName() << " is closed." << endl;
}
