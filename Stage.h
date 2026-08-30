#ifndef STAGE_H
#define STAGE_H

#include "EventUnit.h"

class Stage : public EventUnit{
    void update(string status, int capacity) override;
    string reportStatus() const override;
    void open() override;
    void close() override; 
};

#endif