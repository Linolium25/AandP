#include <iostream>
#include <string>
using namespace std;


class Dvyhun {
private:
    double potuzhnist;
    string zavodNom;

public:
    Dvyhun() : potuzhnist(0), zavodNom("0000") {
        cout << "Stvoreno ob'yekt klasu \"Dvyhun\" (za zamovchuvannyam)" << endl;
    }

    Dvyhun(double p, string z) : potuzhnist(p), zavodNom(z) {
        cout << "Stvoreno ob'yekt klasu \"Dvyhun\" (za parametramy)" << endl;
    }

    virtual ~Dvyhun() {
        cout << "Znyshcheno ob'yekt klasu \"Dvyhun\"" << endl;
    }

    virtual void vvesty() {
        cout << "Vvedit potuzhnist (kVt): ";
        cin >> potuzhnist;
        cin.ignore();

        cout << "Vvedit zavodskyy nomer: ";
        getline(cin, zavodNom);
    }

    virtual void vyvesty() const {
        cout << "Potuzhnist: " << potuzhnist << " kVt" << endl;
        cout << "Zavodskyy nomer: " << zavodNom << endl;
    }
};



class Avtomobil : public Dvyhun {
private:
    string marka;
    double tsina;

public:
    Avtomobil() : Dvyhun(), marka("N/A"), tsina(0) {
        cout << "Stvoreno ob'yekt klasu \"Avtomobil\" (za zamovchuvannyam)" << endl;
    }

    Avtomobil(string m, double t, double p, string z) : Dvyhun(p, z), marka(m), tsina(t) {
        cout << "Stvoreno ob'yekt klasu \"Avtomobil\" (z parametramy)" << endl;
    }

    
    ~Avtomobil() override {
        cout << "Znyshcheno ob'yekt klasu \"Avtomobil\"" << endl;
    }

    void vvesty() override {
        Dvyhun::vvesty();

        cout << "Vvedit marku avtomobilya: ";
        getline(cin, marka);

        cout << "Vvedit tsinu: ";
        cin >> tsina;
        cin.ignore();
    }

    void vyvesty() const override {
        Dvyhun::vyvesty();

        cout << "Marka: " << marka << endl;
        cout << "Tsina: " << tsina << " hrn" << endl;
    }
};


class Vantazhivka : public Avtomobil {
private:
    double vantazhopidyomnist;

public:
    Vantazhivka() : Avtomobil(), vantazhopidyomnist(0) {
        cout << "Stvoreno ob'yekt klasu \"Vantazhivka\" (za zamovchuvannyam)" << endl;
    }

    Vantazhivka(string m, double t, double p, string z, double v)
        : Avtomobil(m, t, p, z), vantazhopidyomnist(v) {
        cout << "Stvoreno ob'yekt klasu \"Vantazhivka\" (z parametramy)" << endl;
    }

    ~Vantazhivka() override {
        cout << "Znyshcheno ob'yekt klasu \"Vantazhivka\"" << endl;
    }

    void vvesty() override {
        Avtomobil::vvesty();

        cout << "Vvedit vantazhopidyomnist (kg): ";
        cin >> vantazhopidyomnist;
        cin.ignore();
    }

    void vyvesty() const override {
        Avtomobil::vyvesty();

        cout << "Vantazhopidyomnist: " << vantazhopidyomnist << " kg" << endl;
    }
};

int main() {
    const int N = 3;

    cout << "\n=== \"DVYHUNY\" ===" << endl;
    Dvyhun dvyhuny[N];
    for (int i = 0; i < N; ++i) {
        cout << "\n\"Dvyhun\" #" << i + 1 << ":" << endl;
        dvyhuny[i].vvesty();
    }

    for (int i = 0; i < N; ++i) {
        cout << "\nInformatsiya pro \"Dvyhun\" #" << i + 1 << ":" << endl;
        dvyhuny[i].vyvesty();
    }

    cout << "\n=== \"AVTOMOBILI\" ===" << endl;
    Avtomobil avt[N];
    for (int i = 0; i < N; ++i) {
        cout << "\n\"Avtomobil\" #" << i + 1 << ":" << endl;
        avt[i].vvesty();
    }

    for (int i = 0; i < N; ++i) {
        cout << "\nInformatsiya pro \"Avtomobil\" #" << i + 1 << ":" << endl;
        avt[i].vyvesty();
    }

    cout << "\n=== \"VANTAZHIVKY\" ===" << endl;
    Vantazhivka vant[N];
    for (int i = 0; i < N; ++i) {
        cout << "\n\"Vantazhivka\" #" << i + 1 << ":" << endl;
        vant[i].vvesty();
    }

    for (int i = 0; i < N; ++i) {
        cout << "\nInformatsiya pro \"Vantazhivka\" #" << i + 1 << ":" << endl;
        vant[i].vyvesty();
    }

    return 0;
}


