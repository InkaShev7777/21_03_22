#include "PhoneNumber.h"

bool PhoneNumber::isAllDigits(const std::string& str)
{
	size_t size = str.length();

	for (size_t i = 0; i < size; i++)
	{
		if (!isdigit(str[i]))
			return false;
	}

	return true;
}

void PhoneNumber::setOperator()
{
	if (this->number.substr(0, 3) == "050" || this->number.substr(0, 3) == "066" || this->number.substr(0, 3) == "095")
	{
		this->_operator = "Vodafone";
	}
	else if (this->number.substr(0, 3) == "067" || this->number.substr(0, 3) == "068" ||
		this->number.substr(0, 3) == "096" || this->number.substr(0, 3) == "097" || this->number.substr(0, 3) == "098")
	{
		this->_operator = "Kyivstar";
	}
	else if (this->number.substr(0, 3) == "063" || this->number.substr(0, 3) == "093" || this->number.substr(0, 3) == "073")
	{
		this->_operator = "Lifecell";
	}
	else
	{
		this->_operator = "Unknown";
	}
}

PhoneNumber::PhoneNumber(const std::string& number)
{
	this->setNumber(number);
	this->setOperator();
}

void PhoneNumber::setNumber(const std::string& number)
{
	if (PhoneNumber::isAllDigits(number))
	{
		this->number = number;
	}
}

const std::string& PhoneNumber::getOperator() const
{
	return this->_operator;
}
