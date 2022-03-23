#include "Menu.h"

void Menu::showMainMenu()
{
	cout << "1 - Show all contacts\n";
	cout << "2 - Add contact\n";
	cout << "3 - Delete contact\n";
	cout << "4 - Find contact\n";
	cout << "5 - Sort\n";
	cout << "6 - Save\n";
	cout << "0 - Exit\n";
}

void Menu::showMenuAddProperty()
{
	cout << "1 - Add birthday\n";
	cout << "2 - Add phone number\n";
	cout << "3 - Add address\n";
	cout << "4 - Add car\n";
	cout << "5 - Add company\n";
	cout << "0 - Exit\n";
}

void Menu::showMenuFindContact()
{
	cout << "1 - Find by name\n";
	cout << "2 - Find by second name\n";
	cout << "3 - Find by surname\n";
	cout << "4 - Find by operator\n";
	cout << "5 - Find by adding date\n";
	cout << "0 - Exit\n";
}

void Menu::showMenuOperators()
{
	cout << "1 - Kyivstar\n";
	cout << "2 - Lifecell\n";
	cout << "3 - Vodafone\n";
	cout << "4 - Others\n";
	cout << "0 - Exit\n";
}

void Menu::showMenuSort()
{
	cout << "1 - Sort by name\n";
	cout << "2 - Sort by second name\n";
	cout << "3 - Sort by surname\n";
	cout << "4 - Sort by operator\n";
	cout << "5 - Sort by adding date\n";
	cout << "0 - Exit\n";
}
