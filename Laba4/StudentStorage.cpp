#include "StudentStorage.h"
#include <stdexcept>

void StudentStorage::addStudent(const Student& student)
{
	try {
		int id = student.getId();
		students.insert({ id, student });
		auto itGroup = students_by_group.find(student.getGroup());
		if (itGroup != students_by_group.end())
		{
			itGroup->second.insert(id);
		}
		else 
		{
			students_by_group[student.getGroup()] = std::set<int>();
			students_by_group[student.getGroup()].insert(id);

		}
	}
	catch (std::logic_error& e){
		throw e;
	}
}

std::vector<Student*>* StudentStorage::getStudents()
{
	std::vector<Student*>* studentsVector = new std::vector<Student*>();
	for (auto it = students.begin(); it != students.end(); ++it)
	{
		studentsVector->push_back(&it->second);
	}
	return studentsVector;
}

Student* StudentStorage::findStudentById(int id)
{
	auto it = students.find(id);
	if (it != students.end()) {
		return &(it->second);
	}
	return nullptr;
}


std::vector<Student*>* StudentStorage::findStudentsByGroup(std::string group)
{
	std::vector<Student*>* studentsVector = new std::vector<Student*>();
	auto it = students_by_group.find(group);
	if (it != students_by_group.end())
	{
		auto itSet = it->second.begin();
		for (; itSet != it->second.end(); ++itSet)
		{
			studentsVector->push_back(&students[*itSet]);
		}
	}
	return studentsVector;
}

std::vector<Student*>* StudentStorage::findStudentsByRating(double rating)
{
	std::vector<Student*> *studentsVector = new std::vector<Student*>();;
	auto it = students_by_rating.find(rating);
	if (it != students_by_rating.end())
	{
		auto itSet = it->second.begin();
		for (; itSet != it->second.end(); ++itSet)
		{
			studentsVector->push_back(&students[*itSet]);
		}
	}
	return studentsVector;
}
