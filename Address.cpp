#include "Address.h"

Address::Address(const std::string& country, const std::string& city, const std::string& street, const std::string& house, int app):
	country{ country }, city{ city }, street{ street }, house{ house }, app{ app }
{
}

void Address::setCountry(const std::string& country)
{
	this->country = country;
}

void Address::setCity(const std::string& city)
{
	this->city = city;
}

void Address::setStreet(const std::string& street)
{
	this->street = street;
}

void Address::setHouse(const std::string& house)
{
	this->house = house;
}

void Address::setAppartment(int app)
{
	this->app = app;
}

bool Address::isEmpty() const
{
	return this->country.empty() && this->city.empty() && this->street.empty() && this->house.empty() && this->app == 0;
}

std::ostream& operator<<(std::ostream& out, const Address& address)
{
	if (!address.country.empty())
		out << "\tCountry: " << address.country << "\n";

	if (!address.city.empty())
		out << "\tCity: " << address.city << "\n";

	if (!address.street.empty())
		out << "\tStreet: " << address.street << "\n";

	if (!address.house.empty())
		out << "\tHouse: " << address.house << "\n";

	if (address.app != 0)
		out << "\tAppartment: " << address.app;


	return out;
}
