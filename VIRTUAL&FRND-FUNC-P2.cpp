/*2. Student Scholarship Eligibility Using Friend Function
Problem Statement
Create a class Student with private data members name, marks, and attendance. Create another class ScholarshipPolicy with private data members minimum marks and minimum attendance. Define a friend function checkScholarship() that accesses the private data of both classes and checks whether the student is eligible for a scholarship.

Class Design
Class: Student

Data Members: string name, float marks, float attendance

Member Functions: getStudentData(), friend checkScholarship()

Class: ScholarshipPolicy

Data Members: float minMarks, float minAttendance

Member Functions / Friend Function: getPolicyData(), friend checkScholarship()
*/
#include <iostream>
#include <string>
using namespace std;

class ScholarshipPolicy; // Forward declaration

// Class: Student
class Student {
private:
    string name;
    float marks;
    float attendance;
public:
    void getStudentData() {
        cout << "Enter Student Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
        cout << "Enter Attendance (%): ";
        cin >> attendance;
    }
    // Friend function declaration
    friend void checkScholarship(Student, ScholarshipPolicy);
};

// Class: ScholarshipPolicy
class ScholarshipPolicy {
private:
    float minMarks;
    float minAttendance;
public:
    void getPolicyData() {
        cout << "Enter Minimum Marks Required: ";
        cin >> minMarks;
        cout << "Enter Minimum Attendance Required: ";
        cin >> minAttendance;
    }
    // Friend function declaration
    friend void checkScholarship(Student, ScholarshipPolicy);
};

// Friend Function Definition
void checkScholarship(Student s, ScholarshipPolicy p) {
    cout << "\nChecking Scholarship Eligibility...\n";
    if (s.marks >= p.minMarks && s.attendance >= p.minAttendance) {
        cout << s.name << " is ELIGIBLE for Scholarship.\n";
    } else {
        cout << s.name << " is NOT ELIGIBLE for Scholarship.\n";
    }
}

// Main Function
int main() {
    Student s;
    ScholarshipPolicy p;
    
    s.getStudentData();
    p.getPolicyData();
    
    checkScholarship(s, p);
    
    return 0;
}