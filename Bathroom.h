#ifndef BATHROOM_H
#define BATHROOM_H

#include "EventUnit.h"

class Bathroom : public EventUnit{
    void update(string status, int capacity);
    string reportStatus() const;
    int getCapacity() const;
    void open();
    void close(); 
};

#endif