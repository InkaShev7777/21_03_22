#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include"ContactList.h"
#include"AddContactProperties.h"
#include"Menu.h"

class Actions
{
public:
	static bool addContact(ContactList& list);

	static size_t deleteContact(ContactList& list);

	static void findContact(const ContactList& list);

	static void sort(ContactList& list);

	static void showContacts(const vector<pair<Contact, Date>>& contacts);

};

