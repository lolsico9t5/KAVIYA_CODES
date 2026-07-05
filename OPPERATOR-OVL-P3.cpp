//Design a class BankAccount with attributes account number, account holder name, and balance. Overload:  += for deposit  -= for withdrawal  Ensure withdrawal is allowed only if sufficient balance exists. Implement viewSummary() to display account details.  Class Design  Class: BankAccount  Data Members:  int accNo  string name  float balance  Member Functions:  getData()  operator += (float amount)  operator -= (float amount)  viewSummary() 
#include <iostream>
using namespace std;

class BankAccount {
private:
    int accNo;
    string name;
    float balance;
public:
    // Function to get data
    void getData() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Account Holder Name: ";
        cin >> name;
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    // Operator += (Deposit)
    void operator += (float amount) {
        balance += amount;
        cout << "Amount Deposited: " << amount << endl;
    }

    // Operator -= (Withdrawal)
    void operator -= (float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient Balance! Withdrawal failed." << endl;
        }
    }

    // Display account details
    void viewSummary() {
        cout << "\n--- Account Summary ---\n";
        cout << "Account No: " << accNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount ob;
    ob.getData();
    
    // Deposit
    ob += 1000;
    
    // Withdrawal
    ob -= 500;
    ob -= 10000; // test insufficient balance
    
    // Display details
    ob.viewSummary();
    
    return 0;
}