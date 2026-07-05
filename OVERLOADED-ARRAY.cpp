/*1. A class MarksArray is used to store marks of students in a subject. The system should:

Accept marks for a fixed number of students.

Increase all marks by 1 (grace marks) using prefix ++ operator.

Add marks of two sections using overloaded + operator (friend function).

Display marks.
*/
#include <iostream>
using namespace std;

class MarksArray {
    int arr[5]; // fixed size array
    
public:
    // Function to get input
    void create() {
        cout << "Enter 5 marks:\n";
        for(int i = 0; i < 5; i++) {
            cin >> arr[i];
        }
    }
    
    // Function to display array
    void display() {
        cout << "Marks: ";
        for(int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    // Prefix ++ operator overloading
    void operator++() {
        for(int i = 0; i < 5; i++) {
            ++arr[i]; // increment each element
        }
    }
    
    // Friend function for + operator
    friend MarksArray operator+(MarksArray m1, MarksArray m2);
};

// Definition of friend function
MarksArray operator+(MarksArray m1, MarksArray m2) {
    MarksArray temp;
    for(int i = 0; i < 5; i++) {
        temp.arr[i] = m1.arr[i] + m2.arr[i];
    }
    return temp;
}

// Main function
int main() {
    MarksArray ob1, ob2, ob3;
    
    cout << "Enter marks for Section A:\n";
    ob1.create();
    
    cout << "Enter marks for Section B:\n";
    ob2.create();
    
    cout << "\nOriginal Marks:\n";
    ob1.display();
    ob2.display();
    
    // Using prefix ++
    ++ob1;
    cout << "\nAfter giving grace marks to Section A:\n";
    ob1.display();
    
    // Using + operator
    ob3 = ob1 + ob2;
    cout << "\nCombined Marks (A+B):\n";
    ob3.display();
    
    return 0;
}