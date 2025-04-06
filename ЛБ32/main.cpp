#include <iostream>
#include "Employee.h"

int main() {
    int n;
    std::cout << "Enter the number of employees: ";
    std::cin >> n;

    int currentYear = 2025;

    // ����� ��������������� ��������� ����� ��� Employee
    Employee* employees = new Employee[n];

    // ����������� ������ ���� ���������� ������
    employees[0] = Employee();
    employees[1] = Employee("Smith", "IT", 2015, 1500.0f);

    std::cout << "Data entry for employees:\n";
    // �������� � 2-�� �������, �� ����� ��� ��� �����������
    for (int i = 2; i < n; ++i) {
        employees[i].inputEmployee();
        employees[i].calculateBonus(currentYear);
    }

    std::cout << "\nList of employees (to be sorted):\n";
    for (int i = 0; i < n; ++i) {
        employees[i].printEmployee();
        std::cout << std::endl;
    }

    std::cout << "----------------------------------\n";
    bubbleSortEmployees(employees, n, currentYear);

    std::cout << "\nList of employees (after sorting):\n";
    for (int i = 0; i < n; ++i) {
        employees[i].printEmployee();
        std::cout << std::endl;
    }

    std::cout << "----------------------------------\n";
    float avg = averageExperience(employees, n, currentYear);
    std::cout << "Average work experience: " << avg << " years\n";

    delete[] employees; // �� ������� �������� ���'���
    return 0;
}
