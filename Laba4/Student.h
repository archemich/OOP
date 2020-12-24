#pragma once
#include <string>
class Student
{
public:
	Student() = default;
	Student(
		const std::string& first_name,
		const std::string& second_name,
		const std::string& last_name,
		const std::string& group,
		const double rating,
		const bool has_scolarship
		);
	int getId() const { return id; }
	std::string const &getFirstName() const { return first_name; }
	std::string const& getSecondName() const { return second_name; }
	std::string const& getLastName() const { return last_name; }
	std::string const& getGroup() const { return group; }
	double getRating() const { return rating; }
	bool hasScolarship() const { return has_scolarship; }

private:
	static int idgen;
	int id;
	std::string first_name;
	std::string second_name;
	std::string last_name;
	std::string group;
	double rating;
	bool has_scolarship;
};

