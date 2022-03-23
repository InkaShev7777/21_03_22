#pragma once
#include<iostream>
#include<string>

class Date
{
private:
	int day;
	int month;
	int year;

	bool _isSet; //true if the date is correct

public:
	Date(int day, int month, int year);
	Date() = default;

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

	//return true if the date is correct
	inline bool isCorrect() const
	{
		return this->_isSet;
	}

	Date& operator=(const Date& date);

	//print only if the date is correct
	friend std::ostream& operator<<(std::ostream& out, const Date& date);

	friend bool operator==(const Date& date_1, const Date& date_2);
	friend bool operator!=(const Date& date_1, const Date& date_2);
	friend bool operator<(const Date& date_1, const Date& date_2);

	virtual ~Date() {}
};

Date getToday();


Date getDate(const std::string& str);


