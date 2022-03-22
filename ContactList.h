#pragma once
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include"Contact.h"

using std::vector;
using std::pair;

class ContactList
{
private:
	vector<pair<Contact, Date>> contacts; //Date - date of adding the contact
	std::string path; //path to the file with database

	void _show(pair < Contact, Date> el, std::ostream& out) const;

	//comparators for sorting
	static bool _compareNames(const pair<Contact, Date>& contact_1, const pair<Contact, Date>& contact_2);
	static bool _compareSecondnames(const pair<Contact, Date>& contact_1, const pair<Contact, Date>& contact_2);
	static bool _compareSurnames(const pair<Contact, Date>& contact_1, const pair<Contact, Date>& contact_2);
	static bool _compareOperators(const pair<Contact, Date>& contact_1, const pair<Contact, Date>& contact_2);
	static bool _compareDates(const pair<Contact, Date>& contact_1, const pair<Contact, Date>& contact_2);

	//gets date from string
	static Date _getDate(const std::string& str);

public:
	explicit ContactList(const std::string& path) :path{ path }
	{
		this->load();
	}

	//add contact. Returns true if the contact is added and false if the list already has a contact with the same fullname
	bool addContact(const Contact& contact, const Date& date);

	//delete contact/ Returns count of deleted elements
	size_t deleteContact(const std::string& name);

	//find
	vector<pair<Contact, Date>> findByName(const std::string& name) const;
	vector<pair<Contact, Date>> findBySurame(const std::string& surname) const;
	vector<pair<Contact, Date>> findBySecondName(const std::string& secName) const;
	vector<pair<Contact, Date>> findByOperator(Operator oper) const;
	vector<pair<Contact, Date>> findByAddingDate(const Date& date) const;

	//sort
	void sortByName();
	void sortBySecondName();
	void sortBySurname();
	void sortByOperator(); // sorting by the first number of the contact
	void sortByAddingDate();

	//shows
	void showContact(const Contact& contact, std::ostream& out = std::cout) const;
	void showAllContacts(std::ostream& out = std::cout) const;

	//save to the file. Returns true if the data is saved, false if it was en error during openning the file
	bool save() const;

	//load from the file. Returns true if the data is loaded, false if it was en error during openning the file
	bool load();

	~ContactList()
	{
		this->save();
	}
};
