#include <iostream>
using namespace std;

//  obmin zn.
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;

    cout << "Vvedit kilkist elementiv: ";
    cin >> n;

    int* a = new int[n]; 

  
    cout << "Vvedit " << n << "  chysela:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> *(a + i); // Vvedennya cherez vkazivnyk
    }

 // парн
    for (int i = 0; i < n; i += 2) {
        for (int j = i + 2; j < n; j += 2) {
            if (*(a + j) < *(a + i)) {
                swap(a + i, a + j); 
            }
        }
    }
 // не пар
    for (int i = 1; i < n; i += 2) {
        for (int j = i + 2; j < n; j += 2) {
            if (*(a + j) > *(a + i)) {
                swap(a + i, a + j); // Obmin znachen
            }
        }
    }


    cout << "Masiv pislya sortuvannya:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *(a + i) << " ";
    }
    cout << endl;

    delete[] a;

    return 0;
}
