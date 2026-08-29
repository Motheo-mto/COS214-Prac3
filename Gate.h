#ifndef GATE_H
#define GATE_H

#include "EventUnit.h"

class Gate : public EventUnit{
    void update(string status, int capacity);
    string reportStatus() const;
    int getCapacity() const;
    void open();
    void close(); 
};

#endif