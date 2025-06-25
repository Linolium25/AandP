#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Vvedit rozmir masyvu: ";
    cin >> n;

    if (n < 3) {
        cout << "Nedostatno elementiv dlya poshukiv tryokh pidriad." << endl;
        return 0;
    }

    double* a = new double[n];
    cout << "Vvedit elementy: ";
    for (int i = 0; i < n; i++) {
        cin >> *(a + i);
    }

    bool znaydeno = false;
    cout << "Neperevni dilyanky z 3 spadaiuchykh elementiv: \n";
    for (int i = 0; i < n - 2; i++) {
        double x = *(a + i);
        double y = *(a + i + 1);
        double z = *(a + i + 2);
        if (x > y && y > z) {
            cout << x << " " << y << " " << z << endl;
            znaydeno = true;
        }
    }

    if (!znaydeno) {
        cout << "dil. ne znaydeno." << endl;
    }

    delete[] a;
    return 0;
}

