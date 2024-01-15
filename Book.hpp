class Book
{
    int bookID;                // Unique identifier for the book
    std::string bookName;      // Name of the book
    std::string authorFirstName; // Author's first name
    std::string authorLastName;  // Author's last name
    std::string bookType;         // Type or genre of the book
    Date dueDate;                // Due date for returning the book
    Member* borrower;            // Pointer to the member who borrowed the book

public:
    // Default constructor
    Book()
    {
    }

    // Parameterized constructor
    Book(int ID, std::string name, std::string firstName, std::string lastName, std::string type)
    {
        // Initialize variables with provided values
        bookID = ID;
        bookName = name;
        authorFirstName = firstName;
        authorLastName = lastName;
        bookType = type;
    }

    // Getter functions to retrieve the values of book information
    int getBookID()
    {
        return bookID;
    }

    std::string getBookName()
    {
        return bookName;
    }

    std::string getAuthorFirstName()
    {
        return authorFirstName;
    }

    std::string getAuthorLastName()
    {
        return authorLastName;
    }

    Date getDueDate()
    {
        return dueDate;
    }

    // Setter function to set the due date of the book
    void setDueDate(Date date)
    {
        dueDate = date;
    }

    // Method to return the book by a member
    void returnBook(int memberID)
    {
        // Check if the book was borrowed by the member with the provided ID
        if (memberID == borrower->getMemberID())
        {
            borrower = nullptr;        // Reset borrower to nullptr
            dueDate.removeDate();      // Remove the due date
        }
        else
        {
            std::cout << "Book not borrowed by member ID: " << memberID << std::endl;
        }
    }

    // Method to borrow the book
    void borrowBook(Member* member, Date date)
    {
        borrower = member;    // Set borrower to the provided member
        dueDate = date;       // Set the due date
    }
};