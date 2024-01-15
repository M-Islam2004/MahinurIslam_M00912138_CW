#include <iostream>
#include <string.h>
using namespace std;

// Person class
class Person
{
	string name;
	string address;
	string email;

public:
	// Default constructor
	Person()
	{
	}

	// Parameterized constructor
	Person(string n, string a, string e)
	{
		name = n;
		address = a;
		email = e;
	}

	// Getter for name
	string getName()
	{
		return name;
	}

	// Setter for name
	void setName(string n)
	{
		name = n;
	}

	// Getter for address
	string getAddress()
	{
		return address;
	}

	// Setter for address
	void setAddress(string a)
	{
		address = a;
	}

	// Getter for email
	string getEmail()
	{
		return email;
	}

	// Setter for email
	void setEmail(string e)
	{
		email = e;
	}
};