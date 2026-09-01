/**
 * @file Merch.h
 * @brief Defines the Merchandise vendor operational unit.
 */
#ifndef MERCH_H
#define MERCH_H

#include "EventUnit.h"

/**
 * @class Merch
 * @brief A concrete Leaf representing a Merchandise vendor.
 */
class Merch : public EventUnit
{
private:
    int stockLevel; ///< Tracks the current stock level.
    int previousCapacity; ///< Tracks capacity increments.
public:
    Merch();
    
    /**
     * @brief Constructs a Merch unit.
     * @param name Name of the vendor.
     * @param capacity Capacity limit.
     */
    Merch(string name, int capacity);
    
    ~Merch();
    
    /**
     * @brief Handles incoming event notifications (e.g., triggers giveaway if stock is high).
     * @param noticeType Event string to react to.
     */
    void update(string noticeType) override;
    
    void reportStatus() const override;
    
    int getCapacity() const override;
    
    void open() override;
    
    void close() override;
};

#endif