#include <iostream>
#include "Math.h"

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

using namespace std;

int main()
{
	float x, eps, result;

	cout << "sin (x, esp)" << endl;
	cout << "x = ";
	getValueFloat(x);
	cout << "eps = "; 
	getValueFloat(eps);
		result = Math::sin(x, eps);
		cout << "sin (" << x << ", " << eps << ") = " << result << endl;

	cout << "sqrt (x, esp)" << endl;
	cout << "x = ";
	getValueFloat(x);
	cout << "eps = "; 
	getValueFloat(eps);
		result = Math::sqrt(x, eps);
		cout << "sqrt (" << x << ", " << eps << ") = " << result << endl;
	return 0;
}

