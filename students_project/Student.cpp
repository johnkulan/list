#include "Student.h"
#include "ConsoleReader.h"
#include <iostream>

void Student::printStudent()
{
	std::cout << name << "\t\t\t" << group << "\t\t\t"
		<< averageScore << std::endl;
}
void Student::readStudent()
{
	std::cout << "Enter the student: " << std::endl;
	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "Group: ";
	std::cin >> group;
	std::cout << "Score: ";
	getValueFloat(averageScore);
}

Student::Student(std::string name, std::string group, float averageScore)
{
	this->name = name;
	this->group = group; 
	this->averageScore = averageScore;
}
