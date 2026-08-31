#ifndef MERCH_H
#define MERCH_H

#include "EventUnit.h"

class Merch : public EventUnit
{
public:
    void update(string status, int capacity) override;
    string reportStatus() const override;
    void open() override;
    void close() override;
};

#endif