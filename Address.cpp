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

std::ostream& operator<<(std::ostream& out, const Address& address)
{
	if (address.country != "")
		out << "Country: " << address.country << "\n";

	if (address.city != "")
		out << "City: " << address.city << "\n";

	if (address.street != "")
		out << "Street: " << address.street << "\n";

	if (address.house != "")
		out << "House: " << address.house << "\n";

	if (address.app != 0)
		out << "Appartment: " << address.app << "\n";

	return out;
}
