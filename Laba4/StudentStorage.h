#pragma once
#include <vector>
#include <map>
#include <string>
#include <set>
#include "Student.h"

class StudentStorage
{
public:
	StudentStorage() = default;

	void addStudent(const Student &stud);
	std::vector<Student*>* getStudents();
	Student* findStudentById(int id);
	std::vector<Student*>* findStudentsByGroup(std::string group);
	std::vector<Student*>* findStudentsByRating(double rating);


private:
	std::map<int, Student> students;
	std::map<std::string, std::set<int>> students_by_group;
	std::map<double, std::set<int>> students_by_rating;


};

