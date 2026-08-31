#ifndef MERCH_H
#define MERCH_H

#include "EventUnit.h"

class Merch : public EventUnit
{
public:
    Merch();
    Merch(string name, string status, int capacity);
    ~Merch();
    void update(string noticeType) override;
    void reportStatus() const override;
    int getCapacity() const override;
    void open() override;
    void close() override;
private:
    int stockLevel;
};

#endif