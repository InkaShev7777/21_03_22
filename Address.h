#pragma once
#include<iostream>

class Address
{
private:
	std::string country;
	std::string city;
	std::string street;
	std::string house;
	int app;

public:
	Address(const std::string& country = "", const std::string& city = "", const std::string& street = "", const std::string& house = "", int app = 0);

	//gets
	inline const std::string& getCountry() const
	{
		return this->country;
	}

	inline const std::string& getCity() const
	{
		return this->city;
	}

	inline const std::string& getStreet() const
	{
		return this->street;
	}

	inline const std::string& getHouse() const
	{
		return this->house;
	}

	inline int getAppartment() const
	{
		return this->app;
	}

	//sets
	void setCountry(const std::string& country);
	void setCity(const std::string& city);
	void setStreet(const std::string& street);
	void setHouse(const std::string& house);
	void setAppartment(int app);

	friend std::ostream& operator<<(std::ostream& out, const Address& address);
};

