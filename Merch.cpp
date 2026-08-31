#include "Merch.h"
#include <iostream>

using namespace std;

Merch::Merch() {}

Merch::Merch(string name, string status, int capacity)
    : EventUnit(name, status, capacity), stockLevel(0) {}

Merch::~Merch() {}

void Merch::update(string noticeType) {}

void Merch::reportStatus() const {}

int Merch::getCapacity() const
{
    return EventComponent::getCapacity();
}

void Merch::open()
{
    setStatus("OPEN");
    cout << "Merch stand " << getName() << " is opened." << endl;
}

void Merch::close()
{
    setStatus("CLOSE");
    cout << "Merch stand " << getName() << " is closed" << endl;
}

