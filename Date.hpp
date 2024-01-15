class Date {
public:
    // Default constructor
	Date()
	{}

    // Parameterized constructor
	Date(int day, int month, int year) : day(day), month(month), year(year) {}

    // Getter functions for day, month, and year
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

    // Function to reset the date (set day, month, and year to 0)
	void removeDate()
	{
		day = month = year = 0;
	}

    // Function to get user input for the date
	void getUserInputDate() {
        std::cout << "Enter current date (YYYY MM DD): " << std::endl;
        
        // Prompt and input for the year
        std::cout << "year: ";
        std::cin >> year; 

        // Prompt and input for the month
        std::cout << "month: ";
        std::cin >> month;

        // Prompt and input for the day
        std::cout << "day: ";
        std::cin >> day;

        std::cin.ignore();  // Ignore any remaining characters in the input buffer
    }

private:
	int day, month, year;  // Private data members representing day, month, and year
};