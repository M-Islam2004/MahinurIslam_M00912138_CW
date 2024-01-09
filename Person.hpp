#include <iostream>
#include <string.h>
using namespace std;
class Person
{

	string name;
	string address;
	string email;
public:
	Person()
	{
	}

	Person(string n, string a, string e)
	{
		name = n;
		address = a;
		email = e;
	}

	string getName()
	{
		return name;
	}

	void setName(string n)
	{
		name = n;
	}

	string getAddress()
	{
		return address;
	}

	void setAddress(string a)
	{
		address = a;
	}

	string getEmail()
	{
		return email;
	}

	void setEmail(string e)
	{
		email = e;
	}

};