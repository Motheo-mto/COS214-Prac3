#ifndef GATE_H
#define GATE_H

#include "EventUnit.h"

class Gate : public EventUnit
{
public:
    Gate();
    Gate(string name, int capacity);
    ~Gate();
    void update(string noticeType) override;
    void reportStatus() const override;
    int getCapacity() const override;
    void open() override;
    void close() override;
};

#endif