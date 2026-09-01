/**
 * @file EventComponent.h
 * @brief Defines the abstract base Component in the Composite pattern.
 */
#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include "Subject.h"

/**
 * @class EventComponent
 * @brief The common Component interface for the EventFlow system.
 * 
 * Provides common operations for both EventGroup (Composite) and EventUnit (Leaf).
 * Inherits from Subject so that both groups and units can be observed.
 */
class EventComponent : public Subject
{
private:
    string name;
    int capacity;

public:
    /**
     * @brief Adds a child component (used by composites).
     * @param component Raw pointer to the component to add. Ownership is transferred to the composite.
     */
    virtual void add(EventComponent *component);
    
    /**
     * @brief Removes a child component.
     * @param component Raw pointer to the component to remove.
     */
    virtual void remove(EventComponent *component);
    
    EventComponent();
    
    /**
     * @brief Constructor setting name and capacity.
     * @param name Name of the component.
     * @param capacity Capacity of the component.
     */
    EventComponent(string name, int capacity);
    
    /**
     * @brief Virtual destructor to ensure proper cleanup of derived classes.
     */
    virtual ~EventComponent() = 0;
    
    /**
     * @brief Gets the name of the component.
     * @return string containing the name.
     */
    string getName() const;
    
    /**
     * @brief Sets the name of the component.
     * @param n New name.
     */
    void setName(string n);
    
    /**
     * @brief Reports the current status of the component.
     */
    virtual void reportStatus() const = 0;
    
    /**
     * @brief Gets the capacity of the component.
     * @return int representing capacity.
     */
    virtual int getCapacity() const;
    
    /**
     * @brief Sets the capacity of the component.
     * @param n New capacity.
     */
    void setCapacity(int n);
    
    /**
     * @brief Opens the component.
     */
    virtual void open() = 0;
    
    /**
     * @brief Closes the component.
     */
    virtual void close() = 0;
};

#endif