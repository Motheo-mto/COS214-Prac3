#include "Stage.h"
#include <iostream>

using namespace std;

Stage::Stage() : EventUnit()
{
}

Stage::Stage(string name, string status, int capacity)
    : EventUnit(name, status, capacity), isSheltered(false)
{
}

Stage::~Stage() {}

void Stage::update(string notifyType)
{
}

void Stage::reportStatus() const {}

int Stage::getCapacity() const
{
    return EventComponent::getCapacity();
}

void Stage::open()
{
    setStatus("OPEN");
    cout << "Stage " << getName() << " is open." << endl;
}

void Stage::close()
{
    setStatus("CLOSE");
    cout << "Stage " << getName() << " is closed." << endl;
}
