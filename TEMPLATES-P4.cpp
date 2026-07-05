//Write a program to implement a Matrix class template that supports, input of matrix elements, addition of two matrices and display of result matrix.  If matrix dimensions do not match, display an error message.  Class Design  Template Class: Matrix<T>  Data Members:  mat[10][10]  ▪ rows, cols  Member Functions: getMatrix()  ▪ add(Matrix obj2)  ▪ display()  
#include <iostream>
using namespace std;

template <class T>
class Matrix {
private:
    T mat[10][10];
    int rows, cols;
    
public:
    // Input matrix
    void getMatrix() {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> cols;
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    // Add two matrices
    Matrix add(Matrix obj2) {
        Matrix result;
        if (rows != obj2.rows || cols != obj2.cols) {
            cout << "Error: Matrix dimensions do not match!\n";
            result.rows = 0;
            result.cols = 0;
            return result;
        }
        
        result.rows = rows;
        result.cols = cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + obj2.mat[i][j];
            }
        }
        return result;
    }

    // Display matrix
    void display() {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix<int> m1, m2, m3;
    
    cout << "Enter Matrix 1:\n";
    m1.getMatrix();
    
    cout << "Enter Matrix 2:\n";
    m2.getMatrix();
    
    // Add matrices
    m3 = m1.add(m2);
    
    // Check if the result has valid dimensions before displaying
    if (m3.add(m1).add(m2).add(m3) /* Dummy condition check */) {
        // Result dimensions check isn't strictly necessary here 
        // since our add() handles error output, but we can display the result safely.
    }
    
    cout << "\nResult Matrix:\n";
    m3.display();
    
    return 0;
}