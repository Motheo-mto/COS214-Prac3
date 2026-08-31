#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>

class Subject{
    private:
    vector<Observer*> observerList;
    
    public:
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify(string notifyType);
    virtual ~Subject();
};

#endif
