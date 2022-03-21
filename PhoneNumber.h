#pragma once
#include<iostream>

class PhoneNumber
{
private:
	std::string number;
	std::string _operator;

	static bool isAllDigits(const std::string& str);
	void setOperator();

public:
	PhoneNumber(const std::string& number = "");

	void setNumber(const std::string& number);

	inline const std::string& getNumber() const
	{
		return this->number;
	}

	const std::string& getOperator() const;
};

