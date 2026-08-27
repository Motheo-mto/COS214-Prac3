#include "EventGroup.h"
#include <iostream>

EventGroup::EventGroup(std::string name) : EventComponent(name) {
	// children is initialized as empty
}

void EventGroup::add(EventComponent* ec) {
	if (ec != nullptr) { //edge case chechking
		children.push_back(ec); //adds to children vector
		std::cout << "Added " << ec->getName() << " to Event Group " << getName() << std::endl;
	}
}

void EventGroup::remove(EventComponent* ec) {
	if (m == nullptr) return; //edge case checkingn
	
	for (int i = 0; i < children.size(); ++i) { //go through vector
		if (children[i] == ec) {//if it equals the target
			std::cout << "Removing " << ec->getName() << " from Event Group " << getName() << std::endl;
			delete children[i];//delete it 
			children.erase(children.begin() + i);//remove from children properly (shifts elements in vector too)
			return;
		}
	}
	std::cout << "Child doesnt exist" << getTitle() << std::endl;
}

std::vector<EventComponent*> EventGroup::getChildren() {
	return children;
}


EventGroup::~EventGroup() {
	std::cout << "Deleting Event Group: " << getName() << std::endl;
	for (EventComponent* child : children) {
		delete child; //recusrivley delete the tree
	}
	children.clear();
}