/*
Program 2: Store and Sort a List of Strings from a File
Question:
 Create a program to store a list of strings in a file called names.txt.
Read the strings from the file, sort them in alphabetical order, and display the sorted list.  
*/
// Store and Sort a List of Strings from a File
#include <iostream>
#include <fstream>
using namespace std;

// Sorting function
void sortNames(string names[], int n)
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(names[j] > names[j+1]) {
                string temp = names[j];
                names[j] = names[j+1];
                names[j+1] = temp;
            }
        }
    }
}

int main()
{
    ofstream fout;
    ifstream fin;
    string names[100], name;
    int n, i;

    // Store names
    fout.open("names.txt");
    cout << "Enter number of names: ";
    cin >> n;
    cout << "Enter names:\n";
    for(i = 0; i < n; i++)
    {
        cin >> names[i];
        fout << names[i] << endl;
    }
    fout.close();

    // Read from file
    fin.open("names.txt");
    i = 0;
    while(fin >> name)
    {
        names[i] = name;
        i++;
    }
    fin.close();

    // Call sorting function
    sortNames(names, i);

    // Display
    cout << "\nSorted Names:\n";
    for(int j = 0; j < i; j++)
    {
        cout << names[j] << endl;
    }

    return 0;
}