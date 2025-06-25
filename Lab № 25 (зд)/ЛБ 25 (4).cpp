#include <iostream>
using namespace std;

int main() {
  
    int n;
    cout << "Vvedit rozmir masyvu: ";
    cin >> n;

    // Створення динамічного масиву
    int* a = new int[n];
    cout << "Vvedit elementy masyvu: ";
    for (int i = 0; i < n; i++) {
        cin >> *(a + i); // Введення з використанням вказівників
    }

    int count = 0; // Лічильник від’ємних елементів

    cout << "Vidyemni elementy ta yikhni adresy:\n";
    for (int i = 0; i < n; i++) {
        int* ptr = a + i; // Вказівник на поточний елемент
        if (*ptr < 0) {
            cout << "Znachenia: " << *ptr << ", Adresa: " << ptr << endl;
            count++;
        }
    }

    // Вивід загальної кількості
    cout << "\nZagalna kilkist vid. elementiv: " << count << endl;

    // Звільнення пам’яті
    delete[] a;
    return 0;
}

