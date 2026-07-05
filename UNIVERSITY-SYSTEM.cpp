/*
Question: Design a university system where: Person is a base class. Student and Employee inherit from Person. Teaching Assistant inherits from both Student and Employee.  
Code / Class Design Snippets: (Note: A full executable program is not provided in the source text, but the required class framework and function snippets to solve the diamond problem are outlined below). 
*/
// Solution to Ambiguity: Virtual Base Class
class Student : virtual public Person 
class Employee : virtual public Person

// Inside TeachingAssistant:
void getTAData() { 
    getPersonData();   // From Person (shared virtual base)
    getStudentData();  // From Student
    getEmployeeData(); // From Employee 
}

void displayTAData() {
    cout << "\n--- Teaching Assistant Details ---\n";
    displayPersonData();
    displayStudentData();
    displayEmployeeData(); 
}