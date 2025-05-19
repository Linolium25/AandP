#include <iostream>
using namespace std;

// ��� �������, ��� ������� ����� b � ������ a
typedef double* (*FilterFunc)(double*, int, int&);

// �������, ��� ������� ����� b � ���� �������� � �������� �������
double* createFilteredArray(double* a, int n, int& m) {
    m = 0;

    // ϳ�������� ������� ��������� ��������
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && static_cast<int>(a[i]) % 2 == 0) {
            m++;
        }
    }

    // �������� �������� ����� ��� ������ b
    double* b = new double[m];
    int j = 0;

    // ���������� b
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && static_cast<int>(a[i]) % 2 == 0) {
            b[j++] = a[i];
        }
    }

    return b;
}

int main() {
    int n;
    cout << "Rozmir masivy a: ";
    cin >> n;

    // �������� �������� ����� ��� ������ a
    double* a = new double[n];
    cout << "Elementu masivy a:\n";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    // �������� �� �������
    FilterFunc filter = createFilteredArray;

    int m; // ����� ������ ������
    double* b = filter(a, n, m); // ������ ������� ����� ��������

    // ��������� ����������
    cout << "\n Masiv b (parni elem. z neparnih indecsiv a): ";
    for (int j = 0; j < m; j++) {
        cout << b[j] << " ";
    }
    cout << endl;

    // ��������� �����
    delete[] a;
    delete[] b;

    return 0;
}

