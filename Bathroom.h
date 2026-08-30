#ifndef BATHROOM_H
#define BATHROOM_H

#include "EventUnit.h"

class Bathroom : public EventUnit{
    void update(string status, int capacity) override;
    string reportStatus() const override ;
    void open() override;
    void close() override; 
};

#endif