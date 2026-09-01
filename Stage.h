/**
 * @file Stage.h
 * @brief Defines the Stage operational unit.
 */
#ifndef STAGE_H
#define STAGE_H

#include "EventUnit.h"

/**
 * @class Stage
 * @brief A concrete Leaf representing a Stage.
 */
class Stage : public EventUnit
{
public:
    Stage();
    
    /**
     * @brief Constructs a Stage.
     * @param name Name of the stage.
     * @param capacity Capacity of the stage.
     */
    Stage(string name, int capacity);
    
    ~Stage();
    
    /**
     * @brief Handles incoming event notifications (e.g., WEATHER_ALERT closes unsheltered stages).
     * @param noticeType Event string to react to.
     */
    void update(string noticeType) override;
    
    void reportStatus() const override;
    
    int getCapacity() const;
    
    void open() override;
    
    void close() override;
    
    /**
     * @brief Sets whether the stage is sheltered from weather.
     * @param sheltered True if sheltered, false otherwise.
     */
    void setSheltered(bool sheltered);
private:
    bool isSheltered; ///< Tracks if the stage is sheltered from weather.
};

#endif
