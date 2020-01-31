#include "ConsoleReader.h"
#include <iostream>
void getValueFloat(float& in)
{
	bool check1 = false;
	while (check1 != true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		std::cin >> in;

		if (std::cin.fail()) // ���� ���������� ���������� ��������� ����������
		{
			std::cout << "Mistake, enter again (float) : ";
			std::cin.clear(); // ���������� cin � '�������' ����� ������
			std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			check1 = false;
		}
		else
		{
			check1 = true;
		}

	}
}

bool getValueInt(int& in)
{
	bool checkValue = true;
	std::cin >> in;
	if (std::cin.fail()) // ���� ���������� ���������� ��������� ����������
	{
		std::cin.clear(); // ���������� cin � '�������' ����� ������
		std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
		checkValue = false;
	}

	return checkValue;
}

void console()
{
	std::cout << "1. Add\n"
		<< "2. Delete\n"
		<< "3. Insert\n"
		<< "4. Find\n"
		<< "5. Print\n"
		<< "6. Exit" << std::endl;

}

bool equals(Student* a, Student* b)
{
	if (a->name == b->name && a->group == b->group
		&& a->averageScore == b->averageScore)
		return true;
	else
		return false;
}