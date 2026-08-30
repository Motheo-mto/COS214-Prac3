#ifndef FOOD_H
#define FOOD_H

#include "EventUnit.h"

class Food : public EventUnit{
    void update(string status, int capacity) override;
    string reportStatus() const override;
    void open() override;
    void close() override; 
};

#endif