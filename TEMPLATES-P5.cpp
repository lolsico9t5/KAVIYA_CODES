//Write a program to perform insert, delete, and empty operations on an array using a generic class template.  The program should support storing, integer, character and float values  Provide a menu-driven interface.  Class Design  Template Class: Array<T>  Data Members:  • arr[]  •  size  •  capacity  Member Functions: ▪ insertAtBeginning()  ▪ insertAtEnd()  ▪ deleteFromBeginning()  ▪ deleteFromEnd()  ▪ emptyArray()  ▪ display()  
#include <iostream>
using namespace std;

template <class T>
class Array {
private:
    T arr[100];
    int size;
    int capacity;
    
public:
    Array(int cap = 100) {
        size = 0;
        capacity = cap;
    }

    // Insert at beginning
    void insertAtBeginning(T value) {
        if (size == capacity) {
            cout << "Array is full!\n";
            return;
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
    }

    // Insert at end
    void insertAtEnd(T value) {
        if (size == capacity) {
            cout << "Array is full!\n";
            return;
        }
        arr[size++] = value;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Delete from end
    void deleteFromEnd() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        size--;
    }

    // Empty the array
    void emptyArray() {
        size = 0;
        cout << "Array emptied successfully!\n";
    }

    // Display
    void display() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Menu function for any type
template <class T>
void menu() {
    Array<T> a;
    int choice;
    T value;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Empty Array\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                a.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                a.insertAtEnd(value);
                break;
            case 3:
                a.deleteFromBeginning();
                break;
            case 4:
                a.deleteFromEnd();
                break;
            case 5:
                a.emptyArray();
                break;
            case 6:
                a.display();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);
}

int main() {
    int typeChoice;
    cout << "Select Data Type:\n";
    cout << "1. Integer\n2. Float\n3. Character\n";
    cout << "Enter choice: ";
    cin >> typeChoice;
    
    switch (typeChoice) {
        case 1:
            menu<int>();
            break;
        case 2:
            menu<float>();
            break;
        case 3:
            menu<char>();
            break;
        default:
            cout << "Invalid type choice!\n";
    }
    
    return 0;
}