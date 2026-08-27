#include "EventComponent.h"
#include <iostream>
#include <string>

EventComponent::EventComponent(std::string n){
    name = n;
}

string EventComponent::getName() {
	return this->name;
}

void EventComponent::doSomething(){
    std::cout<< this->getName() << " is doing something"<<std::endl;
}

 
EventComponent::~EventComponent(){}