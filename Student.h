#pragma once
#include <string>
struct Student
{
	std::string name;		//��� ��������
	std::string group;		//����� ������
	float averageScore;	//������� ����
	Student() {};

	Student(std::string name, std::string group, float averageScore);

	void printStudent();
	void readStudent();
	friend bool equals(Student*, Student*);
};
