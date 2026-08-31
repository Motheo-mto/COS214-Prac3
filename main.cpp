#include <iostream>
#include "EventGroup.h"
#include "Stage.h"
#include "Food.h"
#include "Bathroom.h"
#include "Gate.h"
#include "Merch.h"

using namespace std;

int main()
{
    cout << " Spring Day Festival Setup " << endl;

    EventGroup *festival = new EventGroup(0, "Spring Day Festival");
    EventGroup *houseZone = new EventGroup(4000, "House Music Area");
    EventGroup *rockZone = new EventGroup(3000, "Rock Music Area");
    EventGroup *popZone = new EventGroup(3000, "Pop Music Area");

    // Leaf nodes
    Stage *mainStage = new Stage("Main Stage", 500);
    Food *pizzaStand = new Food("Pizza Stand", 100);
    Merch *bandMerch = new Merch("Band Merch", 50);
    Gate *mainGate = new Gate("Main Gate", 2000);
    Bathroom *mainBathroom = new Bathroom("Main Bathroom", 20);

    Stage *houseStage = new Stage("House Stage", 300);
    houseStage->setSheltered(false);
    Food *burgerStand = new Food("Burger Stand", 80);
    Bathroom *houseBathroom = new Bathroom("House Bathroom", 10);

    Stage *rockStage = new Stage("Rock Stage", 400);
    rockStage->setSheltered(true); // sheltered stage
    Merch *rockMerch = new Merch("Rock Merch", 30);
    Gate *rockGate = new Gate("Rock Gate", 500);

    Stage *popStage = new Stage("Pop Stage", 600);
    Gate *popGate = new Gate("Pop Gate", 1000);
    Bathroom *popBathroom = new Bathroom("Pop Bathroom", 15);
    Food *tacoStand = new Food("Taco Loco", 50);

    // Building Composite Tree & Observer Registration
    festival->add(mainGate);
    festival->add(mainStage);
    festival->add(pizzaStand);
    festival->add(bandMerch);
    festival->add(mainBathroom);

    houseZone->add(houseStage);
    houseZone->add(burgerStand);
    houseZone->add(houseBathroom);

    rockZone->add(rockStage);
    rockZone->add(rockMerch);
    rockZone->add(rockGate);

    popZone->add(popStage);
    popZone->add(popGate);
    popZone->add(popBathroom);
    popZone->add(tacoStand);

    festival->add(houseZone);
    festival->add(rockZone);
    festival->add(popZone);

    // Test base component setters
    mainStage->setName("Main Festival Stage");

    // Coverage for EventGroup edge cases
    festival->add(nullptr);    // should ignore
    festival->add(mainGate);   // duplicate add, should ignore
    festival->remove(nullptr); // should ignore

    cout << "\n Opening Event " << endl;
    festival->open();
    festival->reportStatus();

    cout << "\n Sending WEATHER_ALERT " << endl;
    festival->update("WEATHER_ALERT");

    cout << "\n Triggering CAPACITY_ALERT " << endl;
    // Set capacity high to trigger Stage close (>=1000) and Gate close (>1500 for EventGroup)
    houseStage->setCapacity(1200);
    rockMerch->setCapacity(rockMerch->getCapacity() + 10);
    tacoStand->setCapacity(tacoStand->getCapacity() + 10);
    mainBathroom->setCapacity(mainBathroom->getCapacity() + 10);

    // Test capacity > 1500 logic directly
    festival->setCapacity(2000);
    festival->update("CAPACITY_ALERT");

    cout << "\n Triggering CAPACITY_ALERT " << endl;
    mainBathroom->setCapacity(mainBathroom->getCapacity() - 5);
    tacoStand->setCapacity(tacoStand->getCapacity() - 5);
    rockMerch->setCapacity(rockMerch->getCapacity() - 5);
    festival->update("CAPACITY_ALERT");

    cout << "\n Sending GIVEAWAY " << endl;
    bandMerch->setCapacity(bandMerch->getCapacity() + 1); // trigger state logic if any
    tacoStand->setCapacity(50);                           // <100 triggers food decrement
    festival->update("GIVEAWAY");

    cout << "\n Sending EVACUATE " << endl;
    festival->update("EVACUATE");

    cout << "\n Sending OPEN " << endl;
    festival->update("OPEN");

    cout << "\n Sending CLOSE " << endl;
    festival->update("CLOSE");

    cout << "\n Reorganizing: Moving components (Task 4.2) " << endl;
    rockZone->remove(rockMerch); // removes from Composite tree and detaches Observer
    popZone->add(rockMerch);     // adds to new Composite tree and attaches Observer
    cout << "rockMerch has been moved from Rock Music Area to Pop Music Area." << endl;

    // Prove that the reorganisation worked by sending a notice only to the Pop Zone
    cout << "\n Proving Reorganization " << endl;
    popZone->update("OPEN"); // rockMerch should now react to this since it's in popZone!

    cout << "\n Testing Edge Case " << endl;
    EventUnit *dummyUnit = new Stage();        // testing default constructor
    EventGroup *dummyGroup = new EventGroup(); // testing default constructor
    dummyGroup->add(dummyUnit);
    delete dummyGroup;

    delete festival; // This cascades and deletes everything in the tree

    return 0;
}
