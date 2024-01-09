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

private:
	int day, month, year;
};