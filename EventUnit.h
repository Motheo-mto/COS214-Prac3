#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "Observer.h"

class EventUnit : public Observer // , public EventComponent - this class still needs to be implemented.
{
public:
    EventUnit() : Observer() {}
    virtual ~EventUnit();
    virtual void update() override;
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void reportStatus() = 0;
    virtual int getCapacity() = 0;
};

#endif // EVENTUNIT_H