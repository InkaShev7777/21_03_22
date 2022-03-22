#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
#include"FullName.h"
#include"Date.h"
#include"PhoneNumber.h"
#include"Address.h"
#include"Car.h"
#include"Company.h"

using std::vector;

class Contact
{
private:
	FullName fullName;
	Date birthday;
	vector<PhoneNumber> phoneNumbers; //sorted
	Address address;
	vector<Car> cars;
	vector<Company> companies;

	//print all elements of the list
	template<typename T>
	static void _show(const vector<T>& list, std::ostream& out, const std::string& text = "");

public:
	//ctors
	Contact(const FullName& fName, const Date& birthday, const vector<PhoneNumber>& numbers, const Address& address,
		const vector<Car>& cars, const vector<Company>& companies);
	
	Contact(const FullName& fName, const Date& birthday, const vector<PhoneNumber>& numbers);
	Contact(const FullName& fName, const Date& birthday);
	Contact(const FullName& fName);
	Contact(const std::string& name);

	//gets
	inline const FullName& getFullName() const
	{
		return this->fullName;
	}

	inline const Date& getBirthday() const
	{
		return this->birthday;
	}

	inline const vector<PhoneNumber>& getPhoneNumbers() const
	{
		return this->phoneNumbers;
	}

	inline Address& getAddress()
	{
		return this->address;
	}

	inline vector<Car>& getCars()
	{
		return this->cars;
	}

	inline vector<Company>& getCompanies()
	{
		return this->companies;
	}

	//sets
	void setFullName(const FullName& fName);
	void setBirthday(const Date& birthday);
	void setAddress(const Address& address);

	//adds only unique numbers and sorts numbers
	void addPhoneNumber(const std::string& number);

	//adds only unique cars
	void addCar(const Car& car);

	//adds only unique companies
	void addCompany(const Company& company);

	void show(std::ostream& out = std::cout) const;

	friend bool operator==(const Contact& contact_1, const Contact& contact_2);
	friend bool operator!=(const Contact& contact_1, const Contact& contact_2);

	virtual ~Contact() {}
};

template<typename T>
inline void Contact::_show(const vector<T>& list, std::ostream& out, const std::string& text)
{
	for (auto& el : list)
	{
		if (!text.empty())
		{
			out << text << ": ";
		}
		out << el << "\n";
	}
}
