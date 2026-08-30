#ifndef FOOD_H
#define FOOD_H

#include "EventUnit.h"

class Food : public EventUnit
{
public:
    Food() {}
    void update() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void printFood();


};

#endif