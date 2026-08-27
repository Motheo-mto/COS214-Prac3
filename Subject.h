#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer; // Forward Declaration

class Subject
{
public:
    virtual ~Subject() {}
    bool attach(Observer *);
    bool detach(Observer *);
    void notify();

private:
    std::vector<Observer *> observer;
};

#endif // SUBJECT_H