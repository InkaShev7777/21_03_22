#include "ContactList.h"

void ContactList::_show(pair<Contact, Date> el, std::ostream& out) const
{
	out << "Added: " << el.second << "\n";
	el.first.show(out);
}

bool ContactList::_compareNames(const pair<Contact, Date>& contact_1, const pair<Contact, Date>& contact_2)
{
	return contact_1.first.getFullName().getName() < contact_2.first.getFullName().getName();
}

bool ContactList::_compareSecondnames(const pair<Contact, Date>& contact_1, const pair<Contact, Date>& contact_2)
{
	return contact_1.first.getFullName().getSecondName() < contact_2.first.getFullName().getSecondName();
}

bool ContactList::_compareSurnames(const pair<Contact, Date>& contact_1, const pair<Contact, Date>& contact_2)
{
	return contact_1.first.getFullName().getSurname() < contact_2.first.getFullName().getSurname();
}

bool ContactList::_compareOperators(const pair<Contact, Date>& contact_1, const pair<Contact, Date>& contact_2)
{
	return contact_1.first.getPhoneNumbers().front().getOperator() < contact_2.first.getPhoneNumbers().front().getOperator();
}

bool ContactList::_compareDates(const pair<Contact, Date>& contact_1, const pair<Contact, Date>& contact_2)
{
	return contact_1.second < contact_2.second;
}

Date ContactList::_getDate(const std::string& str)
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

bool ContactList::addContact(const Contact& contact, const Date& date)
{
	for (auto& el : this->contacts)
	{
		if (el.first == contact)
			return false;
	}

	this->contacts.push_back(std::make_pair(contact, date));
	return true;
}

size_t ContactList::deleteContact(const std::string& name)
{
	size_t count = 0;

	for (auto i = this->contacts.begin(); i != this->contacts.end(); i++)
	{
		if (i->first.getFullName().getName() == name)
		{
			this->contacts.erase(i);
			i--;
			count++;
		}
	}

	return count;
}

vector<pair<Contact, Date>> ContactList::findByName(const std::string& name) const
{
	vector<pair<Contact, Date>> res;

	for (auto& el : this->contacts)
	{
		if (el.first.getFullName().getName() == name)
		{
			res.push_back(el);
		}
	}

	return res;
}

vector<pair<Contact, Date>> ContactList::findBySurame(const std::string& surname) const
{
	vector<pair<Contact, Date>> res;

	for (auto& el : this->contacts)
	{
		if (el.first.getFullName().getSurname() == surname)
		{
			res.push_back(el);
		}
	}
	return res;
}

vector<pair<Contact, Date>> ContactList::findBySecondName(const std::string& secName) const
{
	vector<pair<Contact, Date>> res;

	for (auto& el : this->contacts)
	{
		if (el.first.getFullName().getSecondName() == secName)
		{
			res.push_back(el);
		}
	}

	return res;
}

vector<pair<Contact, Date>> ContactList::findByOperator(Operator oper) const
{
	vector<pair<Contact, Date>> res;

	for (auto& el : this->contacts)
	{
		for (auto& num : el.first.getPhoneNumbers())
		{
			if (num.getOperator() == oper)
			{
				res.push_back(el);
				break;
			}
		}
	}
	return res;
}

vector<pair<Contact, Date>> ContactList::findByAddingDate(const Date& date) const
{
	vector<pair<Contact, Date>> res;

	for (auto& el : this->contacts)
	{
		if (el.second == date)
		{
			res.push_back(el);
		}
	}

	return res;
}

void ContactList::sortByName()
{
	std::sort(this->contacts.begin(), this->contacts.end(), ContactList::_compareNames);
}

void ContactList::sortBySecondName()
{
	std::sort(this->contacts.begin(), this->contacts.end(), ContactList::_compareSecondnames);
}

void ContactList::sortBySurname()
{
	std::sort(this->contacts.begin(), this->contacts.end(), ContactList::_compareSurnames);
}

void ContactList::sortByOperator()
{
	std::sort(this->contacts.begin(), this->contacts.end(), ContactList::_compareOperators);
}

void ContactList::sortByAddingDate()
{
	std::sort(this->contacts.begin(), this->contacts.end(), ContactList::_compareDates);
}

void ContactList::showContact(const Contact& contact, std::ostream& out) const
{
	for (auto& el : this->contacts)
	{
		if (el.first == contact)
		{
			this->_show(el, out);
		}
	}
}

void ContactList::showAllContacts(std::ostream& out) const
{
	for (auto& el : this->contacts)
	{
		this->_show(el, out);
		out << "===============================\n";
	}
}

bool ContactList::save() const
{
	std::ofstream file;
	file.open(this->path);

	if (!file.is_open())
		return false;

	this->showAllContacts(file);

	file.close();

	return true;
}

bool ContactList::load()
{
	std::ifstream file;

	file.open(this->path);

	if (!file.is_open())
		return false;

	std::string str;

	unsigned int count = -1;

	while (std::getline(file, str))
	{

		size_t pos = 0;
		pos = str.find(':');

		if (pos == std::string::npos)
			continue;

		std::string property = str.substr(0, pos);

		if (property == "Added")
		{
			std::string name = "";
			std::string secName = "";
			std::string surname = "";
			Date addDate = ContactList::_getDate(str.substr(pos + 2));
			
			if (file.eof())
				break;

			std::getline(file, str);
			pos = str.find(':');

			if (pos == std::string::npos)
				break;

			property = str.substr(0, pos);

			while (!file.eof() && (property == "Name" || property == "Second name" || property == "Surname"))
			{
				if (property == "Name")
				{
					name = str.substr(pos + 2);
				}

				else if (property == "Second name")
				{
					secName = str.substr(pos + 2);
				}

				else if (property == "Surname")
				{
					surname = str.substr(pos + 2);
				}

				std::getline(file, str);
				pos = str.find(':');

				if (pos == std::string::npos)
					break;

				property = str.substr(0, pos);
			}

			this->addContact(Contact(FullName(name, secName, surname)), addDate);
			count++;
		}

		if (str.empty())
			continue;

		str.erase(0, str.find_first_not_of(" \n\r\t"));

		pos = str.find(':');

		if (pos == std::string::npos)
			break;

		property = str.substr(0, pos);

		if (property == "Birthday")
		{
			this->contacts[count].first.setBirthday(ContactList::_getDate(str.substr(pos + 2)));
		}

		else if (property == "Phone number")
		{
			this->contacts[count].first.addPhoneNumber(str.substr(pos + 2));
		}

		else if (property == "Country")
		{
			this->contacts[count].first.getAddress().setCountry(str.substr(pos + 2));
		}

		else if (property == "City")
		{
			this->contacts[count].first.getAddress().setCity(str.substr(pos + 2));
		}

		else if (property == "Street")
		{
			this->contacts[count].first.getAddress().setStreet(str.substr(pos + 2));
		}

		else if (property == "House")
		{
			this->contacts[count].first.getAddress().setHouse(str.substr(pos + 2));
		}

		else if (property == "Appartment")
		{
			this->contacts[count].first.getAddress().setAppartment(std::stoi(str.substr(pos + 2)));
		}

		else if (property == "Car")
		{
			this->contacts[count].first.getCars().push_back(Car());

			size_t i = 0;

			if ((i = str.find("Brand")) != std::string::npos)
			{
				i += strlen("Brand: ");
				size_t j = str.find_first_of(" \n\r\t", i);
				this->contacts[count].first.getCars().back().setBrand(str.substr(i, j - i));
			}

			if ((i = str.find("Model")) != std::string::npos)
			{
				i += strlen("Model: ");
				size_t j = str.find_first_of(" \n\r\t", i);
				this->contacts[count].first.getCars().back().setModel(str.substr(i, j - i));
			}

			if ((i = str.find("Number")) != std::string::npos)
			{
				i += strlen("Number: ");
				size_t j = str.find_first_of(" \n\r\t", i);
				this->contacts[count].first.getCars().back().setNumber(str.substr(i, j - i));
			}
		}

		else if (property == "Company")
		{
			this->contacts[count].first.getCompanies().push_back(Company());

			size_t i = 0;

			if ((i = str.find("Company name")) != std::string::npos)
			{
				i += strlen("Company name: ");
				size_t j = str.find_first_of(" \n\r\t", i);
				this->contacts[count].first.getCompanies().back().setName(str.substr(i, j - i));
			}

			if ((i = str.find("Position")) != std::string::npos)
			{
				i += strlen("Position: ");
				size_t j = str.find_first_of(" \n\r\t", i);
				this->contacts[count].first.getCompanies().back().setPosition(str.substr(i, j - i));
			}
		}
	}

	file.close();

	return true;
}
