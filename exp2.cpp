#include <iostream>
using namespace std;

void inputMatrix(int mat[3][3], string name) {
    cout << "Enter elements for Matrix " << name << ":\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat[i][j];
        }
    }
}

void displayMatrix(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int a[3][3], b[3][3], choice;
    char cont;

    do {
        cout << "\n--- Matrix Operations Menu ---";
        cout << "\n1. Input Matrices\n2. Display Matrices\n3. Addition\n4. Subtraction\n5. Transpose\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputMatrix(a, "A");
                inputMatrix(b, "B");
                break;

            case 2:
                cout << "\nMatrix A:\n"; displayMatrix(a);
                cout << "\nMatrix B:\n"; displayMatrix(b);
                break;

            case 3:
                cout << "\nAddition Result:\n";
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) 
                        cout << a[i][j] + b[i][j] << "\t";
                    cout << endl;
                }
                break;

            case 4:
                cout << "\nSubtraction Result:\n";
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) 
                        cout << a[i][j] - b[i][j] << "\t";
                    cout << endl;
                }
                break;

            case 5:
                cout << "\nTranspose of A:\n";
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) 
                        cout << a[j][i] << "\t";
                    cout << endl;
                }
                break;

            default:
                cout << "Invalid Selection!";
        }

        cout << "\nPress 'y' to continue: ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    return 0;
}
