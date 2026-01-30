#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) { 
        if (arr[i] == key) {    
            return i;            
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 0, 1, 9};
    int key = 1;
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = linearSearch(arr, n, key);

    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index: " << result << endl;
    }

    return 0;
}
