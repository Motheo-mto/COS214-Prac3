#ifndef STAGE_H
#define STAGE_H

#include "EventUnit.h"

class Stage : public EventUnit
{
public:
    Stage();
    Stage(string name, string status, int capacity);
    ~Stage();
    void update(string noticeType) override;
    void reportStatus() const override;
    int getCapacity() const;
    void open() override;
    void close() override;
private:
    bool isSheltered;
};

#endif
