#pragma once
#include<string>
#include<iostream>
#include"Contact.h"

using std::cout;

class AddContactProperties
{
public:
	static void birthday(Contact& contact);

	static void phoneNumber(Contact& contact);

	static void address(Contact& contact);

	static void car(Contact& contact);

	static void company(Contact& contact);
};

