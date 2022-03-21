#include "Car.h"

Car::Car(const std::string& brand, const std::string& model, const std::string& number) :brand{ brand }, model{ model }, number{ number }
{
}

void Car::setBrand(const std::string& brand)
{
	this->brand = brand;
}

void Car::setModel(const std::string& model)
{
	this->model = model;
}

void Car::setNumber(const std::string& number)
{
	this->number = number;
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
	if (car.brand != "")
		out << "Brand: " << car.brand << "\n";

	if (car.model != "")
		out << "Model: " << car.model << "\n";

	if (car.number != "")
		out << "Number: " << car.number << "\n";

	return out;
}
