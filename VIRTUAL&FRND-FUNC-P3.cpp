/*3. Bank and Auditor System Using Friend Class
Problem Statement
Create a class BankAccount that stores account balance as a private data member. Create another class Auditor that needs access to the private balance for auditing purposes. Declare Auditor as a friend class of BankAccount and display the account balance through the auditor object.

Class Design
Class: BankAccount

Data Members: int balance

Member Functions: Constructor to initialize balance, friend class Auditor

Class: Auditor

Member Functions: checkBalance(BankAccount acc)*/
#include <iostream>
using namespace std;

// Forward declaration
class Auditor;

// Class: BankAccount
class BankAccount {
private:
    int balance;
public:
    // Constructor
    BankAccount(int b) {
        balance = b;
    }
    
    // Declare Auditor as friend class
    friend class Auditor;
};

// Class: Auditor
class Auditor {
public:
    void checkBalance(BankAccount acc) {
        cout << "Auditor checking balance...\n";
        cout << "Account Balance: " << acc.balance << endl;
    }
};

// Main Function
int main() {
    BankAccount account(50000); // initialize balance
    Auditor auditor;
    
    auditor.checkBalance(account);
    
    return 0;
}