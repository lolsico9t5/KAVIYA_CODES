/*
Program 4: Cargo Shipment

Question Statement
Topic: Cargo Shipment utilizing Multiple Inheritance.  
PDF

Problem Statement: Create a system to calculate shipment charges for refrigerated cargo using multiple inheritance.  
PDF

Charge Logic: Cargo charges are calculated based on weight and destination, while refrigeration charges are based on cooling capacity and power consumption. The derived class must combine both charges to display the final bill.  
PDF
+ 1

Class Relationship: RefrigeratedCargo is derived from both Cargo and RefrigerationUnit classes.  
PDF

Base Class 1 (Cargo): Contains data members cargoId, weight, destination, and cargoCharge.  
PDF

Base Class 1 Functions: Includes getCargoData(), calculateCargoCharge(ratePerKg, distance) (Formula: weight * ratePerKg * distance), and displayCargoData().  
PDF

Base Class 2 (RefrigerationUnit): Contains data members temperatureRange, coolingCapacity (in tons), powerConsumption, and refrigerationCharge.  
PDF

Base Class 2 Functions: Includes getRefrigerationData(), calculateRefrigerationCharge(ratePerTon) (Formula: coolingCapacity * ratePerTon), and displayRefrigerationData().  
PDF

Derived Class (RefrigeratedCargo): Inherits publicly from both base classes and contains data members shipmentDate and totalBill.  
PDF

Derived Class Functions: Includes getRefrigeratedCargoData(), calculateTotalBill() (Formula: calculateCargoCharge + refrigerationCharge), and displayDetails().  
PDF

Sample Input: Cargo ID: 101, Weight: 500 kg, Destination: Chennai, Temperature Range: -10 to 5°C, Cooling Capacity: 20 units, Power Consumption: 5 kW, Shipment Date: 15-04-2026.*/
#include <iostream>
#include <string>
using namespace std;

// Base Class 1: Cargo
class Cargo {
protected:
    int cargoId;
    double weight;
    string destination;
    double cargoCharge;

public:
    void getCargoData() {
        cout << "Enter Cargo ID: ";
        cin >> cargoId;
        cout << "Enter Weight (kg): ";
        cin >> weight;
        cout << "Enter Destination: ";
        cin >> destination;
    }
    
    void calculateCargoCharge(double ratePerKg, double distance) {
        cargoCharge = weight * ratePerKg * distance;
    }
    
    void displayCargoData() {
        cout << "\nCargo ID: " << cargoId;
        cout << "\nWeight: " << weight << " kg";
        cout << "\nDestination: " << destination;
        cout << "\nCargo Charge: " << cargoCharge << endl;
    }
};

// Base Class 2: RefrigerationUnit
class RefrigerationUnit {
protected:
    string temperatureRange;
    double coolingCapacity;
    double powerConsumption;
    double refrigerationCharge;

public:
    void getRefrigerationData() {
        cout << "Enter Temperature Range: ";
        cin.ignore();
        getline(cin, temperatureRange);
        cout << "Enter Cooling Capacity (tons): ";
        cin >> coolingCapacity;
        cout << "Enter Power Consumption (kW): ";
        cin >> powerConsumption;
    }
    
    void calculateRefrigerationCharge(double ratePerTon) {
        refrigerationCharge = coolingCapacity * ratePerTon;
    }
    
    void displayRefrigerationData() {
        cout << "Temperature Range: " << temperatureRange;
        cout << "\nCooling Capacity: " << coolingCapacity;
        cout << "\nPower Consumption: " << powerConsumption;
        cout << "\nRefrigeration Charge: " << refrigerationCharge << endl;
    }
};

// Derived Class
class RefrigeratedCargo : public Cargo, public RefrigerationUnit {
private:
    string shipmentDate;
    double totalBill;

public:
    void getRefrigeratedCargoData() {
        getCargoData();          // From Cargo
        getRefrigerationData();  // From RefrigerationUnit
        cout << "Enter Shipment Date: ";
        cin >> shipmentDate;
    }
    
    void calculateTotalBill(double ratePerKg, double distance, double ratePerTon) {
        calculateCargoCharge(ratePerKg, distance);
        calculateRefrigerationCharge(ratePerTon);
        totalBill = cargoCharge + refrigerationCharge;
    }
    
    void displayDetails() {
        displayCargoData();
        displayRefrigerationData();
        cout << "Shipment Date: " << shipmentDate;
        cout << "\nTotal Bill: " << totalBill << endl;
    }
};

// Main Function
int main() {
    RefrigeratedCargo rc;
    double ratePerKg, distance, ratePerTon;
    
    rc.getRefrigeratedCargoData();
    
    cout << "Enter Rate per Kg: ";
    cin >> ratePerKg;
    cout << "Enter Distance: ";
    cin >> distance;
    cout << "Enter Rate per Ton (Refrigeration): ";
    cin >> ratePerTon;
    
    rc.calculateTotalBill(ratePerKg, distance, ratePerTon);
    rc.displayDetails();
    
    return 0;
}
