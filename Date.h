#pragma once
#include<iostream>

class Date
{
private:
	int day;
	int month;
	int year;

	bool isSet;

public:
	Date(int day, int month, int year);

	//gets

	inline int getDay() const
	{
		return this->day;
	}

	inline int getMonth() const
	{
		return this->month;
	}

	inline int getYear() const
	{
		return this->year;
	}

	inline bool isCorrect() const
	{
		return this->isSet;
	}

	Date& operator=(const Date& date);

	friend std::ostream& operator<<(std::ostream& out, const Date& date);
};

