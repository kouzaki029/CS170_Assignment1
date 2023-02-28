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
    bool done = false;

    while(!done)
    {
        if(day == 0)
        {
            if(errorCount == 3)
            {
                cout << "\nYou entered day and/or month incorrectly three times.\nProgram closing...\n";
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
        else if(month == 0)
        {
            if(errorCount == 3)
            {
                cout << "\nYou entered day and/or month incorrectly three times.\nProgram closing...\n";
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
        else if(year == 0)
        {
            cout << "Please enter a number for year (e.g., 03): ";
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
        else if(day > 0 && month > 0 && year > 0)
        {
            cout << "good job!\n";
        }
        else
            done = true;
    }

    return 0;
}
