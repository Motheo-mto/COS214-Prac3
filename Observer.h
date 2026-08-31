#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>

using namespace std;

class Observer
{
public:
    virtual void update(string status, int capacity) = 0;
};

#endif
