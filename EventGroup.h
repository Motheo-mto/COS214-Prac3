#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include "Observer.h"

class EventGroup : public EventComponent, public Observer
{
private:
    vector<EventComponent *> children;

public:
    void add(EventComponent *component) override;
    void remove(EventComponent *component) override;
    EventGroup();
    EventGroup(int capacity, string status, string name);
    ~EventGroup();
    void update(string status, int capacity) override;
    string reportStatus() const override;
    int getCapacity() const override;
    void open() override;
    void close() override;
};

#endif