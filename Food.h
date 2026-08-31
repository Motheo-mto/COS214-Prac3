#ifndef FOOD_H
#define FOOD_H

#include "EventUnit.h"

class Food : public EventUnit
{
public:
    void update(string status, int capacity) override;
    void reportStatus() const override;
    void open() override;
    void close() override;
};

#endif