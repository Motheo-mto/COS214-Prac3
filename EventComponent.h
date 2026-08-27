#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <iostream>
#include <string>

using namespace std;

class EventComponent{ // will inherit from subject ltr, and from observer (?)
    private:
    std::string name; //event name
    bool gate; //whether or not the areas gate is openede or closed
    int capactiy; //no. of people
public:
    EventComponent(std::string name);

    virtual void doSomething(); //what we make them do????

    virtual void add(EventComponent* ec) = 0;

    virtual void remove(EventComponent* ec) = 0;

    virtual void getChild(int i);

    virtual std::string getName();

    virtual ~EventComponent();

virtual void open() = 0; //open event area

virtual void close() = 0;// close event area

virtual void reportStatus() const = 0; //is it open, closed, power issues etc

virtual int getCapacity() const = 0; //people



};

#endif