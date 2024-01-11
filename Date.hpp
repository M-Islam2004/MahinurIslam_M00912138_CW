class Date {
public:
	Date()
	{}
	Date(int day, int month, int year) : day(day), month(month), year(year) {}

	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

	void removeDate()
	{
		day = month = year = 0;
	}

	void getUserInputDate() {
    std::cout << "Enter current date (YYYY MM DD): " << endl;
	cout << "year: ";
    std::cin >> year; 
	cout << "month: ";
	std::cin >> month;
	cout << "day: ";
	std::cin >> day;

	cin.ignore();
}

private:
	int day, month, year;
};