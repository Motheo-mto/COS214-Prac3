#ifndef FOOD_H
#define FOOD_H

#include "EventUnit.h"

class Food : public EventUnit
{
public:
    Food();

private:
    int foodLeft;
    int previousCapacity;

public:
    Food(string name, int capacity);
    ~Food();
    void update(string noticeType) override;
    void reportStatus() const override;
    int getCapacity() const override;
    void open() override;
    void close() override;
};

#endif