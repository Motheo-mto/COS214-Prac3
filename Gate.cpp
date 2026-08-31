#include "Gate.h"
#include <iostream>

using namespace std;

Gate::Gate(string name, string status, int capacity) : EventUnit(name, status, capacity)
{
}

Gate::~Gate() {}

void Gate::update(string noticeType) {}

void Gate::reportStatus() const {}

int Gate::getCapacity() const
{
    return EventComponent::getCapacity();
}

void Gate::open()
{
    setStatus("OPEN");
    cout << "Gate " << getName() << " is opened." << endl;
}

void Gate::close()
{
    setStatus("CLOSE");
    cout << "Gate " << getName() << " is closed." << endl;
}
