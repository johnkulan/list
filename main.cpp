#include <iostream>
#include <string>
#include <string.h>
#include "ConsoleReader.h"
#include "Student.h"
#include "List.h"

using namespace std;

enum check
{
	ADD = 1, DELETE, INSERT, FIND, PRINT, EXIT
};

#pragma region METHODS_LIST
//template <typename T_>
//class LIST
//{
//public:
//	T_* arr;
//	int count;
//	LIST() : count(0), max(4) { arr = new T_[max]; }
//
//	T_& operator[](int i);
//	void add(T_& elem);
//	bool remove(int a);
//	void insert(T_& elem, int a);
//	int indexOf(T_* elem, bool (*equal)(T_*, T_*));
//
//private:
//	int max;
//	void ExpandList();
//};
//
//
//template <typename T_>
//void LIST<T_>::ExpandList()
//{
//	if (count >= max)
//	{
//		max *= 2; //увеличиваем размер максимального массива
//		T_* arr1 = new T_[max]; //создание нового массива и переписываем в новый
//		for (int j = 0; j < count; j++)
//		{
//
//			arr1[j] = arr[j];
//		}
//		delete[]arr; //удаляем старый
//		arr = arr1; // указатель на новый массив
//	}
//}
//
//template <typename T_>
//int LIST<T_>::indexOf(T_ * elem, bool (*equal)(T_*, T_*))
//{
//	int temp = -1;
//	for (int i = 0; i < count; i++)
//		if (equal(arr + i, elem))
//			temp = i;
//	return temp;
//}
//
//template <typename T_>
//void LIST<T_>::insert(T_ & elem, int a)
//{
//	ExpandList();
//	bool output = false;
//	do
//	{
//		if (count != 0) // если при вставке список не пуст
//		{
//			for (int j = count; j > a; j--)
//			{
//				arr[j] = arr[j - 1];
//			}
//			output = true;
//			arr[a] = elem;
//		}
//		else // а если пуст, то просто добавляем первый элемент
//		{
//			add(elem);
//		}
//	} while (output != true);
//}
//
//template <typename T_>
//bool LIST<T_>::remove(int a)
//{
//	bool output = true;
//
//	if (count != 0) // если список пуст?
//	{
//		if (a >= 0 && a <= count) //проверка правильности ввода номера
//		{
//			// если удаляется послений элемент
//			if (a == count) delete arr;
//
//			else // присваиваем номеру удаления, следующий по списку элемент
//			{
//				for (int j = a; j < count; j++)
//					arr[j] = arr[j + 1];
//			}
//			count--;
//		}
//		else output = false;
//	}
//	else output = false;
//	return output;
//
//
//}
//
//template <typename T_>
//void LIST<T_>::add(T_ & elem)
//{
//	ExpandList();
//	arr[count] = elem; //добавляем нового студента в конец списка
//	count++;
//}
//
//template <typename T_>
//T_& LIST<T_>:: operator[](int i)
//{
//	return T_(*arr + i);
//}
#pragma endregion

bool FUNC(List<Student>& L, int in)
{
	bool output = false;
	bool isRemoved;
	int a; Student st;
	switch (in)

	{
	case ADD:
		cout << "\nYou choose ADD" << endl;
		st.readStudent();
		L.add(st);
		break;

	case DELETE:

		cout << "\nYou choose DELETE" << endl;
		// если массив не пустой, то можно написать номер
		cout << "Enter the number: ";
		cin >> a;
		a--;
		if (L.count > 0)
		{
			isRemoved = L.remove(a);
			if (isRemoved)
				cout << "Removed" << endl;
			else
				cout << "Not removed" << endl;
		}
		else
			cout << "The list is empty" << endl;
		break;

	case INSERT:
		cout << "\nYou choose INSERT" << endl;
		cout << "Enter the number of insertion: ";
		cin >> a;
		a--;
		L.count++;
		if (a < 0 || a >= L.count)
		{
			cout << "Mistake with number!!!" << endl;
			L.count--;
		}
		else
		{
			st.readStudent();
			L.insert(st, a);
		}
		output = false;
		break;

	case FIND:
		cout << "\nYou choose FIND" << endl;
		int ind;
		st.readStudent();
		ind = L.indexOf(&st, equals);
		if (ind != -1)
			cout << "The number of your member is " << ind + 1 << endl;
		else
			cout << "The list doesn't contain this shit" << endl;
		break;

	case PRINT:
		cout << "\nYou choose PRINT" << endl;

		if (L.count != 0)
		{
			for (int j = 0; j < L.count; j++)
			{
				cout << j + 1 << ". ";
				L.arr[j].printStudent();
			}
			cout << endl;
		}

		break;

	case EXIT:
		output = true;
		break;

	default:
		cout << "Mistake with command!" << endl;
		break;
	}
	return output;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	List<Student> myList;
	int in;
	bool output;

	do
	{
		console();
		cout << "Enter the command:";

		if (getValueInt(in))
		{
			output = FUNC(myList, in);
		}
		else
		{
			cout << "Mistake with command!" << endl;
			output = false;
		}
		cout << endl << endl;
	} while (output != true);
	return 0;
}