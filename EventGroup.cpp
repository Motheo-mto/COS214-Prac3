#include "EventGroup.h"
#include "Gate.h"
#include <iostream>

using namespace std;

EventGroup::EventGroup() : EventComponent()
{
}

EventGroup::EventGroup(int capacity, string name)
    : EventComponent(name, capacity)
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

    Observer *obs = dynamic_cast<Observer *>(component);
    if (obs != nullptr)
    {
        attach(obs);
    }
}

void EventGroup::remove(EventComponent *component)
{
    if (component == nullptr)
        return;

    for (size_t i = 0; i < children.size(); i++)
    {
        if (children[i] == component)
        {
            Observer *obs = dynamic_cast<Observer *>(component);
            if (obs != nullptr)
            {
                detach(obs);
            }
            children.erase(children.begin() + i);
            return;
        }
    }
}

void EventGroup::update(string noticeType)
{
    if (noticeType == "OPEN")
    {
    }
    else if (noticeType == "CLOSE")
    {
    }
    else if (noticeType == "CAPACITY_ALERT")
    {
        {
            if (getCapacity() > 1500)
            {
                cout << "EventGroup " << getName() << " capacity is greater than 1500. Closing all gates!" << endl;
                for (EventComponent *comp : children)
                {
                    Gate *gate = dynamic_cast<Gate *>(comp);
                    if (gate != nullptr)
                    {
                        gate->close();
                    }
                }
            }
        }
    }

    notify(noticeType);
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

void EventGroup::reportStatus() const
{
    cout << "--- Group: " << getName() << " | Capacity: " << getCapacity() << " ---" << endl;
    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->reportStatus();
    }
}

void EventGroup::open()
{
    cout << "EventGroup " << getName() << " is open." << endl;
    for (EventComponent *comp : children)
    {
        comp->open();
    }
}

void EventGroup::close()
{
    cout << "EventGroup " << getName() << " is closed." << endl;
    for (EventComponent *comp : children)
    {
        comp->close();
    }
}