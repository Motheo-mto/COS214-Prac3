#ifndef BATHROOM_H
#define BATHROOM_H

#include "EventUnit.h"

class Bathroom : public EventUnit
{
public:
    Bathroom() {}
    void update() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void printBathroom(); // temporary print statement

    // Possible Operations:
    // void requestCleaning(); // change status to unavailable while cleaning stuff locks in.
    // void completeCleaning(); // reopens the facility

    // Possible internal state variables:
    // private:
    // int cleanliness; // range from 0 to 100 that goes the more attendees use the bathroom.
    // bool requiresMaintenance; // true if soap or toilet paper runs out or if cleanliness drops
    // bool isPlumbingOk; // plumbing could be damaged during a weather event.
};

#endif // BATHROOM_H