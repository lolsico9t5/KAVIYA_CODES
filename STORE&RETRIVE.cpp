/*Program 4: Store and Retrieve Employee Objects in Binary File
Question: Store and Retrieve Employee Objects in Binary File. (Note: A specific word problem wasn't provided in the source for this, only the title directive).  
*/
#include <iostream>
#include <fstream>
using namespace std;

class Employee {
private:
    int empId;
    char name[20];
    float salary;
public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Salary: ";
        cin >> salary;
    }
    void showData() {
        cout << "\nEmployee ID: " << empId;
        cout << "\nName: " << name;
        cout << "\nSalary: " << salary << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    Employee e[n]; // array of objects
    
    // Input data
    for(int i = 0; i < n; i++) {
        cout << "\nEnter details for Employee " << i + 1 << endl;
        e[i].getData();
    }
    
    // Write array to file
    ofstream outFile("employee.dat", ios::binary);
    for(int i = 0; i < n; i++) {
        outFile.write(reinterpret_cast<char*>(&e[i]), sizeof(e[i]));
    }
    outFile.close();
    cout << "\nData written to file.\n";
    
    // Read from file
    Employee e2;
    ifstream inFile("employee.dat", ios::binary);
    cout << "\nData read from file:\n";
    while(inFile.read(reinterpret_cast<char*>(&e2), sizeof(e2))) {
        e2.showData();
    }
    inFile.close();

    return 0;
}