#include "Bathroom.h"
#include <iostream>

using namespace std;

Bathroom::Bathroom() : EventUnit()
{
}

Bathroom::Bathroom(string name, string status, int capacity) 
: EventUnit(name, status, capacity), cleanlines(0)
{
}

Bathroom::~Bathroom(){}

void Bathroom::update(string noticeType) {}

void Bathroom::reportStatus() const {}

int Bathroom::getCapacity() const
{
    return EventComponent::getCapacity();
}

void Bathroom::open()
{
    setStatus("OPEN");
    cout << "Bathroom " << getName() << " opened." << endl;
}

void Bathroom::close()
{
    setStatus("CLOSE");
    cout << "Bathroom " << getName() << " closed." << endl;
}