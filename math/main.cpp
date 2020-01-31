#include <iostream>
#include "Math.h"

void getValueFloat(float& in)
{
	bool check1 = false;
	while (check1 != true) // Цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		std::cin >> in;

		if (std::cin.fail()) // если предыдущее извлечение оказалось провальным
		{
			std::cout << "Mistake, enter again (float) : ";
			std::cin.clear(); // возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
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

