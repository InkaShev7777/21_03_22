#pragma once
#include<iostream>

enum class Operator
{
	Kyivstar,
	Lifecell,
	Unknown,
	Vodafone
};

class PhoneNumber
{
private:
	std::string number;
	Operator _operator;

	//return true if str contains only digits
	static bool _isAllDigits(const std::string& str);

	//sets _operator using first three digits
	void _setOperator();

public:
	//sets number only if the number is correct
	PhoneNumber(const std::string& number = "");

	//sets number only if the number is correct. Returns true if the set is successful
	bool setNumber(const std::string& number);

	inline const std::string& getNumber() const
	{
		return this->number;
	}

	Operator getOperator() const;

	friend std::ostream& operator<<(std::ostream& out, const PhoneNumber& number);

	//first compares by the operator, then by the number without operator's code
	friend bool operator<(const PhoneNumber& number_1, const PhoneNumber& number_2);

	friend bool operator==(const PhoneNumber& number_1, const PhoneNumber& number_2);
	friend bool operator!=(const PhoneNumber& number_1, const PhoneNumber& number_2);

	virtual ~PhoneNumber() {}
};

