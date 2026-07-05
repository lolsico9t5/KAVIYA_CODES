/*Program 3: Store Eligible Students for Placement Based on CGPA
Question: Create a class Student with attributes such as name, register number, and CGPA. Store student objects in a file. Read a cutoff CGPA from the user and separate all students whose CGPA is greater than or equal to the given cutoff into a separate file called eligible.dat. Retrieve and display the eligible students from that file.
*/
//Reading and Writing Objects
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
private:
    char name [50]; // fixed for binary safety
    int regNo;
    float cgpa;
public:
    void getData()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Register Number: ";
        cin >> regNo;
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }
    void displayData()
    {
        cout << "Name: "<< name
             << ", RegNo: " << regNo
             << ", CGPA: " << cgpa << endl;
    }
    float getCGPA()
    {
        return cgpa;
    }
};

int main()
{
    Student s;
    ofstream fout;
    ifstream fin;
    int n;
    float cutoff;

    // Step 1: Store student data
    fout.open("students.dat", ios::binary);
    cout << "Enter number of students: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details of student " << i+1 << endl;
        s.getData();
        fout.write(reinterpret_cast<char*>(&s), sizeof(s));
    }
    fout.close();

    // Step 2: Get cutoff
    cout << "\nEnter cutoff CGPA: ";
    cin >> cutoff;

    // Step 3: Filter eligible students
    fin.open("students.dat", ios::binary);
    ofstream fout2("eligible.dat", ios::binary);
    while(fin.read(reinterpret_cast<char*>(&s), sizeof(s)))
    {
        if(s.getCGPA() >= cutoff)
        {
            fout2.write(reinterpret_cast<char*>(&s), sizeof(s));
        }
    }
    fin.close();
    fout2.close();

    // Step 4: Display eligible students
    cout << "\nEligible Students:\n";
    ifstream fin2("eligible.dat", ios::binary);
    while(fin2.read(reinterpret_cast<char*>(&s), sizeof(s)))
    {
        s.displayData();
    }
    fin2.close();

    return 0;
}