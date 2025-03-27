#include <iostream>
#include <vector>
using namespace std;

class People {
public:
    string surname, country, gender, education;
    int birthYear, age;

    People() {
        surname = "�������";
        country = "������";
        gender = "�������";
        education = "�������";
        birthYear = 2006;
        age = 2024 - birthYear;
    }

    People(string s, string g, string e, int by) {
        surname = s;
        country = "������";
        gender = g;
        education = e;
        birthYear = by;
        age = 2024 - birthYear;
    }

    People(const People &p) {
        surname = p.surname;
        country = p.country;
        gender = p.gender;
        education = p.education;
        birthYear = p.birthYear;
        age = p.age;
    }

    void input() {
        cout << "�������: ";
        cin >> surname;
        cout << "����� (�/�): ";
        cin >> gender;
        cout << "�����: ";
        cin >> education;
        cout << "г� ����������: ";
        cin >> birthYear;
        age = 2024 - birthYear;
    }

    void display() {
        cout << surname << ", " << gender << ", �����: " << education 
             << ", ³�: " << age << " ����" << endl;
    }
};

int main() {
    vector<People> peopleList = {
        People("��������", "�", "����", 1995),
        People("��������", "�", "�������", 2001),
        People("��������", "�", "����", 1987)
    };

    // ������ ������ �����������
    People newPerson;
    cout << "\n������ ��� ��� ���� ������:\n";
    newPerson.input();
    peopleList.push_back(newPerson);

    // ��������� ������
    cout << "\n������ ��� �����:\n";
    for (People &p : peopleList) p.display();

    // Գ�������� �� ������ � ����
    int minAge;
    cout << "\n������ ��������� �� ��� ������ ��� � ����� ������: ";
    cin >> minAge;
    cout << "\n����� � ����� ������ � ���� > " << minAge << ":\n";
    for (People &p : peopleList) {
        if (p.education == "����" && p.age > minAge) p.display();
    }

    // ��������� �� ������
    string genderToRemove;
    cout << "\n������ ����� ��� ��������� (�/�): ";
    cin >> genderToRemove;
    for (int i = 0; i < peopleList.size(); i++) {
        if (peopleList[i].gender == genderToRemove) {
            peopleList.erase(peopleList.begin() + i);
            i--;  
        }
    }

    // ��������� ������ ���� ���������
    cout << "\n������ ���� ��������� ��� ���� " << genderToRemove << ":\n";
    for (People &p : peopleList) p.display();

    // ������� ������� � ������ � �������
    if (!peopleList.empty()) {
        People copyPerson = peopleList[0];
        peopleList.insert(peopleList.begin(), copyPerson);
    }

    // ��������� ���� ���������
    cout << "\n������ ���� ��������� ����� ������:\n";
    for (People &p : peopleList) p.display();

    return 0;
}

