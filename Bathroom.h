#ifndef BATHROOM_H
#define BATHROOM_H

#include "EventUnit.h"

class Bathroom : public EventUnit
{
private:
    int cleanliness;
    int previousCapacity;

public:
    Bathroom(string name, int capacity);
    ~Bathroom();
    void update(string noticeType) override;
    void reportStatus() const override;
    int getCapacity() const override;
    void open() override;
    void close() override;

private:
    int cleanlines;
};

#endif