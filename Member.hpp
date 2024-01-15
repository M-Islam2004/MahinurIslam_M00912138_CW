#include <string>
using namespace std;

// Forward declaration of the Person class
class Person;

// Member class, inheriting from the Person class
class Member : public Person
{
	int memberID;
	vector<int> bookLoaned;

public:
	// Default constructor
	Member()
	{
	}

	// Parameterized constructor
	Member(int memberID, const std::string& name, const std::string& address, const std::string& email)
		: Person(name, address, email), memberID(memberID) {}

	// Getter for member ID
	int getMemberID()
	{
		return memberID;
	}

	// Getter for books borrowed by the member
	vector<int> getBooksBorrowed()
	{
		return bookLoaned;
	}

	// Function to set a book as borrowed by the member
	void setBooksBorrowed(int bookID)
	{
		bookLoaned.push_back(bookID);
		cout << "Book ID:" << bookID << " issued to member ID: " << memberID << "\n";
	}

	// Function to return a borrowed book
	void returnBook(int bookID)
	{
		auto position = std::find(bookLoaned.begin(), bookLoaned.end(), bookID);

		if (position != bookLoaned.end())
		{
			bookLoaned.erase(position);
		}
		else
		{
			cout << "Book not loaned by the member." << endl;
		}
	}

    // Function to show member details
    string ShowDetail()
    {
        return "Name: " + getName() + "\nAddress: " + getAddress() + "\nEmail: " + getEmail() + "\n";
    }
};