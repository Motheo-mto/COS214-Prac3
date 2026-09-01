/**
 * @file EventGroup.h
 * @brief Defines the Composite class in the Composite pattern.
 */
#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include "Observer.h"

/**
 * @class EventGroup
 * @brief A Composite class representing a grouping of event components (e.g. zones, areas).
 * 
 * **Design Decision 1: Dual Pattern Participation**
 * `EventGroup` implements both `Subject` (via `EventComponent`) and `Observer`.
 * This is not a misuse of the pattern. Instead, it bridges the cascade of notifications:
 * it acts as an Observer to its parent group (receiving updates from above), and 
 * acts as a Subject to its children (pushing updates downwards).
 */
class EventGroup : public EventComponent, public Observer
{
private:
    vector<EventComponent *> children;

public:
    /**
     * @brief Adds a child component to the group and attaches it as an observer.
     * @param component Raw pointer to the child. Ownership is transferred to this EventGroup.
     */
    void add(EventComponent *component) override;
    
    /**
     * @brief Removes a child component and detaches it as an observer.
     * @param component Raw pointer to the child to remove.
     */
    void remove(EventComponent *component) override;
    
    EventGroup();
    
    /**
     * @brief Constructs an EventGroup.
     * @param capacity Total aggregate capacity (or default).
     * @param name Name of the group.
     */
    EventGroup(int capacity, string name);
    
    /**
     * @brief Destructor recursively deletes all owned children components.
     */
    ~EventGroup();
    
    /**
     * @brief Receives a notification from a parent and cascades it to children.
     * @param noticeType The string message/notice pushed from the parent.
     */
    void update(string noticeType) override;
    
    /**
     * @brief Recursively reports status of this group and its children.
     */
    void reportStatus() const override;
    
    /**
     * @brief Calculates aggregate capacity of all children.
     * @return int representing total capacity.
     */
    int getCapacity() const override;
    
    /**
     * @brief Recursively opens this group and its children.
     */
    void open() override;
    
    /**
     * @brief Recursively closes this group and its children.
     */
    void close() override;
};

#endif