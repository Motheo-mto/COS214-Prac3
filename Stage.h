#ifndef STAGE_H
#define STAGE_H

#include "EventUnit.h"
#include <string>

class Stage : public EventUnit
{
public:
    Stage() {}
    void update() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void printStage(); // temporary print statement

    // Possible Operations:
    // void pausePerformance(); // Halts the current act. Triggered by a weather alert. Maybe rain?
    // void resumePerformance(); // Restart the act, once its all clear.
    // bool isOutdoor(); // is the stage susceptible to weather conditions

    // Possible internal state variables:
    // private:
    // bool isOut; // so the stage knows whether a to pause during a weather alert.
    // bool isPerfomanceActice; // track if a band or artist is performing.
};

#endif // STAGE_H