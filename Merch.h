#ifndef MERCH_H
#define MERCH_H

#include "EventUnit.h"

class Merch : public EventUnit
{
public:
    void update(string noticeType) override;
    void reportStatus() const override;
    void open() override;
    void close() override;
};

#endif