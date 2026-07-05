/*Write a C++ program to illustrate Single Inheritance using a Student class.
Create a base class Student with the following private data members:
Name (string)
Roll number
Marks in three subjects
Include member functions to:
Ο Read student details
Display student details
Calculate total marks
Derive a class Result from Student that:
Calculates the average marks
Assigns a grade based on the average as follows:
Average,Grade
≥75,Distinction
≥60,First Class
≥50,Second Class
≥40,Pass
<40,Fail
*/
// Single Inheritance
// METHOD 1 - Public Derivation
#include <iostream>
using namespace std;

// Base class
class Student {
private:
    string name;
    int roll;
    int m1, m2, m3;

public:
    void setData() {
        cout << "Enter Name and Roll: ";
        cin >> name >> roll;
        cout << "Enter 3 subject marks: ";
        cin >> m1 >> m2 >> m3;
    }
    
    void displayStudent() {
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
        cout << "Marks: " << m1 << ", " << m2 << ", " << m3 << endl;
    }
    
    // Total marks
    int totalMarks() {
        return m1 + m2 + m3;
    }
};

// Derived class
class Result : public Student {
private:
    float avg;
    string grade;

public:
    void calculate() {
        avg = totalMarks() / 3.0;
        if (avg >= 75)
            grade = "Distinction";
        else if (avg >= 60)
            grade = "First Class";
        else if (avg >= 50)
            grade = "Second Class";
        else if (avg >= 40)
            grade = "Pass";
        else
            grade = "Fail";
    }
    
    void displayResult() {
        displayStudent();
        cout << "Average: " << avg << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Result r;
    r.setData();
    r.calculate();
    r.displayResult();
    return 0;
}
//METHOD 2: PUBLIC DERIVATION:
// Single Inheritance
// METHOD 2 - Public Derivation
#include <iostream>
using namespace std;

// Base class
class Student {
private:
    string name;
    int roll;
    int m1, m2, m3;

public:
    void getData() {
        cout << "Enter Name and Roll: ";
        cin >> name >> roll;
        cout << "Enter 3 subject marks: ";
        cin >> m1 >> m2 >> m3;
    }
    
    void displayStudent() {
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
        cout << "Marks: " << m1 << ", " << m2 << ", " << m3 << endl;
    }
    
    // Total marks
    int totalMarks() {
        return m1 + m2 + m3;
    }
};

// Derived class
class Result : public Student {
private:
    float avg;
    string grade;

public:
    void calculate() {
        avg = totalMarks() / 3.0;
        if (avg >= 75)
            grade = "Distinction";
        else if (avg >= 60)
            grade = "First Class";
        else if (avg >= 50)
            grade = "Second Class";
        else if (avg >= 40)
            grade = "Pass";
        else
            grade = "Fail";
    }
    
    void displayResult() {
        cout << "Average: " << avg << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Result r;
    r.getData();
    r.calculate();
    r.displayStudent();
    r.displayResult();
    return 0;
}