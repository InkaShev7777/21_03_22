#include "Actions.h"

bool Actions::addContact(ContactList& list)
{
	std::string name, surname, secName;
	do
	{
		cout << "Enter a name: ";
		std::getline(std::cin, name);

		if (name.empty())
		{
			cout << "The name is required\n";
		}

	} while (name.empty());

	cout << "Enter a second name: ";
	std::getline(std::cin, secName);

	cout << "Enter a surname: ";
	std::getline(std::cin, surname);

	if (!list.addContact(FullName(name, secName, surname), getToday()))
		return false;

	do
	{
		system("cls");
		Menu::showMenuAddProperty();

		char ch = _getch();

		if (ch == '0')
			break;

		switch (ch)
		{
		case '1':
			AddContactProperties::birthday(list.getContact(list.size() - 1));
			cout << "Added...";
			Sleep(2000);
			break;

		case '2':
			AddContactProperties::phoneNumber(list.getContact(list.size() - 1));
			cout << "Added...";
			Sleep(2000);
			break;

		case '3':
			AddContactProperties::address(list.getContact(list.size() - 1));
			cout << "Added...";
			Sleep(2000);
			break;

		case '4':
			AddContactProperties::car(list.getContact(list.size() - 1));
			cout << "Added...";
			Sleep(2000);
			break;

		case '5':
			AddContactProperties::company(list.getContact(list.size() - 1));
			cout << "Added...";
			Sleep(2000);
			break;
		}

	} while (true);

	return true;
}

size_t Actions::deleteContact(ContactList& list)
{
	std::string str;

	cout << "Enter a name: ";
	std::getline(std::cin, str);

	auto res = list.findByName(str);

	if (res.empty())
	{
		cout << "Not found\n";
		return 0;
	}

	cout << "Found:\n";
	Actions::showContacts(res);

	cout << "Delete them all? (1 - yes, other - cancel)\n";

	char ch = _getch();

	if (ch == '1')
	{
		return list.deleteContact(str);
	}

	return 0;
}

void Actions::findContact(const ContactList& list)
{
	system("cls");

	Menu::showMenuFindContact();

	char ch = _getch();

	if (ch == '0')
		return;

	std::string str;
	vector<pair<Contact, Date>> res;

	switch (ch)
	{
	case '1':
		cout << "Enter a name: ";
		std::getline(std::cin, str);
		res = list.findByName(str);
		break;

	case '2':
		cout << "Enter a second name: ";
		std::getline(std::cin, str);
		res = list.findBySecondName(str);
		break;

	case '3':
		cout << "Enter a surname: ";
		std::getline(std::cin, str);
		res = list.findBySurame(str);
		break;

	case '4':
		system("cls");
		Menu::showMenuOperators();
		ch = _getch();

		if (ch == '0')
			return;

		switch (ch)
		{
		case '1':
			res = list.findByOperator(Operator::Kyivstar);
			break;

		case '2':
			res = list.findByOperator(Operator::Lifecell);
			break;

		case '3':
			res = list.findByOperator(Operator::Vodafone);
			break;

		case '4':
			res = list.findByOperator(Operator::Unknown);
			break;
		}

		break;

	case '5':
		cout << "Enter a date (dd/mm/yyyy): ";
		std::getline(std::cin, str);

		try
		{
			res = list.findByAddingDate(getDate(str));
		}
		catch (std::exception)
		{
			cout << "Invalid date\n";
		}
		break;
	}

	if (res.empty())
	{
		cout << "Not found\n";
	}
	else
	{
		Actions::showContacts(res);
	}
}

void Actions::sort(ContactList& list)
{
	system("cls");

	Menu::showMenuSort();

	char ch = _getch();

	if (ch == '0')
		return;

	switch (ch)
	{
	case '1':
		list.sortByName();
		break;

	case '2':
		list.sortBySecondName();
		break;

	case '3':
		list.sortBySurname();
		break;

	case '4':
		list.sortByOperator();
		break;

	case '5':
		list.sortByAddingDate();
		break;
	}
}

void Actions::showContacts(const vector<pair<Contact, Date>>& contacts)
{
	size_t i = 0;

	for (auto& el : contacts)
	{
		cout << ++i << " =================================\n";
		cout << "Added: " << el.second << "\n";
		el.first.show();
	}
}

