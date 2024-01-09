#include <string>
using namespace std;
class Member : public Person
{
	int memberID;
	vector<int> bookLoaned;
public:
	Member() 
	{
	}
	Member(int memberID, const std::string& name, const std::string& address, const std::string& email)
		: Person(name, address, email), memberID(memberID) {}

	int getMemberID()
	{
		return memberID;
	}

	vector<int> getBooksBorrowed()
	{
		return bookLoaned;
	}

	void setBooksBorrowed(int bookID)
	{
		bookLoaned.push_back(bookID);
        cout << "Book ID:" << bookID << " issued to member ID: " << memberID << "\n";
	}

	void returnBook(int bookID)
	{
		auto position = std::find(bookLoaned.begin(), bookLoaned.end(), bookID);

		if (position != bookLoaned.end()) {
			bookLoaned.erase(position);
		}
		else {
			cout << "Book not loaned by member." << endl;
		}
	}

    string ShowDetail()
    {
        return "Name: " + getName() + "\nAddress: " + getAddress() + "\nEmail: " + getEmail() + "\n";
    }
};