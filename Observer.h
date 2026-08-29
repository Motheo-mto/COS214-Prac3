#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>

using namespace std;

class Observer{

virtual void update(int capacity, string status) = 0;

};

#endif