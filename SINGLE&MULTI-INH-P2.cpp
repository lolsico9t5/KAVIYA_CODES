/*Lab 9 Programs: 27 March 2026Problem Statement: Design a payroll system where a PermanentEmployee inherits common employee details from Employee and calculates total salary including allowances.Class Relationship:
Employee (Base) $\rightarrow$ PermanentEmployee (Derived)
(PermanentEmployee is derived from Employee.)
Class Design:


Base Class: Employee


empId, name, basicSalary


getEmployeeData(), displayEmployeeData()


Derived Class: PermanentEmployee : public Employee


hra, bonus


calculateSalary(), displaySalary()


Parent Function Invocation (Inside PermanentEmployee):*/
void getData() { 
    getEmployeeData(); // Base class function invoked 
    // Then read hra and bonus 
}

/*
The derived class explicitly calls the parent class function to initialize inherited members.

Answer 2
Method 1: Single Inheritance (Using Private and Getters)
*/
// METHOD 1 - SINGLE INHERITANCE
#include <iostream>
using namespace std;

// Base Class
class Employee {
private:
    int empId;
    string name;
    float basicSalary;

public:
    void getEmployeeData() {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
    }
    
    void displayEmployeeData() {
        cout << "\nEmployee ID: " << empId;
        cout << "\nName: " << name;
        cout << "\nBasic Salary: " << basicSalary << endl;
    }
    
    // Getter for basicSalary (needed in derived class)
    float getBasicSalary() {
        return basicSalary;
    }
};

// Derived Class
class PermanentEmployee : public Employee {
private:
    float hra, bonus, totalSalary;

public:
    void getData() {
        getEmployeeData(); // Parent function call
        cout << "Enter HRA: ";
        cin >> hra;
        cout << "Enter Bonus: ";
        cin >> bonus;
    }
    
    void calculateSalary() {
        totalSalary = getBasicSalary() + hra + bonus;
    }
    
    void displaySalary() {
        displayEmployeeData(); // Parent function call
        cout << "HRA: " << hra;
        cout << "\nBonus: " << bonus;
        cout << "\nTotal Salary: " << totalSalary << endl;
    }
};

// Main Function
int main() {
    PermanentEmployee emp;
    emp.getData();
    emp.calculateSalary();
    emp.displaySalary();
    return 0;
}