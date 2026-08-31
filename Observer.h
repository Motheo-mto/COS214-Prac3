#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>

using namespace std;

class Observer
{
public:
    virtual void update(string noticeType) = 0;
    virtual ~Observer() = default;
};

#endif
