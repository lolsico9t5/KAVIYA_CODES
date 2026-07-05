//Write a program to implement a generic function that finds the maximum of two values. The function should work for both integer ,floating-point and Character type data
#include <iostream>
using namespace std;

template <class T>
T findMax(T a, T b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    cout << "Max (int): " << findMax(10, 20) << endl;
    cout << "Max (float): " << findMax(10.5, 5.5) << endl;
    cout << "Max (char): " << findMax('A', 'Z') << endl;
    
    return 0;
}