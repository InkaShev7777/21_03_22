#include "Date.h"

Date::Date(int day, int month, int year) :_isSet{ true }, day{ 0 }, month{ 0 }, year{ 0 }
{
	if (day <= 0 || day > 31)
	{
		_isSet = false;
	}
	else
	{
		this->day = day;
	}

	if (month <= 0 || month > 12)
	{
		_isSet = false;
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
	this->_isSet = date.isCorrect();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	if(date._isSet)
		out << date.day << "/" << date.month << "/" << date.year;
	
	return out;
}

bool operator==(const Date& date_1, const Date& date_2)
{
	return (date_1.day == date_2.day && date_1.month == date_2.month && date_1.year == date_2.year);
}

bool operator!=(const Date& date_1, const Date& date_2)
{
	return !(date_1 == date_2);
}

bool operator<(const Date& date_1, const Date& date_2)
{
	if (date_1.year < date_2.year)
		return true;

	if (date_1.year == date_2.year && date_1.month < date_2.month)
		return true;

	if (date_1.year == date_2.year && date_1.month == date_2.month && date_1.day < date_2.day)
		return true;

	return false;
}

Date getToday()
{
	time_t seconds = time(NULL);
	tm today;
	localtime_s(&today, &seconds);

	return Date(today.tm_mday, today.tm_mon + 1, 1900 + today.tm_year);
}

Date getDate(const std::string& str)
{
	size_t pos = 0;
	int day, month, year;

	day = std::stoi(str, &pos);
	size_t i = pos;
	month = std::stoi(str.substr(i + 1), &pos);
	i += pos;
	year = std::stoi(str.substr(i + 2), &pos);
	return Date(day, month, year);
}
