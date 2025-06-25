#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "K-st elementiv: ";
    cin >> n;

    // вид. пам.
    double* a = new double[n];

  
    cout << "Vvesty " << n << " disni chisla:\n";
    for (int i = 0; i < n; ++i) {
        cin >> *(a + i); 
    }

   // макс. можл. роз.
    double* newA = new double[n * 2]; 

    int newSize = 0; 
    double sumBefore = 0.0; // нак. П.Е

    for (int i = 0; i < n; ++i) {
        *(newA + newSize) = *(a + i); // коп. у нов м.
        ++newSize;

        sumBefore += *(a + i); 

       
        if (static_cast<int>(*(a + i)) % 5 == 0) {
            *(newA + newSize) = sumBefore - *(a + i); 
            ++newSize;
        }
    }

    cout << "\nNov.masiv:\n";
    for (int i = 0; i < newSize; ++i) {
        cout << *(newA + i) << " ";
    }
    cout << endl;

    delete[] a;
    delete[] newA;

    return 0;
}
