#include <iostream>
#include <vector>
#include <stdexcept>
#include "Student.h"
#include "StorageBuilder.h"
#include "ConsoleUI.h"

//enum command { _EXIT, _ADDSTUDENT, _GETSTUDENTS, _GETSTUDENTSBYGROUP, _GETSTUDENTSBYRAITING, _PRINTMENUTEXT };

void ConsoleUI::prompt()
{
	std::cout << "\nUser $"; 
}


void ConsoleUI::printMenuText()
{
    std::cout << "enum command { _EXIT, _ADDSTUDENT, _GETSTUDENTS, _GETSTUDENTSBYGROUP, _GETSTUDENTSBYRAITING, _LOADFROMFILE, _PRINTMENUTEXT }" << std::endl;
}




std::vector<Student*>* ConsoleUI::getStudents()
{
    return storage->getStudents();
}


std::vector<Student*>* ConsoleUI::findStudentsByGroup()
{
    std::cout << "Write group:";
    prompt();
    std::string group;
    std::cin >> group;
    return storage->findStudentsByGroup(group);
}


std::vector<Student*>* ConsoleUI::findStudentsByRating()
{
    std::cout << "Write rating:";
    prompt();
    double rating = ReadDouble();
    return storage->findStudentsByRating(rating);
}


Student* ConsoleUI::addStudent()
{
    try {
        std::string fn, sn, ln, gr;
        double rating;
        bool has_scolar;
        std::cout << "Add Student."<<std::endl;
        std::cout << "Write first name:"; prompt();
        std::cin >> fn;
        std::cout << "Write second name:"; prompt();
        std::cin >> sn;
        std::cout << "Write last name:"; prompt();
        std::cin >> ln;
        std::cout << "Write group:"; prompt();
        std::cin >> gr;
        std::cout << "Write average score:"; prompt();
        rating = ReadDouble();
        std::cout << "Write 0 if has not scolarship or 1 if has scolarship:"; prompt();
        has_scolar = ReadBool();
        Student* student = new Student(fn, sn, ln, gr, rating, has_scolar);
        storage->addStudent(*student);
        return student;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
        return nullptr;
    }
    
}





int ConsoleUI::ReadInt()
{
    using std::cin;
    int a = 0;
    prompt();
    cin >> a;
    if (cin.fail())
    {
        do
        {
            prompt();
            cin.clear();
            cin.ignore(INT64_MAX, '\n');
            cin >> a;
        } while (cin.fail());
    }
    return a;
}


double ConsoleUI::ReadDouble()
{
    using std::cin;
    double a = 0;
    cin >> a;
    if (cin.fail())
    {
        do
        {
            prompt();
            cin.clear();
            cin.ignore(INT64_MAX, '\n');
            cin >> a;
        } while (cin.fail());
    }
    return a;
}


bool ConsoleUI::ReadBool()
{
    using std::cin;
    char a = 0;
    while (a != '0' && a != '1')
    {
        cin >> a;
    }
    if (a == '0')
        return false;
    return true;

    
}


void ConsoleUI::printStudent(Student& student)
{
    std::cout << student.getId() << "\t" << student.getFirstName() << " " << student.getSecondName() << " " << student.getLastName() << " " << student.getGroup() << "\t" << student.getRating() << "\t" << (student.hasScolarship() ? "Yes" : "No") << std::endl;
}


void ConsoleUI::printStudentVector(std::vector<Student*> &vector )
{
    auto it = vector.begin();
    std::cout << "Id\tFull name\tGroup\tRating\tHas scolarship";
    for (; it != vector.end(); ++it)
    {
        printStudent(**it);
    }
}


ConsoleUI::ConsoleUI() : storage(nullptr)
{
    
    StudentStorage* storage = StorageBuilder::createStudentStorage();
    if (storage == nullptr)
    {
        throw std::runtime_error("Can't create student storage.");
    }
}

ConsoleUI::~ConsoleUI()
{
    delete storage;
}

void ConsoleUI::run()
{
	bool running = true;

	while (running)
	{
        printMenuText();
        int choice = ReadInt();
		switch (choice)
        { 
        case _EXIT:
        {
            running = 0;
            return;
            break;
        }
        case _ADDSTUDENT:
        {
            Student* newStudent = addStudent();
            printStudent(*newStudent);
            break;

        }
        case _GETSTUDENTS:
        {
            std::vector<Student*> *students = getStudents();
            printStudentVector(*students);
            break;

        }
        case _GETSTUDENTSBYGROUP:
        {
            std::vector<Student*> *students = findStudentsByGroup();
            printStudentVector(*students);
            break;

        }
        case _GETSTUDENTSBYRAITING: 
        {
            std::vector<Student*> *students = findStudentsByRating();
            printStudentVector(*students);
            break;

        }
      
        case _PRINTMENUTEXT:
        {
            printMenuText();
            prompt();
            break;

        }
        }
		
	}
}



