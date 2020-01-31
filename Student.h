#pragma once
#include <string>
struct Student
{
	std::string name;		//имя студента
	std::string group;		//номер группы
	float averageScore;	//средний балл
	Student() {};

	Student(std::string name, std::string group, float averageScore);

	void printStudent();
	void readStudent();
	friend bool equals(Student*, Student*);
};
