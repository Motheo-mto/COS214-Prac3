#ifndef MERCH_H
#define MERCH_H

#include "EventUnit.h"

class Merch : public EventUnit
{
public:
    Merch() {};
    void update() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void printMerch(); // temporary print statement

    // Possible Operations:
    // void secureMerch(); // if a weather alert is received, the merch stand needs to cover its stock.
    // void moreDisplay(string performer); // if schedule changes, bring the performer's merch to the front stall.
    // void lockCashRegister(); // if an there's an EVACUATE, secure the cash and close down.
    // void processSale(int quantity); decrement available stock and add to a sale counter.

    // Possible internal state variables:
    // private:
    // bool isMerchSafe; // tracks if stock is protected. if a weather alert comes in.
    // string featuredPerformer; // Stores the name of the artist or band whose merch is being displayed.
    // int totalStock; // tracks remaining inventory. could maybe trigger an restocks if it drops below a certain number?
};

#endif // MERCH_H