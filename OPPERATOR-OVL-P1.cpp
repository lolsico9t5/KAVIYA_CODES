//Program 1:  Create a class Distance with attributes feet and inches. Overload the + operator to add two Distance objects and return the resulting distance after proper conversion of inches to feet.  Class Design  Class: Distance  Data Members:  int feet  int inches  Member Functions:  getData()  display()  operator + (Distance d) 
#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    // Function to get data
    void getData() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // Function to display data
    void display() {
        cout << feet << " feet and " << inches << " inches" << endl;
    }

    // Overloading the + operator
    Distance operator + (Distance d) {
        Distance temp;
        temp.feet = feet + d.feet;
        temp.inches = inches + d.inches;

        // Proper conversion of inches to feet
        if (temp.inches >= 12) {
            temp.feet += temp.inches / 12;
            temp.inches = temp.inches % 12;
        }
        return temp;
    }
};

int main() {
    Distance d1, d2, d3;

    cout << "Enter details for Distance 1:" << endl;
    d1.getData();

    cout << "\nEnter details for Distance 2:" << endl;
    d2.getData();

    // Adding the two Distance objects using the overloaded + operator
    d3 = d1 + d2;

    cout << "\nResulting Distance:" << endl;
    d3.display();

    return 0;
}