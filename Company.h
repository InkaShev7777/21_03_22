#pragma once
#include<iostream>

class Company
{
private:
	std::string name;
	std::string position;

public:
	Company(const std::string& name = "", const std::string& position = "");

	//gets
	inline const std::string& getName() const
	{
		return this->name;
	}
	
	inline const std::string& getPosition() const
	{
		return this->position;
	}

	//sets
	void setName(const std::string& name);
	void setPosition(const std::string& position);

	friend std::ostream& operator<<(std::ostream& out, const Company& company);

	friend bool operator==(const Company& company_1, const Company& company_2);
	friend bool operator!=(const Company& company_1, const Company& company_2);

	virtual ~Company()
	{

	}
};

