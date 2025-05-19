#include <iostream>
#include <string>
#include <ctime> // ��� ���������� ��������� ����
using namespace std;

class Shkolyar {
protected:
    string pip;
    int rik_narodzhennya;
    char stat;

public:
    // ����������� �� �������������
    Shkolyar() {
        pip = "N/A";
        rik_narodzhennya = 2000;
        stat = 'M';
        cout << "Stvoreno ob'yekt klasu 'Shkolyar' (za zamovchuvannyam)\n";
    }

    // ����� ��� ���������� ���
    int obchyslyty_vik() const {
        time_t t = time(NULL); 
        tm* now = localtime(&t);
        return now->tm_year + 1900 - rik_narodzhennya;
    }

    // ����� �������� �����
    void vvesty() {
        cout << "Vvedit PIP: ";
        getline(cin, pip);

        cout << "Vvedit rik narodzhennya: ";
        cin >> rik_narodzhennya;

        cout << "Vvedit stat (M/F): ";
        cin >> stat;
        cin.ignore(); // ��� �������� �� ���������� getline
    }

    // ����� ���������
    void vyvesty() const {
        cout << "\n=== Informatsiya pro shkolyara ===" << endl;
        cout << "PIP: " << pip << endl;
        cout << "Rik narodzhennya: " << rik_narodzhennya << endl;
        cout << "Stat: " << stat << endl;
        cout << "Vik: " << obchyslyty_vik() << " rokiv" << endl;
    }
};

class Pratsivnyk : public Shkolyar {
private:
    double zarplata;
    string mistse_roboty;

public:
    // ���������������� �����������
    Pratsivnyk(string p, int rik, char s, double z, string mr) {
        pip = p;
        rik_narodzhennya = rik;
        stat = s;
        zarplata = z;
        mistse_roboty = mr;
        cout << "Stvoreno ob'yekt klasu 'Pratsivnyk' (z parametramy)\n";
    }

    // ����������� �� �������������
    Pratsivnyk() {
        pip = "N/A";
        rik_narodzhennya = 1990;
        stat = 'M';
        zarplata = 0;
        mistse_roboty = "N/A";
        cout << "Stvoreno ob'yekt klasu 'Pratsivnyk' (za zamovchuvannyam)\n";
    }

    // ����� ��������
    void vvesty() {
        cout << "\n=== Vvedennya danykh dlya pratsivnyka ===" << endl;
        cout << "Vvedit PIP: ";
        getline(cin, pip);

        cout << "Vvedit rik narodzhennya: ";
        cin >> rik_narodzhennya;

        cout << "Vvedit stat (M/F): ";
        cin >> stat;

        cout << "Vvedit zarplatu: ";
        cin >> zarplata;
        cin.ignore();

        cout << "Vvedit mistse roboty: ";
        getline(cin, mistse_roboty);
    }

    // ����� ���������
    void vyvesty() const {
        cout << "\n=== Informatsiya pro pratsivnyka ===" << endl;
        cout << "PIP: " << pip << endl;
        cout << "Rik narodzhennya: " << rik_narodzhennya << endl;
        cout << "Stat: " << stat << endl;
        cout << "Vik: " << obchyslyty_vik() << " rokiv" << endl;
        cout << "Zarplata: " << zarplata << " hrn" << endl;
        cout << "Mistse roboty: " << mistse_roboty << endl;
    }
};

int main() {
    // ������������ �������� �����
    Shkolyar s;
    cout << "\n--- Vvedennya danykh dlya shkolyara ---" << endl;
    s.vvesty();
    s.vyvesty();

    // ������������ ����������������� ������������
    Pratsivnyk p("Ivanenko Petro", 1990, 'M', 18000, "IT-kompaniya");
    p.vyvesty();

    // ������������ ������� �������� �� ������ ����������
    Pratsivnyk p2;
    p2.vvesty();
    p2.vyvesty();

    return 0;
}


