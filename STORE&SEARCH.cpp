/*
Program 1: Store and Search a List of Integers in a File
Question: Create a program to store a list of integer elements in a file called integers.txt. Read an integer from the user and search whether it is present in the file. Display the result. 
*/
// Store and Search a List of Integers in a File
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout;
    ifstream fin;
    int n, num, searchnum;
    bool found = false;

    // Step 1: Store integers into file
    fout.open("integers.txt");
    cout << "Enter number of integers: ";
    cin >> n;
    
    cout << "Enter " << n << " integers:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        fout << num << " ";
    }
    fout.close();

    // Step 2: Read number to search
    cout << "\nEnter number to search: ";
    cin >> searchnum;

    // Step 3: Search in file
    fin.open("integers.txt");
    while(fin >> num)
    {
        if(num == searchnum) {
            found = true;
            break;
        }
    }
    fin.close();

    // Step 4: Display result
    if(found)
        cout << "Number found in file.\n";
    else
        cout << "Number NOT found in file.\n";
        
    return 0;
}