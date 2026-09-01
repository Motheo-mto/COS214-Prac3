/**
 * @file Food.h
 * @brief Defines the Food vendor operational unit.
 */
#ifndef FOOD_H
#define FOOD_H

#include "EventUnit.h"

/**
 * @class Food
 * @brief A concrete Leaf representing a Food vendor.
 */
class Food : public EventUnit
{
public:
    Food();

private:
    int foodLeft; ///< The amount of food stock left.
    int previousCapacity; ///< Used to track capacity changes.

public:
    /**
     * @brief Constructs a Food unit.
     * @param name Name of the vendor.
     * @param capacity Capacity constraint.
     */
    Food(string name, int capacity);
    
    ~Food();
    
    /**
     * @brief Handles incoming event notifications.
     * @param noticeType Event string to react to.
     */
    void update(string noticeType) override;
    
    void reportStatus() const override;
    
    int getCapacity() const override;
    
    void open() override;
    
    void close() override;
};

#endif