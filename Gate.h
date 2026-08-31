#ifndef GATE_H
#define GATE_H

#include "EventUnit.h"

class Gate : public EventUnit
{
public:
    void update(string status, int capacity) override;
    void reportStatus() const override;
    void open() override;
    void close() override;
};

#endif