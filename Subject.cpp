#include "Subject.h"
#include "Observer.h"

using namespace std;

bool Subject::attach(Observer* thing)
{
    if(thing == nullptr)
        return false;
    observer.push_back(thing);
    return true;
}

bool Subject::detach(Observer* thing)
{
    bool found = false;
    vector<Observer*>::iterator it = observer.begin();
    while((it != observer.end()) && (!found))
    {
        if(*it == thing)
        {
            found = true;
            observer.erase(it);
        }
        else
        {
            ++it;
        }
    }
    return found;
}

void Subject::notify()
{
    vector<Observer*>::iterator it;
    for(it = observer.begin(); it != observer.end(); ++it)
    {
        (*it)->update();
    }
}