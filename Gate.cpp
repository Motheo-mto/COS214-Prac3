#include "Gate.h"
#include <iostream>

using namespace std;

Gate::Gate(string name, int capacity) : EventUnit(name, capacity)
{
}

Gate::~Gate() {}

void Gate::update(string noticeType)
{
    if (noticeType == "WEATHER_ALERT")
    {
        cout << "Gate " << getName() << " remains open during WEATHER ALERT." << endl;
    }
    else if (noticeType == "EVACUATE")
    {
        open();
        cout << "Gate " << getName() << " is forcibly opened due to EVACUATE." << endl;
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

void Gate::reportStatus() const
{
    cout << "  - Gate: " << getName() << " | Capacity: " << getCapacity() << endl;
}

int Gate::getCapacity() const
{
    return EventComponent::getCapacity();
}

void Gate::open()
{
    cout << "Gate " << getName() << " is opened." << endl;
}

void Gate::close()
{
    cout << "Gate " << getName() << " is closed." << endl;
}
