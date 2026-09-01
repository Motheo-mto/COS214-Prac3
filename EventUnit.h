/**
 * @file EventUnit.h
 * @brief Defines the abstract Leaf class in the Composite pattern.
 */
#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

/**
 * @class EventUnit
 * @brief Abstract Leaf node representing an operational unit.
 * 
 * Inherits from EventComponent (Component) and Observer.
 */
class EventUnit : public EventComponent, public Observer
{
public:
    /**
     * @brief Virtual destructor.
     */
    ~EventUnit();
    
    EventUnit();
    
    /**
     * @brief Constructor for a generic EventUnit.
     * @param name Name of the unit.
     * @param capacity Capacity of the unit.
     */
    EventUnit(string name, int capacity);
    
    /**
     * @brief Receives pushed notification from parent Subject.
     * @param noticeType The notice string.
     */
    virtual void update(string noticeType) = 0;
    
    /**
     * @brief Reports status of the unit.
     */
    virtual void reportStatus() const = 0;
    
    /**
     * @brief Returns the capacity of the unit.
     * @return int representing capacity.
     */
    virtual int getCapacity() const = 0;
    
    bool isOpen; ///< Boolean indicating if the unit is currently open.
};

#endif
