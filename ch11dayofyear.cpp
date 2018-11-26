// --------------------------------------------------------------------------------------------------
// - Make a program that will input the day and the month of a year by using any number in the year -
// - BY: Nathaniel Barrera                                                                          -
// --------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>

// One Global variable
const int NUM_MONTHS = 12;

// Class day Of year
class DayOfYear {
private:
    const static std::string monthOfYear[NUM_MONTHS];
    const static int daysInYear[NUM_MONTHS];
    const static int daysInMonth[NUM_MONTHS];

    std::string month;            // To hold a month name
    int day;                    // To hold a day
    int arrayIdx;            // Stores an array index

public:
    // Constructors
    DayOfYear() {}
    DayOfYear(int d);
    DayOfYear(std::string, int);

    // Member functions
    bool isMonthName(std::string);
    void setMonth(int);
    void helpIncrement();
    void helpDecrement();
    void print();
    std::string getMonth() const { return month; }
    int getDay() const { return day; }
    DayOfYear operator++();
    DayOfYear operator++(int);
    DayOfYear operator--();
    DayOfYear operator--(int);
};

// Definition of const static array member holding month names
const std::string DayOfYear::monthOfYear[] = {"January", "February", "March", "April", "May", "June", "July",
                                              "August", "September", "October", "November", "December"};

// MAIN FUNCTION
int main() {
    DayOfYear d = 2;
    d.print();
    d = 365;
    d.print();
    d = 32;
    d.print();

    d++;
    d.print();

    d = 365;
    ++d;
    d.print();
    d = 1;
    --d;
    d.print();

    d = 32;
    d--;
    d.print();

    DayOfYear e("December", 31);
    e.print();

    DayOfYear f("July", 32);

    return 0;
}

// Definitions
// Definition of const static array member holding a range of days
const int DayOfYear::daysInYear[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
const int DayOfYear::daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
                DayOfYear::DayOfYear() : int
    The constructor accepts an integer as its argument. If the
    value passed to it is invalid, a message is output, and
    the program exits with an error code.
*/

DayOfYear::DayOfYear(int d) {
    if (d >= 1 && d <= 365) {
        setMonth(d);

        if (d > 31) {
            d %= daysInYear[arrayIdx - 1];
        }
        day = d;
    } else {
        std::cout << "\nDATE ERROR: A normal year has at least 1, and no more than, 365 days.\n";
        exit(0);
    }
}

/*
                DayOfYear::DayOfYear() : string, int
    The constructor accepts a string and and integer as
    arguments. If the value passed to it is invalid, a message
    is output, and the program exits with an error code. If
    the values are valid, they are copied to the appropriate
    member variables.
*/

DayOfYear::DayOfYear(std::string m, int d) {
    if (isMonthName(m) == true) {
        month = m;
    } else {
        std::cout << "\nDATE ERROR: " << m << " does not exist\n";
        exit(0);
    }

    if (d >= 1 && d <= daysInMonth[arrayIdx]) {
        day = d;
    } else {
        std::cout << "\nDATE ERROR: " << month << " starts with the 1, and it has "
                  << daysInMonth[arrayIdx] << " days.\n";
        exit(0);
    }
}

/*
            DayOfYear::setMonth() : int
    The function accepts an integer holding a day value in the
    range of 1 through 365. Based on this value, the month of
    year and arrayIdx members are set.
*/

void DayOfYear::setMonth(int d) {
    bool isFound = false;

    for (int count = 0; count < NUM_MONTHS && isFound != true; count++) {
        if (d <= daysInYear[count]) {
            arrayIdx = count;
            month = monthOfYear[count];

            isFound = true;
        }
    }
}

/*
            DayOfYear::isMonthName() : string
    The month name passed to this function is compared against
    the values in the monthOfYear array. If it is found, the
    function exits and returns true. Else, false is returned.
*/

bool DayOfYear::isMonthName(std::string m) {
    for (int count = 0; count < NUM_MONTHS; count++) {
        if (m == monthOfYear[count]) {
            arrayIdx = count;
            return true;
        }
    }
    return false;
}

/*
            DayOfYear::helpIncrement
    This function increments day and month if the conditions
    in the if/else statement are met.
*/

void DayOfYear::helpIncrement() {
    if (month == "December" && day == 31) {
        arrayIdx = 0;
        month = monthOfYear[arrayIdx];
        day = 0;
    } else if (day == daysInMonth[arrayIdx]) {
        month = monthOfYear[++arrayIdx];
        day = 0;
    }
}

/*
            DayOfYear::helpIncrement
    This function decrements day and month if the conditions
    in the if/else statement are met.
*/

void DayOfYear::helpDecrement() {
    if (month == "January" && day == 1) {
        arrayIdx = 11;
        month = monthOfYear[arrayIdx];
        day = 31;
    } else {
        month = monthOfYear[--arrayIdx];
        day = daysInMonth[arrayIdx];
    }
}

/*
            DayOfYear &DayOfYear::operator++() : Prefix ++
*/

DayOfYear DayOfYear::operator++() {
    helpIncrement();
    ++day;

    return *this;
}


/*
            DayOfYear DayOfYear::operator++(int) : Postfix ++
*/

DayOfYear DayOfYear::operator++(int) {
    DayOfYear temp = *this;

    helpIncrement();
    day++;

    return temp;
}

/*
            DayOfYear &DayOfYear::operator--() : Prefix --
*/

DayOfYear DayOfYear::operator--() {
    if (day == 1) {
        helpDecrement();
    }
    else {
        --day;
    }
    return *this;
}

/*
            DayOfYear DayOfYear::operator--(int) : Postfix --
*/

DayOfYear DayOfYear::operator--(int) {
    DayOfYear temp = *this;

    if (day == 1) {
        helpDecrement();
    } else {
        day--;
    }

    return temp;
}

/*
            DayOfYear::print()
    This function outputs the month and day to screen.
*/

void DayOfYear::print() {
    std::cout << "Day " << daysInYear[arrayIdx] << ": " << getMonth() << " " << getDay() << std::endl;
}