#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"


class EventGroup : public EventComponent , public Observer{
    private:
    vector<EventComponent*> children;

    public:
    void add(EventComponent component) override;
    void remove(EventComponent component) override;
    EventGroup();
    EventGroup(int capacity, string status, string name);
    ~EventGroup();
    void update(int capacity, string status) override;
    string reportStatus() const override;
    int getCapacity() const override;
    void open() override;
    void close() override;          
};

#endif