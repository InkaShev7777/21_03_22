#include"ContactList.h"

int main()
{
	ContactList list("11.txt");
	//Contact c1("Ivan");
	//Contact c2(FullName("Petr", "Ivanovich"));
	//Contact c3(FullName("Semen", "Semenovich", "Semenov"), Date(12, 03, 2005));
	//c3.addCar(Car("Mazda", "C3", "AE00000"));
	//c3.addCar(Car("Mazda", "C5", "AE11111"));
	//c3.addCompany(Company("Razdolbaistroy", "Director"));
	//c3.addPhoneNumber("0955000000");
	//c3.addPhoneNumber("0951000000");
	//c3.addPhoneNumber("0631000000");
	//c3.setAddress(Address("UA", "Dnepr", "KM", "103", 12));
	//

	//list.addContact(c1, Date(12, 5, 2003));
	//list.addContact(c2, Date(10, 5, 2003));
	//list.addContact(c3, Date(12, 5, 2001));
	list.showAllContacts();
}