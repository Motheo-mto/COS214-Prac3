#include "Subject.h"
#include "Observer.h"

using namespace std;

void Subject::attach(Observer *observer)
{
    if (observer == nullptr)
        return;
    observerList.push_back(observer);
}

void Subject::detach(Observer *observer)
{
    bool found = false;
    vector<Observer *>::iterator it = observerList.begin();
    while ((it != observerList.end()) && (!found))
    {
        if (*it == observer)
        {
            found = true;
            observerList.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Subject::notify(int capacity, string status)
{
    vector<Observer *>::iterator it;
    for (it = observerList.begin(); it != observerList.end(); ++it)
    {
        (*it)->update(capacity, status);
    }
}