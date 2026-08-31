#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

class EventUnit : public EventComponent, public Observer
{
public:
    ~EventUnit();
    EventUnit();
    EventUnit(string name, string status, int capacity);
    virtual void update(string status, int capacity) = 0;
    virtual void reportStatus() const = 0;
    virtual int getCapacity() const = 0;
};

#endif
