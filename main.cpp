#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>

// Include headers
#include "Person.hpp"
#include "Date.hpp"
#include "Member.hpp"
#include "Book.hpp"
#include "Librarian.hpp"

using namespace std;

void ShowMenu()
{
	// Output of menu screen
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
	// Create an instance of the Librarian class
	Librarian librarian;

	// Read books information from a CSV file and display the result
	cout << librarian.readBooksFromCSV(books) << endl;

	// Variables to store user input for member and book IDs
	int memberID, bookID;

	// Main loop for the menu
	while (1)
	{
		// Display the menu
		ShowMenu();

		// User input processing
		std::string userInput;
		int intValue;
		std::getline(std::cin, userInput);

		try {
			size_t pos; // to check if the entire string was used
			intValue = std::stoi(userInput, &pos);

			if (pos == userInput.length()) {
				// Proceed with the selected option
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

		// Switch-case to handle different menu options
		switch (intValue)
		{
		case 1:
			// Option to add a new member
			librarian.addMember();
			break;
		case 2:
			// Option to issue a book to a member
			cout << "Enter member ID : ";
			cin >> memberID;

			cout << "Enter book ID : ";
			cin >> bookID;
			cin.ignore();
			librarian.issueBook(memberID, bookID);
			break;
		case 3:
			// Option to return a book
			cout << "Enter member ID : ";
			cin >> memberID;

			cout << "Enter book ID : ";
			cin >> bookID;
			cin.ignore();
			librarian.returnBook(memberID, bookID);
			break;
		case 4:
			// Option to list books borrowed by a member
			cout << "Enter member ID : ";
			cin >> memberID;
			cin.ignore();
			librarian.listBooksBorrowed(memberID);
			break;
        case 5:
            // Option to exit the program
            return 0;
		default:
			cout << "Wrong Option. " << endl;
			break;
		}
	}
	
	return 0;
}