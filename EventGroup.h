#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H
#include "EventComponent.h"
#include <string>
using namespace std;

class EventGroup : public EventComponent {
    private:
	std::vector<EventComponent*> children;
public:
    EventGroup(string name);

	void add(EventComponent* ec);

	void remove(EventComponent* ec);

    std::vector<EventComponent*> getChildren();

	~EventGroup();
};

#endif