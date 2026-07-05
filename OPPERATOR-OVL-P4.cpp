//Implement a Date class with day, month, and year. Overload operators to:  + add days  - subtract days  == compare two dates  ++ increment date by one day  (Assume February always has 28 days.)  Class Design  Class: Date  Data Members:  int day  int month  int year  Member Functions:  getDate()  display()  operator + (int days)  operator - (int days)  operator == (Date d)  operator ++ () 
#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

    int getDaysInMonth(int m) {
        if (m == 2)
            return 28;
        else if (m == 4 || m == 6 || m == 9 || m == 11)
            return 30;
        else
            return 31;
    }

public:
    // Constructor
    Date(int d = 1, int m = 1, int y = 2000) {
        day = d;
        month = m;
        year = y;
    }

    void getDate() {
        cout << "Enter day month year: ";
        cin >> day >> month >> year;
    }

    void display() {
        cout << day << "/" << month << "/" << year << endl;
    }

    // Operator +
    Date operator+(int days) {
        Date temp;
        temp.day = day;
        temp.month = month;
        temp.year = year;
        temp.day += days;
        
        while (temp.day > getDaysInMonth(temp.month)) {
            temp.day -= getDaysInMonth(temp.month);
            temp.month++;
            if (temp.month > 12) {
                temp.month = 1;
                temp.year++;
            }
        }
        return temp;
    }

    // Operator -
    Date operator-(int days) {
        Date temp;
        temp.day = day;
        temp.month = month;
        temp.year = year;
        temp.day -= days;
        
        while (temp.day <= 0) {
            temp.month--;
            if (temp.month <= 0) {
                temp.month = 12;
                temp.year--;
            }
            temp.day += getDaysInMonth(temp.month);
        }
        return temp;
    }

    // Operator ==
    bool operator==(Date d) {
        return (day == d.day && month == d.month && year == d.year);
    }

    // Operator ++ (prefix)
    Date operator++() {
        day++;
        if (day > getDaysInMonth(month)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        
        // manually create object to return
        Date temp;
        temp.day = day;
        temp.month = month;
        temp.year = year;
        return temp;
    }
};

int main() {
    Date d1, d2;
    d1.getDate();
    cout << "Original Date: ";
    d1.display();
    
    // Add days
    Date d3 = d1 + 5;
    cout << "After adding 5 days: ";
    d3.display();
    
    // Subtract days
    Date d4 = d1 - 3;
    cout << "After subtracting 3 days: ";
    d4.display();
    
    // Increment
    ++d1;
    cout << "After increment (++): ";
    d1.display();
    
    // Compare
    d2.getDate();
    if (d1 == d2)
        cout << "Dates are equal" << endl;
    else
        cout << "Dates are not equal" << endl;
        
    return 0;
}