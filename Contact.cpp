#include "Contact.h"

Contact::Contact(const FullName& fName, const Date& birthday, const vector<PhoneNumber>& numbers, const Address& address,
	const vector<Car>& cars, const vector<Company>& companies):
	fullName{ fName }, birthday{ birthday }, phoneNumbers{ numbers }, address{ address }, cars{ cars }, companies{ companies }
{
}

Contact::Contact(const FullName& fName, const Date& birthday, const vector<PhoneNumber>& numbers) : Contact(fName, birthday)
{
	this->phoneNumbers = numbers;
}

Contact::Contact(const FullName& fName, const Date& birthday) : Contact(fName)
{
	this->birthday = birthday;
}

Contact::Contact(const FullName& fName): Contact(fName.getName())
{
	this->fullName = fName;
}

Contact::Contact(const std::string& name) : fullName{ FullName(name) }, birthday{ Date() }, phoneNumbers{ vector < PhoneNumber>()},
cars{ vector<Car>() }, address{ Address() }, companies{ vector<Company>() }
{
}

void Contact::setFullName(const FullName& fName)
{
	this->fullName = fName;
}

void Contact::setBirthday(const Date& birthday)
{
	this->birthday = birthday;
}

void Contact::setAddress(const Address& address)
{
	this->address = address;
}

void Contact::addPhoneNumber(const std::string& number)
{
	if (std::find(this->phoneNumbers.begin(), this->phoneNumbers.end(), PhoneNumber(number)) == this->phoneNumbers.end())
	{
		this->phoneNumbers.push_back(PhoneNumber(number));
		std::sort(this->phoneNumbers.begin(), this->phoneNumbers.end());
	}
}

void Contact::addCar(const Car& car)
{
	if (std::find(this->cars.begin(), this->cars.end(), car) == this->cars.end())
	{
		this->cars.push_back(car);
	}
}

void Contact::addCompany(const Company& company)
{
	if (std::find(this->companies.begin(), this->companies.end(), company) == this->companies.end())
	{
		this->companies.push_back(company);
	}
}

void Contact::show(std::ostream& out) const
{
	out << this->fullName << "\n";
	
	if (this->birthday.isCorrect())
	{
		out << "Birthday: " << this->birthday << "\n";
	}

	if (!this->phoneNumbers.empty())
	{
		Contact::_show(this->phoneNumbers, out, "Phone number");
	}

	if (!this->address.isEmpty())
	{
		out << "Address:\n";
		out << this->address << "\n";
	}

	if (!this->cars.empty())
	{
		Contact::_show(this->cars, out, "Car");
	}

	if (!this->companies.empty())
	{
		Contact::_show(this->companies, out, "Company");
	}
}

bool operator==(const Contact& contact_1, const Contact& contact_2)
{
	return (contact_1.fullName == contact_2.fullName);
}

bool operator!=(const Contact& contact_1, const Contact& contact_2)
{
	return !(contact_1 == contact_2);
}
