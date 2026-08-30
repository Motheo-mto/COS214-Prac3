#ifndef MERCH_H
#define MERCH_H

#include "EventUnit.h"

class Merch : public EventUnit{
    void update(string status, int capacity);
    string reportStatus() const;
    int getCapacity() const;
    void open();
    void close(); 
};

#endif