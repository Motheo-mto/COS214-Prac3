/**
 * @file Bathroom.h
 * @brief Defines the Bathroom operational unit.
 */
#ifndef BATHROOM_H
#define BATHROOM_H

#include "EventUnit.h"

/**
 * @class Bathroom
 * @brief A concrete Leaf representing a Bathroom facility.
 */
class Bathroom : public EventUnit
{
private:
    int cleanliness; ///< Tracks the cleanliness level of the bathroom.
    int previousCapacity; ///< Used to determine if capacity increased or decreased.

public:
    /**
     * @brief Constructs a Bathroom.
     * @param name Name of the bathroom.
     * @param capacity Capacity limit.
     */
    Bathroom(string name, int capacity);
    
    ~Bathroom();
    
    /**
     * @brief Handles incoming event notifications (e.g., cleanliness drops during WEATHER_ALERT).
     * @param noticeType Event string to react to.
     */
    void update(string noticeType) override;
    
    void reportStatus() const override;
    
    int getCapacity() const override;
    
    void open() override;
    
    void close() override;

};

#endif