#include "Date.h"

Date::Date(int day, int month, int year) :isSet{ true }, day{ 0 }, month{ 0 }, year{ 0 }
{
	if (day <= 0 || day > 31)
	{
		isSet = false;
	}
	else
	{
		this->day = day;
	}

	if (month <= 0 || month > 12)
	{
		isSet = false;
	}
	else
	{
		this->month = month;
	}

	this->year = year;
}

Date& Date::operator=(const Date& date)
{
	this->day = date.getDay();
	this->month = date.getMonth();
	this->year = date.getYear();
	this->isSet = date.isCorrect();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	if(date.isSet)
		out << date.day << "/" << date.month << "/" << date.year;
	
	return out;
}
