#ifndef MERCH_H
#define MERCH_H

#include "EventUnit.h"

class Merch : public EventUnit
{
public:
    Merch() {};
    void update() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void printMerch();


};

#endif