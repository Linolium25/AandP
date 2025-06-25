#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Vvedit rozmir masyvu: ";
    cin >> n;

    // ÄÌ
    int* a = new int[n];
    cout << "Vvedit elementy masyvu: ";
    for (int i = 0; i < n; i++) {
        cin >> *(a + i); 
    }

    int count = 0;

    cout << "Elementy bilshi za svogo livogo susida:\n";

    // ç 2 åë
    for (int i = 1; i < n; i++) {
        int* current = a + i;         // ÏÅ
        int* left = a + i - 1;        // ËÑ

        if (*current > *left) {
            cout << "Index: " << i << ", Znachenia: " << *current << endl;
            count++; 
        }
    }

    cout << "\nZagalna kilkist takykh elementiv: " << count << endl;

    delete[] a;
    return 0;
}

