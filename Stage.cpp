#include "Stage.h"
#include <iostream>

using namespace std;

Stage::Stage() : EventUnit()
{
}

Stage::Stage(string name, int capacity)
    : EventUnit(name, capacity), isSheltered(false)
{
}

Stage::~Stage() {}

void Stage::reportStatus() const
{
    cout << "  - Stage: " << getName() << " | Capacity: " << getCapacity() << " | Sheltered: " << (isSheltered ? "Yes" : "No") << endl;
}

int Stage::getCapacity() const
{
    return EventComponent::getCapacity();
}

void Stage::update(string noticeType)
{
    if (noticeType == "WEATHER_ALERT")
    {
        if (!isSheltered)
        {
            cout << "Stage " << getName() << " is closing due to WEATHER ALERT!" << endl;
            close();
        }
    }
    else if (noticeType == "CAPACITY_ALERT")
    {
        if (getCapacity() >= 1000)
        {
            cout << "Stage " << getName() << " is closing due to capacity." << endl;
            close();
        }
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

void Stage::open()
{
    cout << "Stage " << getName() << " is opened." << endl;
}

void Stage::close()
{
    cout << "Stage " << getName() << " is closed." << endl;
}

void Stage::setSheltered(bool shelter)
{
    isSheltered = shelter;
}
