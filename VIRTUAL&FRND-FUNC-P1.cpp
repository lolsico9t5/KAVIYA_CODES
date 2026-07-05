/*
 Shipping Cost Calculation Using Virtual Functions
Problem Statement
Create a system to calculate shipping charges for different transportation modes. A base class Shipment stores common shipment details. Derived classes RoadShipment, AirShipment, and SeaShipment override the calculateShippingCost() function to compute shipping charges based on different pricing rules.

Class Design
Base Class: Shipment

Data Members: int shipmentId, float weight, float distance

Member Functions: getShipmentData(), virtual calculateShippingCost(), displayShipmentData()

Derived Class: RoadShipment: public Shipment

Data Members: float tollCharges

Member Functions: getRoadShipmentData(), calculateShippingCost() (overrides base class function)

Derived Class: AirShipment: public Shipment

Data Members: float airportHandlingFee

Member Functions: getAirShipmentData(), calculateShippingCost() (overrides base class function)

Derived Class: SeaShipment: public Shipment

Data Members: float containerCharges

Member Functions: getSeaShipmentData(), calculateShippingCost() (overrides base class function)
*/
#include <iostream>
using namespace std;

// Base Class
class Shipment {
protected:
    int shipmentId;
    float weight;
    float distance;
public:
    void getShipmentData() {
        cout << "Enter Shipment ID: ";
        cin >> shipmentId;
        cout << "Enter Weight (kg): ";
        cin >> weight;
        cout << "Enter Distance (km): ";
        cin >> distance;
    }
    
    virtual float calculateShippingCost() {
        return 0; // Base implementation
    }
    
    void displayShipmentData() {
        cout << "\nShipment ID: " << shipmentId;
        cout << "\nWeight: " << weight;
        cout << "\nDistance: " << distance << endl;
    }
};

// Derived Class: RoadShipment
class RoadShipment : public Shipment {
    float tollCharges;
public:
    void getRoadShipmentData() {
        getShipmentData();
        cout << "Enter Toll Charges: ";
        cin >> tollCharges;
    }
    
    float calculateShippingCost() override {
        return (weight * distance * 0.5) + tollCharges;
    }
};

// Derived Class: AirShipment
class AirShipment : public Shipment {
    float airportHandlingFee;
public:
    void getAirShipmentData() {
        getShipmentData();
        cout << "Enter Airport Handling Fee: ";
        cin >> airportHandlingFee;
    }
    
    float calculateShippingCost() override {
        return (weight * distance * 1.5) + airportHandlingFee;
    }
};

// Derived Class: SeaShipment
class SeaShipment : public Shipment {
    float containerCharges;
public:
    void getSeaShipmentData() {
        getShipmentData();
        cout << "Enter Container Charges: ";
        cin >> containerCharges;
    }
    
    float calculateShippingCost() override {
        return (weight * distance * 0.3) + containerCharges;
    }
};

// Main Function
int main() {
    Shipment *s;
    
    RoadShipment r;
    s = &r;
    r.getRoadShipmentData();
    s->displayShipmentData();
    cout << "Shipping Cost: " << s->calculateShippingCost() << "\n\n";
    
    AirShipment a;
    s = &a;
    a.getAirShipmentData();
    s->displayShipmentData();
    cout << "Shipping Cost: " << s->calculateShippingCost() << "\n\n";
    
    SeaShipment se;
    s = &se;
    se.getSeaShipmentData();
    s->displayShipmentData();
    cout << "Shipping Cost: " << s->calculateShippingCost() << "\n";
    
    return 0;
}