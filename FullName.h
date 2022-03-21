#pragma once
#include<iostream>

class FullName
{
private:
	std::string name;
	std::string secondName;
	std::string surname;

	bool isAllAlpha(const std::string& str) const;

public:
	FullName(const std::string& name, const std::string& secondName = "", const std::string& surname = "");

	//gets
	inline const std::string& getName() const
	{
		return this->name;
	}

	inline const std::string& getSecondName() const
	{
		return this->secondName;
	}

	inline const std::string& getSurname() const
	{
		return this->surname;
	}

	//sets
	void setName(const std::string& name);
	void setSecondName(const std::string& name);
	void setSurname(const std::string& name);

	FullName& operator = (const FullName& fName);

	friend std::ostream& operator<<(std::ostream& out, const FullName& fName);
};

