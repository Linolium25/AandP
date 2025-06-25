#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "\nVvedit kilkist ryadkiv (n): ";
    cin >> n;
    cout << "Vvedit' kilkist stovptsiv (m): ";
    cin >> m;

    // дл
    int** A = new int*[n];
    for (int i = 0; i < n; ++i)
        A[i] = new int[m];

    cout << "\nVvedit elementy matrytsi " << n << "x" << m << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> *(*(A + i) + j); 
        }
    }

    int positiveSum = 0;
    int positiveCount = 0;
    int negativeSum = 0;
    int negativeCount = 0;
    int zeroCount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int value = *(*(A + i) + j);
            if (value > 0) {
                positiveSum += value;
                positiveCount++;
            } else if (value < 0) {
                negativeSum += value;
                negativeCount++;
            } else {
                zeroCount++;
            }
        }
    }

    cout << "\nRezultaty:\n";
    if (positiveCount > 0)
        cout << "Serednie dodatnikh: " << (positiveSum * 1.0 / positiveCount) << endl;
    else
        cout << "Nemaye dodatnikh chysel\n";

    if (negativeCount > 0)
        cout << "Serednie vid'yemnykh: " << (negativeSum * 1.0 / negativeCount) << endl;
    else
        cout << "Nemaye vid'yemnykh chysel\n";

    cout << "Kilkist nuliv: " << zeroCount << endl;

 
    for (int i = 0; i < n; ++i)
        delete[] A[i];
    delete[] A;

    return 0;
}


