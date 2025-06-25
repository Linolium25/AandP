#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int n, p;  

    cout << "Vvedit kilkist ryadkiv (n): ";
    cin >> n;
    cout << "Vvedit kilkist stovptsiv (p): ";
    cin >> p;

    int A[n][p]; 

    srand(time(0));  

    cout << "\nAvtomatychno zgenerovana matrytsia:" << endl;
    for (int i = 0; i < n; i++) {           
        for (int j = 0; j < p; j++) {       
            *(*(A + i) + j) = rand() % 100; 
            cout << *(*(A + i) + j) << "\t"; 
        }
        cout << endl; 
    }

    int minIndex[n]; 

   
    for (int i = 0; i < n; i++) {
        int min = *(*(A + i));
        int index = 0;         
        for (int j = 1; j < p; j++) {          
            if (*(*(A + i) + j) < min) {          
                min = *(*(A + i) + j);      
                index = j;                     
            }
        }
        minIndex[i] = index; 
    }

    cout << "\n\"Indeksy minimalnykh elementiv u kozhnomu ryadku\":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\"" << minIndex[i] << "\" "; 
    }

    return 0;
}

