//Write a C++ program to implement a generic swap function using call by reference that can swap values of any data type. 
#include <iostream>
using namespace std;

// Function Template for Swapping
template <class T>
void swapValues(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 10, y = 20;
    float p = 5.5, q = 9.8;
    char c1 = 'A', c2 = 'B';
    
    cout << "Before Swapping (int): " << x << " " << y << endl;
    swapValues(x, y);
    cout << "After Swapping (int): " << x << " " << y << endl;
    
    cout << "\nBefore Swapping (float): " << p << " " << q << endl;
    swapValues(p, q);
    cout << "After Swapping (float): " << p << " " << q << endl;
    
    cout << "\nBefore Swapping (char): " << c1 << " " << c2 << endl;
    swapValues(c1, c2);
    cout << "After Swapping (char): " << c1 << " " << c2 << endl;
    
    return 0;
}