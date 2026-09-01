/**
 * @file Subject.h
 * @brief Defines the Subject role in the Observer pattern.
 */
#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>

/**
 * @class Subject
 * @brief The Subject class that manages a list of observers.
 * 
 * **Design Decision 3: Non-owning observer pointers**
 * This class stores non-owning raw pointers to `Observer` objects. 
 * The actual heap lifetime of the components is managed by the Composite tree (`EventGroup::children`). 
 * Keeping the observer pointers non-owning prevents double-deletion corruption. Observers must outlive 
 * their registration or detach themselves before destruction.
 */
class Subject{
    private:
    vector<Observer*> observerList;
    
    public:
    /**
     * @brief Registers an observer for future event notifications.
     * @param observer Observer to register. Must not be nullptr.
     */
    void attach(Observer* observer);
    
    /**
     * @brief Unregisters an observer so it no longer receives notifications.
     * @param observer Observer to remove.
     */
    void detach(Observer* observer);
    
    /**
     * @brief Notifies all registered observers of a change.
     * @param notifyType The string message/notice to broadcast.
     */
    void notify(string notifyType);
    
    /**
     * @brief Virtual destructor for proper cleanup.
     */
    virtual ~Subject();
};

#endif
