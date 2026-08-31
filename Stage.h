#ifndef STAGE_H
#define STAGE_H

#include "EventUnit.h"

class Stage : public EventUnit
{
public:
    void update(string status, int capacity) override;
    void reportStatus() const override;
    void open() override;
    void close() override;
};

#endif
