#include "FullName.h"

bool FullName::isAllAlpha(const std::string& str) const
{
	size_t size = str.length();

	for (size_t i = 0; i < size; i++)
	{
		if (!isalpha(str[i]))
			return false;
	}

	return true;
}

FullName::FullName(const std::string& name, const std::string& secondName, const std::string& surname)
{
	this->setName(name);
	this->setSecondName(secondName);
	this->setSurname(surname);
}

void FullName::setName(const std::string& name)
{
	try
	{
		if (!this->isAllAlpha(name))
			throw "Incorrect name";

		this->name = name;
	}
	catch (const char* error)
	{
		std::cout << error << "\n";
	}
}

void FullName::setSecondName(const std::string& secondName)
{
	if (this->isAllAlpha(secondName))
		this->secondName = secondName;

}

void FullName::setSurname(const std::string& surname)
{
	if (!this->isAllAlpha(surname))
		this->surname = surname;
}

FullName& FullName::operator=(const FullName& fName)
{
	this->name = fName.getName();
	this->secondName = fName.getSecondName();
	this->surname = fName.getSurname();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const FullName& fName)
{
	out << fName.name << " " << fName.secondName << " " << fName.surname;
	return out;
}
