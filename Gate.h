/**
 * @file Gate.h
 * @brief Defines the Gate operational unit.
 */
#ifndef GATE_H
#define GATE_H

#include "EventUnit.h"

/**
 * @class Gate
 * @brief A concrete Leaf representing a Gate in the event.
 */
class Gate : public EventUnit
{
public:
    Gate();
    
    /**
     * @brief Constructs a Gate.
     * @param name Name of the gate.
     * @param capacity Capacity limit for the gate.
     */
    Gate(string name, int capacity);
    
    ~Gate();
    
    /**
     * @brief Handles incoming event notifications (e.g., EVACUATE forces gates open).
     * @param noticeType Event string to react to.
     */
    void update(string noticeType) override;
    
    void reportStatus() const override;
    
    int getCapacity() const override;
    
    void open() override;
    
    void close() override;
};

#endif