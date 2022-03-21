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
