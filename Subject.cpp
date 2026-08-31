#include "Subject.h"
#include "Observer.h"

using namespace std;

void Subject::attach(Observer *observer)
{
    if (observer == nullptr)
        return;

    // checking for duplicates
    for (size_t i = 0; i < observerList.size(); i++)
    {
        if (observerList[i] == observer)
        {
            return;
        }
    }
    observerList.push_back(observer);
}

void Subject::detach(Observer *observer)
{
    vector<Observer *>::iterator it = observerList.begin();
    while (it != observerList.end())
    {
        if (*it == observer)
        {
            it = observerList.erase(it);
            break;
        }
        else
        {
            ++it;
        }
    }
}

void Subject::notify(string noticeType)
{
    vector<Observer *>::iterator it;
    for (it = observerList.begin(); it != observerList.end(); ++it)
    {
        (*it)->update(noticeType);
    }
}

Subject::~Subject() {}