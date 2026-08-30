#ifndef FOOD_H
#define FOOD_H

#include "EventUnit.h"

class Food : public EventUnit{
    void update(string status, int capacity);
    string reportStatus() const;
    int getCapacity() const;
    void open();
    void close(); 
};

#endif