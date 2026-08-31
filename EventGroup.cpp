#include "EventGroup.h"
#include <iostream>

using namespace std;

EventGroup::EventGroup() : EventComponent()
{
}

EventGroup::EventGroup(int capacity, string status, string name)
    : EventComponent(name, status, capacity)
{
}

EventGroup::~EventGroup()
{
    for (size_t i = 0; i < children.size(); i++)
    {
        delete children[i];
    }
    children.clear();
}

void EventGroup::add(EventComponent *component)
{
    if (component == nullptr)
        return;

    // check for duplicates
    for (size_t i = 0; i < children.size(); i++)
    {
        if (children[i] == component)
        {
            return;
        }
    }
    children.push_back(component);
}

void EventGroup::remove(EventComponent *component)
{
    if (component == nullptr)
        return;

    for (size_t i = 0; i < children.size(); i++)
    {
        if (children[i] == component)
        {
            children.erase(children.begin() + i);
            return;
        }
    }
}

void EventGroup::update(string noticeType)
{
    
    for (size_t i = 0; i < children.size(); i++)
    {
        // reference base class pointer
        Observer *observer = dynamic_cast<Observer *>(children[i]);
        if (observer != nullptr)
        {
            observer->update( noticeType);
        }
    }
}

int EventGroup::getCapacity() const
{
    int total = 0;
    for (size_t i = 0; i < children.size(); i++)
    {
        total += children[i]->getCapacity();
    }
    return total;
}

/// still need to implement these, i dont know how
void EventGroup::reportStatus() const
{
}

void EventGroup::open()
{
    setStatus("OPEN");
    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->open();
    }
}

void EventGroup::close()
{
    setStatus("CLOSE");
    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->close();
    }
}