#include "Food.h"
#include <iostream>

using namespace std;

Food::Food() : EventUnit() {}

Food::Food(string name, string status, int capacity)
    : EventUnit(name, status, capacity) {}

Food::~Food() {}

void Food::update(string noticeType) {}

void Food::reportStatus() const {}

int Food::getCapacity() const
{
    return EventComponent::getCapacity();
}

void Food::open()
{
    setStatus("OPEN");
    cout << "Food stall " << getName() << " is opened." << endl;
}

void Food::close()
{
    setStatus("CLOSE");
    cout << "Food stall " << getName() << " is closed." << endl;
}