#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"


class EventGroup : public EventComponent , public Observer{
    private:
    vector<EventComponent*> children;

    public:
    void add(EventComponent component);
    void remove(EventComponent component);
    EventGroup();
    EventGroup(int capacity, string status, string name);
    ~EventGroup();
    void update(string status, int capacity);
    string reportStatus() const;
    int getCapacity() const;
    void open();
    void close();          
};

#endif