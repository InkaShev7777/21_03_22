#pragma once
#include<iostream>

class FullName
{
private:
	std::string name;
	std::string secondName;
	std::string surname;

	//return true if str contains only alphas
	bool _isAllAlpha(const std::string& str) const;

public:
	//name is required. Name, secondName and surname are setting only if they contain only alphas. Throw an exception if name is incorrect
	explicit FullName(const std::string& name, const std::string& secondName = "", const std::string& surname = "");

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

	//sets. Setting only if name contains only alphas
	void setName(const std::string& name); //throw an exception if name is incorrect
	void setSecondName(const std::string& name);
	void setSurname(const std::string& name);

	FullName& operator = (const FullName& fName);

	friend std::ostream& operator<<(std::ostream& out, const FullName& fName);

	friend bool operator==(const FullName& fName_1, const FullName& fName_2);
	friend bool operator!=(const FullName& fName_1, const FullName& fName_2);

	virtual ~FullName() {}
};

