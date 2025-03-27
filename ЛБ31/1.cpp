#include <iostream>
using namespace std;

class Flat {
public:
    string address;
    int floor;
    int rooms;
    double area;

    Flat() {
        address = "�������";
        floor = 1;
        rooms = 2;
        area = 55;
    }

    Flat(string addr, int fl) {
        address = addr;
        floor = fl;
        rooms = 2;  
        area = 55; 
    }

    void input() {
        cout << "������ ������: ";
        cin.ignore();
        getline(cin, address);
        cout << "������ ������: ";
        cin >> floor;
        cout << "������ ������� �����: ";
        cin >> rooms;
        cout << "������ ����� (�?): ";
        cin >> area;
    }

    void display() {
        cout << "������: " << address << ", ������: " << floor 
             << ", ʳ����: " << rooms << ", �����: " << area << " �?" << endl;
    }
};

int main() {
    const int SIZE = 3;
    Flat flats[SIZE] = {
        Flat("���. ��������, 10", 3),
        Flat("��. ��������, 25", 5),
        Flat()  
    };

    cout << "\n������ ��� ��� ������ ��������:\n";
    flats[2].input();

    cout << "\n������ ��� �������:\n";
    for (int i = 0; i < SIZE; i++) {
        flats[i].display();
    }

    int searchRooms;
    cout << "\n������ ������� ����� ��� ������: ";
    cin >> searchRooms;
    cout << "�������� � " << searchRooms << " ��������:\n";
    for (int i = 0; i < SIZE; i++) {
        if (flats[i].rooms == searchRooms) {
            flats[i].display();
        }
    }

    double maxArea = 40;
    int minFloor, maxFloor;
    cout << "\n������ ��������� ������: ";
    cin >> minFloor;
    cout << "������ ������������ ������: ";
    cin >> maxFloor;

    cout << "\n�������� � ������ < 40 �? �� �� " << minFloor << " � " << maxFloor << " ���������:\n";
    for (int i = 0; i < SIZE; i++) {
        if (flats[i].area < maxArea && flats[i].floor >= minFloor && flats[i].floor <= maxFloor) {
            flats[i].display();
        }
    }

    return 0;
}

