#include "EventUnit.h"
#include "Subject.h"

using namespace std;

EventUnit::EventUnit() : EventComponent(), isOpen(false)
{
}

EventUnit::EventUnit(string name, int capacity)
    : EventComponent(name, capacity)
{
}

EventUnit::~EventUnit()
{
}