#include <iostream>
#include <cstdlib>   
#include <ctime>     

using namespace std;

bool hasSameDigits(int number) {
    int tens = number / 10;
    int units = number % 10;
    return tens == units;
}

int main() {
    int n;

    cout << "Vvedit rozmirnist matrytsi n: ";
    cin >> n;

    int** A = new int*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[n];
    }

    srand(time(0));

    cout << "Matrytsia A:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 90 + 10;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // ѕошук суми елемент≥в у тих стовпц€х, €к≥ не м≥ст€ть чисел з однаковими цифрами
    int countValidColumns = 0; 
    for (int j = 0; j < n; ++j) {
        bool hasSame = false;

        // перев≥рка в стовпц≥ числа з однаковими цифрами
        for (int i = 0; i < n; ++i) {
            if (hasSameDigits(A[i][j])) {
                hasSame = true;
                break;
            }
        }

        // якщо таких чисел немаЇ Ч обчислюЇмо суму
        if (!hasSame) {
            int columnSum = 0;
            for (int i = 0; i < n; ++i) {
                columnSum += A[i][j];
            }
            cout << "Suma elementiv u stovptsi " << j << ": " << columnSum << endl;
            countValidColumns++;
        }
    }

    // якщо не знайдено н≥одного стовпц€....
    if (countValidColumns == 0) {
        cout << "Nemaje stovptsiv bez chysel z odnakovymy tsyframy." << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}

