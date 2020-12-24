#pragma once
#include <vector>
#include "Student.h"
#include "StudentStorage.h"

class ConsoleUI
{
public:
	ConsoleUI();
	~ConsoleUI();
	void run();
	

private:
	StudentStorage* storage;
	int ReadInt();
	double ReadDouble();
	bool ReadBool();
	void printMenuText();
	void prompt();
	std::vector<Student*>* getStudents();
	std::vector<Student*>* findStudentsByGroup();
	std::vector<Student*>* findStudentsByRating();
	Student* addStudent();
	void printStudentVector(std::vector<Student*>& vector);
	void printStudent(Student &student);
	enum command { _EXIT, _ADDSTUDENT, _GETSTUDENTS, _GETSTUDENTSBYGROUP, _GETSTUDENTSBYRAITING, _PRINTMENUTEXT };
};
