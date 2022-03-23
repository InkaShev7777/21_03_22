#include "AddContactProperties.h"

void AddContactProperties::birthday(Contact& contact)
{
	cout << "Enter a birthday (dd/mm/yyyy): ";

	std::string str;
	std::getline(std::cin, str);

	try
	{
		contact.setBirthday(getDate(str));
	}
	catch (std::exception)
	{
		cout << "Invalid date\n";
	}
}

void AddContactProperties::phoneNumber(Contact& contact)
{
	cout << "Enter a phone number: ";

	std::string str;
	std::getline(std::cin, str);

	contact.addPhoneNumber(str);
}

void AddContactProperties::address(Contact& contact)
{
	cout << "Enter an address:\n";

	std::string str;

	cout << "\tCountry: ";
	std::getline(std::cin, str);
	contact.getAddress().setCountry(str);

	cout << "\tCity: ";
	std::getline(std::cin, str);
	contact.getAddress().setCity(str);

	cout << "\tStreet: ";
	std::getline(std::cin, str);
	contact.getAddress().setStreet(str);

	cout << "\tHouse: ";
	std::getline(std::cin, str);
	contact.getAddress().setHouse(str);

	cout << "\tAppartment: ";
	int app;
	std::cin >> app;
	std::cin.ignore();
	contact.getAddress().setAppartment(app);
}

void AddContactProperties::car(Contact& contact)
{
	cout << "Enter a car:\n";

	std::string brand, model, number;

	cout << "\tBrand: ";
	std::getline(std::cin, brand);

	cout << "\tModel: ";
	std::getline(std::cin, model);

	cout << "\tNumber: ";
	std::getline(std::cin, number);

	contact.addCar(Car(brand, model, number));
}

void AddContactProperties::company(Contact& contact)
{
	cout << "Enter a company:\n";

	std::string name, pos;

	cout << "\tName: ";
	std::getline(std::cin, name);

	cout << "\tPosition: ";
	std::getline(std::cin, pos);

	contact.addCompany(Company(name, pos));
}
