#include "PhoneNumber.h"

bool PhoneNumber::_isAllDigits(const std::string& str)
{
	size_t size = str.length();

	for (size_t i = 0; i < size; i++)
	{
		if (!isdigit(str[i]))
			return false;
	}

	return true;
}

void PhoneNumber::_setOperator()
{
	if (this->number.empty())
	{
		this->_operator = Operator::Unknown;
	}
	else if (this->number.substr(0, 3) == "050" || this->number.substr(0, 3) == "066" || this->number.substr(0, 3) == "095")
	{
		this->_operator = Operator::Vodafone;
	}
	else if (this->number.substr(0, 3) == "067" || this->number.substr(0, 3) == "068" ||
		this->number.substr(0, 3) == "096" || this->number.substr(0, 3) == "097" || this->number.substr(0, 3) == "098")
	{
		this->_operator = Operator::Kyivstar;
	}
	else if (this->number.substr(0, 3) == "063" || this->number.substr(0, 3) == "093" || this->number.substr(0, 3) == "073")
	{
		this->_operator = Operator::Lifecell;
	}
	else
	{
		this->_operator = Operator::Unknown;
	}

}

PhoneNumber::PhoneNumber(const std::string& number)
{
	if (this->setNumber(number))
		this->_setOperator();
}

bool PhoneNumber::setNumber(const std::string& number)
{
	if (PhoneNumber::_isAllDigits(number))
	{
		this->number = number;
		return true;
	}

	return false;
}

Operator PhoneNumber::getOperator() const
{
	return this->_operator;
}

std::ostream& operator<<(std::ostream& out, const PhoneNumber& number)
{
	out << number.number;
	return out;
}

bool operator<(const PhoneNumber& number_1, const PhoneNumber& number_2)
{
	if (number_1._operator < number_2._operator)
		return true;

	else if(number_1._operator == number_2._operator)
		return number_1.number.substr(3) < number_2.number.substr(3);

	return false;
}

bool operator==(const PhoneNumber& number_1, const PhoneNumber& number_2)
{
	return number_1.number == number_2.number;
}

bool operator!=(const PhoneNumber& number_1, const PhoneNumber& number_2)
{
	return !(number_1 == number_2);
}
