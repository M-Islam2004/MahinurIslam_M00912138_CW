#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>

#include "Person.hpp"
#include "Date.hpp"
#include "Member.hpp"
#include "Book.hpp"
#include "Librarian.hpp"

using namespace std;



void ShowMenu()
{
	cout << "1: Add New Member." << endl;
	cout << "2: Issue book to member." << endl;
	cout << "3: Return book." << endl;
	cout << "4: List books borrowed." << endl;
    cout << "5: Exit." << endl;
	cout << "Select option. " << endl;
	cout << ">> ";
}
int main()
{
	Librarian librarian;
	cout << librarian.readBooksFromCSV(books) << endl;
	int memberID, bookID;
	while (1)
	{
		ShowMenu();
		std::string userInput;
		int intValue;
		std::getline(std::cin, userInput);

		try {
			size_t pos; // to check if the entire string was used
			intValue = std::stoi(userInput, &pos);

			if (pos == userInput.length()) {
			
			}
			else {
				std::cout << "Invalid input. Please enter a valid integer." << std::endl;
			}
		}
		catch (const std::invalid_argument& e) {
			std::cout << "Invalid input. Please enter a valid integer." << std::endl;
		}
		catch (const std::out_of_range& e) {
			std::cout << "Number out of range. Please enter a smaller integer." << std::endl;
		}

		switch (intValue)
		{
		case 1:
			librarian.addMember();
			break;
		case 2:
			
			cout << "Enter member ID : ";
			cin >> memberID;

			cout << "Enter book ID : ";
			cin >> bookID;
			cin.ignore();
			librarian.issueBook(memberID, bookID);
			break;
		case 3:
			cout << "Enter member ID : ";
			cin >> memberID;

			cout << "Enter book ID : ";
			cin >> bookID;
			cin.ignore();
			librarian.returnBook(memberID, bookID);
			break;
		case 4:
			cout << "Enter member ID : ";
			cin >> memberID;
			cin.ignore();
			librarian.listBooksBorrowed(memberID);
			break;
        case 5:
            return 0;
		default:
			cout << "Wrong Option. " << endl;
			break;
		}
		
	}
	return 0;
}