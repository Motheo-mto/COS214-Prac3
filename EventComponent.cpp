#include "EventComponent.h"
#include <iostream>
#include <string>

EventComponent::EventComponent(){}

EventComponent(string name, string status, int capactiy){
    this->name = name;
    this->status = status;
    this->capacity = capacity;
}
string getName() const{
    return name;
}

void setName(string n){
    name = n;
}
void setStatus(string n){
    status = n;
}
void setCapacity(int n){
    capacity = n;
}
 
EventComponent::~EventComponent(){}