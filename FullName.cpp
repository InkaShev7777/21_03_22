#include "FullName.h"

bool FullName::_isAllAlpha(const std::string& str) const
{
	for (auto i = str.begin(); i != str.end(); i++)
	{
		if (!isalpha(*i))
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
		if (!this->_isAllAlpha(name))
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
	if (this->_isAllAlpha(secondName))
		this->secondName = secondName;

}

void FullName::setSurname(const std::string& surname)
{
	if (this->_isAllAlpha(surname))
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
	if (!fName.name.empty())
	{
		out << "Name: " << fName.name << "\n";
	}
	
	if (!fName.secondName.empty())
	{
		out << "Second name: " << fName.secondName << "\n";
	}
	
	if (!fName.surname.empty())
	{
		out << "Surname: " << fName.surname;
	}

	return out;
}

bool operator==(const FullName& fName_1, const FullName& fName_2)
{
	return (fName_1.name == fName_2.name && fName_1.secondName == fName_2.secondName && fName_1.surname == fName_2.surname);
}

bool operator!=(const FullName& fName_1, const FullName& fName_2)
{
	return !(fName_1 == fName_2);
}
