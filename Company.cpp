#include "Company.h"

Company::Company(const std::string& name, const std::string& position) :name{ name }, position{ position }
{

}

void Company::setName(const std::string& name)
{
	this->name = name;
}

void Company::setPosition(const std::string& position)
{
	this->position = position;
}

std::ostream& operator<<(std::ostream& out, const Company& company)
{
	if (!company.name.empty())
	{
		out << "\tCompany name: " << company.name;
	}

	if (!company.position.empty())
	{
		out << "\tPosition: " << company.position;
	}

	return out;
}

bool operator==(const Company& company_1, const Company& company_2)
{
	return company_1.name == company_2.name && company_1.position == company_2.position;
}

bool operator!=(const Company& company_1, const Company& company_2)
{
	return !(company_1 == company_2);
}
