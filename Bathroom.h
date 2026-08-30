#ifndef BATHROOM_H
#define BATHROOM_H

#include "EventUnit.h"

class Bathroom : public EventUnit
{
public:
    Bathroom() {}
    void update() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void printBathroom();


};

#endif