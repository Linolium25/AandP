#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int findMin(int* arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int findMax(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {
    srand(time(0)); 

    int n;
    cout << "Vvedit kilkist elementiv: ";
    cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 6 - 2;  //  -2 до 3
    }

    int* b = new int[n * 2]; 
    int m = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            if (m > 0) {
                int minVal = findMin(b, m);
                int maxVal = findMax(b, m);
                b[m++] = minVal + maxVal;
            } else {
                b[m++] = 0; 
            }
        }
        b[m++] = a[i];
    }

    cout << "\nOryginal'nyy masyv:\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }

    cout << "\n\nOnovlenyy masyv:\n";
    for (int i = 0; i < m; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    delete[] a;
    delete[] b;

    system("pause"); 
    return 0;
}
