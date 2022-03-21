#pragma once
#include<iostream>

class Car
{
private:
	std::string brand;
	std::string model;
	std::string number;

public:
	Car(const std::string& brand = "", const std::string& model = "", const std::string& number = "");

	//gets
	inline const std::string& getBrand() const
	{
		return this->brand;
	}

	inline const std::string& getModel() const
	{
		return this->model;
	}

	inline const std::string& getNumber() const
	{
		return this->number;
	}

	//sets
	void setBrand(const std::string& brand);
	void setModel(const std::string& model);
	void setNumber(const std::string& number);

	friend std::ostream& operator<<(std::ostream& out, const Car& car);
};

