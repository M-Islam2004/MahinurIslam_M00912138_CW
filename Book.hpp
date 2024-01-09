class Book
{
	int bookID;
	string bookName;
	string authorFirstName;
	string authorLastName;
	string bookType;
	Date dueDate;
	Member* borrower;
public:
	Book()
	{
	}
	Book(int ID, string name, string firstName, string lastName, string type)
	{
		bookID = ID;
		bookName = name;
		authorFirstName = firstName;
		authorLastName = lastName;
		bookType = type;
	}

	int getBookID()
	{
		return bookID;
	}

	string getBookName()
	{
		return bookName;
	}

	string getAuthorFirstName()
	{
		return authorFirstName;
	}

	string getAuthorLastName()
	{
		return authorLastName;
	}

	Date getDueDate()
	{
		return dueDate;
	}

	void setDueDate(Date date)
	{
		dueDate = date;
	}

	void returnBook(int memberID)
	{
		if (memberID == borrower->getMemberID())
		{
			borrower = nullptr;
			dueDate.removeDate();
		}
		else
		{
			cout << "Book not borrowed by member ID: " << memberID << endl;
		}
		
	}

	void borrowBook(Member* member, Date date)
	{
		borrower = member;
		dueDate = date;
	}


};