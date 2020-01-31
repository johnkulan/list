#pragma once
#include "Student.h"
template <typename T>
class List
{
public:
	T* arr;
	int count;
	List() : count(0), max(4) { arr = new T[max]; }

	T& operator[](int i);
	void add(T& elem);
	bool remove(int a);
	void insert(T& elem, int a);
	int indexOf(T* elem, bool (*equal)(T*, T*));

private:
	int max;
	void ExpandList();
};


template <typename T>
void List<T>::ExpandList()
{
	if (count >= max)
	{
		max *= 2; //увеличиваем размер максимального массива
		T* arr1 = new T[max]; //создание нового массива и переписываем в новый
		for (int j = 0; j < count; j++)
		{

			arr1[j] = arr[j];
		}
		delete[]arr; //удаляем старый
		arr = arr1; // указатель на новый массив
	}
}

template <typename T>
int List<T>::indexOf(T* elem, bool (*equal)(T*, T*))
{
	int temp = -1;
	for (int i = 0; i < count; i++)
		if (equal(arr + i, elem))
			temp = i;
	return temp;
}

template <typename T>
void List<T>::insert(T & elem, int a)
{
	ExpandList();
	bool output = false;
	do
	{
		if (count != 0) // если при вставке список не пуст
		{
			for (int j = count; j > a; j--)
			{
				arr[j] = arr[j - 1];
			}
			output = true;
			arr[a] = elem;
		}
		else // а если пуст, то просто добавляем первый элемент
		{
			add(elem);
		}
	} while (output != true);
}

template <typename T>
bool List<T>::remove(int a)
{
	bool output = true;

	if (count != 0) // если список пуст?
	{
		if (a >= 0 && a <= count) //проверка правильности ввода номера
		{
			// если удаляется послений элемент
			if (a == count) delete arr;

			else // присваиваем номеру удаления, следующий по списку элемент
			{
				for (int j = a; j < count; j++)
					arr[j] = arr[j + 1];
			}
			count--;
		}
		else output = false;
	}
	else output = false;
	return output;


}

template <typename T>
void List<T>::add(T & elem)
{
	ExpandList();
	arr[count] = elem; //добавляем нового студента в конец списка
	count++;
}

template <typename T>
T& List<T>:: operator[](int i)
{
	return T(*arr + i);
}