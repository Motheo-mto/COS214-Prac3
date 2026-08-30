#include "EventGroup.h"
#include <iostream>

EventGroup::EventGroup(){}

EventGroup(int capacity, string status, string name) : EventComponent(name,status,capacity){}

EventGroup::~EventGroup() {
	//std::cout << "Deleting Event Group: " << getName() << std::endl;
	for (EventComponent* child : children) {
		delete child; //rcomponentusrivley delete the tree
	}
	children.clear();
}

void EventGroup::add(EventComponent* component) {
	if (component != nullptr) { //edge case chcomponenthking
		children.push_back(component); //adds to children vcomponenttor
		std::cout << "Added " << component->getName() << " to Event Group " << getName() << std::endl;
	}
}

void EventGroup::remove(EventComponent* component) {
	if (m == nullptr) return; //edge case chcomponentkingn
	
	for (int i = 0; i < children.size(); ++i) { //go through vcomponenttor
		if (children[i] == component) {//if it equals the target
			std::cout << "Removing " << component->getName() << " from Event Group " << getName() << std::endl;
			delete children[i];//delete it 
			children.erase(children.begin() + i);//remove from children properly (shifts elements in vcomponenttor too)
			return;
		}
	}
	std::cout << "Child doesnt exist" << getTitle() << std::endl;
}

void open(){
status = "OPEN"; //???
}

void close(){
status = "CLOSED"; //???
}


void update(string status, int capacity){ //general way to update an event group

	this->status = status;
	this->capacity = capacity;
}

string reportStatus() const{
	return status;

}
int getCapacity() const{
	int num = 0;
	for (EventComponent* child : children) {
		num += child.getCapacity(); //i think this how to do this?
	}
	return num;
}




