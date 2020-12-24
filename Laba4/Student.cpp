#include "Student.h"

int Student::idgen = 0;

Student::Student(
	const std::string& first_name,
	const std::string& second_name,
	const std::string& last_name,
	const std::string& group,
	const double rating,
	const bool has_scolarship
) 
	: first_name(first_name), second_name(second_name), 
	group(group), rating(rating), 
	has_scolarship(has_scolarship), id(idgen++)
{
};