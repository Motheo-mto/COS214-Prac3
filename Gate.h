#ifndef GATE_H
#define GATE_H

#include "EventUnit.h"

class Gate : public EventUnit
{
public:
    Gate() {}
    void update() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void printGate();


};

#endif