#include <iostream>
#include<limits>
using std::cout, std::cin, std::numeric_limits, std::streamsize;

int main()
{
    int day = 0;
    int month = 0;
    int year = 0;
    int errorCount = 0;
    int userEntry = 0;

    while(true)
    {
        if(day == 0)
        {
            if(errorCount == 3)
            {
                cout << "You entered day and/or month incorrectly three times.\nProgram closing...\n";
                break;
            }
            cout << "Please enter a number for day (e.g., 02): ";
            cin >> userEntry;
            if (cin.fail() || userEntry == 0)
            {
                ++errorCount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry.\n";
            }
            else
            {
                day = userEntry;
                //cout << "day = " << day << "\n";
            }
        }
        if(month == 0)
        {
            if(errorCount == 3)
            {
                cout << "You entered day and/or month incorrectly three times.\nProgram closing...\n";
                break;
            }
            cout << "Please enter a number for month (e.g., 03): ";
            cin >> userEntry;
            if (cin.fail() || userEntry == 0)
            {
                ++errorCount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry.\n";
            }
            else
            {
                month = userEntry;
                //cout << "month = " << month << "\n";
            }
        }
        if(year == 0)
        {
            cout << "Please enter a number for month (e.g., 03): ";
            cin >> userEntry;
            if (cin.fail() || userEntry == 0)
            {
                ++errorCount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry.\n";
            }
            else
            {
                year = userEntry;
                //cout << "year = " << year << "\n";
            }
        }
    }

    return 0;
}
