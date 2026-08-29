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
    void printGate(); // temporary print statement

    // Possible Operations:
    // void haltAdmissions(); // temporarily locks the gate.
    // void resumeAdmissions(); // reopens the gate for normal entry.
    // void recordEntry(int count); // increments the current capacity;

    // Possible internal state variables:
    // private:
    // int currAdmissions; // compare against the base class capacity.
    // bool isLocked; // response to evacuate or capacity reached.
};

#endif // GATE_H