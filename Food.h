#ifndef FOOD_H
#define FOOD_H

#include "EventUnit.h"

class Food : public EventUnit
{
public:
    Food() {}
    void update() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void printFood(); // temporary print statement

    // Possible Operations:
    // void triggerAllergenAlert(); // stops the sale of certain items or triggers a warning to attendees
    // void clearAllergenAlert(); // resumes normal operations once the issue is risolved.
    // void serveMeals(int count); // decrements available stock. If stock is 0, trigger a status change to "Sold Out".
    // void receiveRestock(int quantity); // restocks inventory and reopens the stall if it was closed.

    // Possible internal state variables:
    // private:
    // int stockLevel; // to track when they need to suspend
    // bool allergenWarningActive; // to change during health issues
};

#endif // FOOD_H