#include "EventUnit.h"
#include "Subject.h"

using namespace std;

EventUnit::EventUnit() : EventComponent()
{
}

EventUnit::EventUnit(string name, string status, int capacity)
    : EventComponent(name, status, capacity)
{
}

EventUnit::~EventUnit()
{
}