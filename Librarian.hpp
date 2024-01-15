// Declaration of global variables
map<int, Member> members;
map<int, Book> books;
int memberID = 0;

// Librarian class, inheriting from the Person class
class Librarian : public Person
{
	int staffID;
	int salary;

public:
	// Default constructor
	Librarian()
	{
	}

	// Parameterized constructor
	Librarian(int staffID, const std::string& name, const std::string& address, const std::string& email, int salary)
		: Person(name, address, email), staffID(staffID), salary(salary) {}

	// Function to add a new member
	void addMember()
	{
		std::cout << "Enter member details:\n";
		std::string name, address, email;
		std::cout << "Name: ";
		std::getline(std::cin, name);
		if (name == "")
		{
			cout << "Name cannot be empty.\n";
			return;
		}
		std::cout << "Address: ";
		std::getline(std::cin, address);
		if (address.empty())
		{
			cout << "Address cannot be empty.\n";
			return;
		}
		std::cout << "Email: ";
		std::getline(std::cin, email);
		if (email.empty())
		{
			cout << "Email cannot be empty.\n";
			return;
		}
		Member member(++memberID, name, address, email);

		members[memberID] = member;

		std::cout << "\nNew member added:\n";
		std::cout << member.ShowDetail();
	}

	// Function to issue a book to a member
	void issueBook(int memberID, int bookID)
	{
		map<int, Member>::iterator itr = members.find(memberID);
		if (itr != members.end())
		{
			map<int, Book>::iterator itr2 = books.find(bookID);

			if (itr2 != books.end())
			{
				std::time_t currentTime = std::time(nullptr);
				currentTime = currentTime + (3 * 24 * 60 * 60);
				std::tm* localTime = std::localtime(&currentTime);

				int year = localTime->tm_year + 1900;
				int month = localTime->tm_mon + 1;
				int day = localTime->tm_mday;

				Date date(day, month, year);

				itr->second.setBooksBorrowed(bookID);
				itr2->second.borrowBook(&itr->second, date);

				cout << "Book ID: " << bookID << " issued to member ID:" << memberID << "\n\n";
			}
			else
			{
				cout << "Book with ID: " << bookID << " is not found." << endl;
			}
		}
		else
		{
			cout << "Member with ID: " << memberID << " is not found." << endl;
		}
	}

	// Function to calculate the fine based on the due date and returned date
	int CalcFine(Date date)
	{
		Date currentDate;
		currentDate.getUserInputDate();

		int year = currentDate.getYear();
		int month = currentDate.getMonth();
		int day = currentDate.getDay();

		Date dueDate = date;

		std::tm date1 = {};
		date1.tm_year = year - 1900;
		date1.tm_mon = month - 1; // Adjust month value to be in the range [0, 11]
		date1.tm_mday = day;

		std::tm date2 = {};
		date2.tm_year = dueDate.getYear() - 1900;
		date2.tm_mon = dueDate.getMonth() - 1; // Adjust month
		date2.tm_mday = dueDate.getDay();

		std::time_t time1 = std::mktime(&date1);
		std::time_t time2 = std::mktime(&date2);

		if (time1 == -1 || time2 == -1)
		{
			// Handle error in mktime
			std::cerr << "Error in mktime" << std::endl;
			return -1; // Indicate error
		}

		std::time_t timeDiff = time2 - time1;
		int days = timeDiff / (60 * 60 * 24);

		cout << "Due Date: " << dueDate.getYear() << " " << dueDate.getMonth() << " " << dueDate.getDay() << endl;
		cout << "Returned Date: " << currentDate.getYear() << " " << currentDate.getMonth() << " " << currentDate.getDay() << endl;
		return days;
	}

	// Function to return a borrowed book
	void returnBook(int memberID, int bookID)
	{
		map<int, Member>::iterator itr = members.find(memberID);
		if (itr != members.end())
		{
			map<int, Book>::iterator itr2 = books.find(bookID);

			if (itr2 != books.end())
			{
				vector<int> loanedBooks = itr->second.getBooksBorrowed();

				auto position = std::find(loanedBooks.begin(), loanedBooks.end(), bookID);

				if (position != loanedBooks.end())
				{
					int days = CalcFine(itr2->second.getDueDate());
					if (days < 0)
					{
						cout << "Fine: " << days * (-1) << endl;
					}
					else
					{
						cout << "The book has been returned on time." << endl;
						cout << "Due Date: " << to_string(itr2->second.getDueDate().getDay()) << "/" << to_string(itr2->second.getDueDate().getMonth()) << "/" << to_string(itr2->second.getDueDate().getYear()) << endl;
					}
					itr->second.returnBook(bookID);
					itr2->second.returnBook(memberID);

					cout << "Book returned" << endl;
				}
				else
				{
					cout << "Book ID: " << bookID << " not borrowed by member ID: " << memberID << endl;
				}
			}
			else
			{
				cout << "Book with ID: " << bookID << " is not found." << endl;
			}
		}
		else
		{
			cout << "Member with ID: " << memberID << " is not found." << endl;
		}

		cout << endl;
	}

	// Function to list books borrowed by a member
	void listBooksBorrowed(int memberID)
	{
		map<int, Member>::iterator itr = members.find(memberID);
		if (itr != members.end())
		{
			vector<int> booksBorrowed = itr->second.getBooksBorrowed();
			if (booksBorrowed.size() > 0)
			{
				for (unsigned int a = 0; a < booksBorrowed.size(); a++)
				{
					map<int, Book>::iterator itr2 = books.find(booksBorrowed[a]);

					if (itr2 != books.end())
					{
						cout << a + 1 << ": " << itr2->second.getBookName() << endl;
					}
				}
			}
			else
			{
				cout << "No books borrowed from the member." << endl;
			}
		}
		else
		{
			cout << "Member with ID: " << memberID << " is not found." << endl;
		}

		cout << endl;
	}

	// Getter for salary
	int GetSalary()
	{
		return salary;
	}

	// Setter for salary
	void SetSalary(int s)
	{
		salary = s;
	}

	// Getter for staff ID
	int GetStaffID()
	{
		return staffID;
	}

	// Setter for staff ID
	void SetStaffID(int s)
	{
		staffID = s;
	}

	// Function to read books from a CSV file
	string readBooksFromCSV(map<int, Book>& books)
	{
		ifstream file("library_books.csv");
		if (!file.is_open())
		{
			return "Error opening file: library_books.csv";
		}

		string line;
		getline(file, line);
		while (getline(file, line))
		{
			stringstream ss(line);
			string token;

			int bookID;
			string bookName, pageCount, authorFirstName, authorLastName, type;
			getline(ss, token, ',');
			bookID = std::stoi(token);

			getline(ss, bookName, ',');
			getline(ss, pageCount, ',');
			getline(ss, authorFirstName, ',');
			getline(ss, authorLastName, ',');
			getline(ss, type, ',');

			Book book(bookID, bookName, authorFirstName, authorLastName, type);

			books[bookID] = book;
		}
		file.close();
		return "File successfully read library_books.csv";
	}
};