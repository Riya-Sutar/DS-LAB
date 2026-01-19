#include <iostream>
using namespace std;

int main() {
    int a[5], ch, res;
    char x;

    do {
        cout << "\n1.Create 2.Display 3.Sum 4.Diff 5.Max 6.Min\nChoice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter 5 numbers: ";
            for(int i=0; i<5; i++) cin >> a[i];
        } 
        else if (ch == 2) {
            for(int i=0; i<5; i++) cout << a[i] << " ";
            cout << endl;
        } 
        else {
            res = a[0];
            for(int i=1; i<5; i++) {
                if(ch == 3) res += a[i];
                if(ch == 4) res -= a[i];
                if(ch == 5 && a[i] > res) res = a[i];
                if(ch == 6 && a[i] < res) res = a[i];
            }
            cout << "Result: " << res << endl;
        }

        cout << "Continue? (y/n): ";
        cin >> x;
    } while (x == 'y' || x == 'Y');

    return 0;
}
