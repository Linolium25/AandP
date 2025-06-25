#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Vvedit rozmir masyvu: ";
    cin >> n;

    double* a = new double[n];
    cout << "Vvedit elementy: ";
    for (int i = 0; i < n; i++) {
        cin >> *(a + i);
    }

 
    if (n < 2) {
        cout << "Nedostatno elementiv dlya perevirky." << endl;
        delete[] a;
        return 0;
    }

    double minEven = *(a + 1); 
    for (int i = 1; i < n; i += 2) {
        if (*(a + i) < minEven) {
            minEven = *(a + i);
        }
    }

    cout << "Min znachennia na parnykh poz.: " << minEven << endl;
    delete[] a;
    return 0;
}

