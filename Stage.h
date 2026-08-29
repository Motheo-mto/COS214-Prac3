#ifndef STAGE_H
#define STAGE_H

#include "EventUnit.h"

class Stage : public EventUnit{
    void update(string status, int capacity);
    string reportStatus() const;
    int getCapacity() const;
    void open();
    void close(); 
};

#endif