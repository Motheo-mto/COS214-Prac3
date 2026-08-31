#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include "Subject.h"

class EventComponent : public Subject
{
private:
    string name;
    int capacity;
    string status;

public:
    virtual void add(EventComponent *component);
    virtual void remove(EventComponent *component);
    EventComponent();
    EventComponent(string name, string status, int capactiy);
    virtual ~EventComponent() = 0;
    string getName() const;
    void setName(string n);
    void setStatus(string n);
    virtual string reportStatus() const = 0;
    virtual int getCapacity() const = 0;
    void setCapacity(int n);
    virtual void open() = 0;
    virtual void close() = 0;
};

#endif