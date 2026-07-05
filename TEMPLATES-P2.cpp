//Write a program to sort an array using Bubble Sort implemented as a generic function. The function should work for both integer and floating-point arrays. 
#include <iostream>
using namespace std;

// Generic Bubble Sort Function
template <class T>
void bubbleSort(T arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Generic Display Function
template <typename T>
void display(T arr[], int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, i, intarr[25];
    
    cout << "Enter number of integer elements: ";
    cin >> n;
    cout << "Enter integers: ";
    for(i = 0; i < n; i++)
        cin >> intarr[i];
        
    bubbleSort(intarr, n);
    cout << "Sorted integers: ";
    display(intarr, n);
    
    cout << "\nEnter number of float elements: ";
    cin >> n;
    float floatarr[25];
    
    cout << "Enter floating-point numbers: ";
    for(i = 0; i < n; i++)
        cin >> floatarr[i];
        
    bubbleSort(floatarr, n);
    cout << "Sorted floating numbers: ";
    display(floatarr, n);
    
    return 0;
}