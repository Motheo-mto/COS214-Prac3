#include "EventComponent.h"

using namespace std;

EventComponent::EventComponent() : name(""), capacity(0)
{
}

EventComponent::EventComponent(string name, int capacity) : name(name), capacity(capacity)
{
}

EventComponent::~EventComponent() {}

void EventComponent::add(EventComponent *component)
{
    // default implementation for leaf nodes
}

void EventComponent::remove(EventComponent *component)
{
    // default implementation for leaf nodes
}

string EventComponent::getName() const
{
    return name;
}

void EventComponent::setName(string n)
{
    name = n;
}

void EventComponent::setCapacity(int n)
{
    capacity = n;
}

int EventComponent::getCapacity() const
{
    return capacity;
}
