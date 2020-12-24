#include "StorageBuilder.h"

StudentStorage* StorageBuilder::createStudentStorage()
{
	try
	{
		StudentStorage* storage = new StudentStorage();
		return storage;
	}
	catch(std::exception &e)
	{
		return nullptr;
	}
}
