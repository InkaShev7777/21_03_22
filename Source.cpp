#include<conio.h>
#include<Windows.h>
#include"ProviderContacts.h"


int main()
{
	ContactList list("database.txt");

	do
	{
		system("cls");
		Menu::showMainMenu();

		char ch = _getch();
		size_t i = 0;

		if (ch == '0')
			break;

		switch (ch)
		{
		case '1':
			system("cls");
			list.showAllContacts();
			system("pause");
			break;

		case '2':
			if (Actions::addContact(list))
			{
				cout << "Added...\n";
				Sleep(2000);
			}
			else
			{
				cout << "This contact is already at the list\n";
				Sleep(2000);
			}
			break;

		case '3':
			i = Actions::deleteContact(list);
			
			if (i > 0)
			{
				cout << "Deleted " << i << " contacts\n";
				Sleep(2000);
			}

			break;

		case '4':
			Actions::findContact(list);
			system("pause");

			break;

		case '5':
			Actions::sort(list);
			system("cls");
			list.showAllContacts();
			system("pause");

			break;

		case '6':
			if (list.save())
			{
				cout << "Saved...\n";
			}
			else
			{
				cout << "Error\n";
			}

			Sleep(2000);
			break;
		}
	
	} while (true);
}



