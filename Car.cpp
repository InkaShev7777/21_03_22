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
	if (!car.brand.empty())
		out << "\tBrand: " << car.brand;

	if (!car.model.empty())
		out << "\tModel: " << car.model;

	if (!car.number.empty())
		out << "\tNumber: " << car.number;

	return out;
}

bool operator==(const Car& car_1, const Car& car_2)
{
	return car_1.brand == car_2.brand && car_1.model == car_2.model && car_1.number == car_2.number;
}

bool operator!=(const Car& car_1, const Car& car_2)
{
	return !(car_1 == car_2);
}
