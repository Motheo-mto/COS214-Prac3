/**
 * @file Observer.h
 * @brief Defines the Observer interface.
 */
#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>

using namespace std;

/**
 * @class Observer
 * @brief The interface for receiving notifications from a Subject.
 * 
 * **Design Decision 2: Push Architecture**
 * We use a **Push** architecture for the Observer pattern. The `update()` method 
 * accepts a `string noticeType` argument containing the exact event state directly from the Subject. 
 * This avoids the need for observers to hold a back-reference to the Subject or explicitly query it for state, 
 * making the multi-level cascade much simpler and cleaner.
 */
class Observer
{
public:
    /**
     * @brief Called by the Subject to push a notification to this observer.
     * @param noticeType The event notice string (e.g. "WEATHER_ALERT").
     */
    virtual void update(string noticeType) = 0;
    
    /**
     * @brief Virtual destructor.
     */
    virtual ~Observer() = default;
};

#endif
