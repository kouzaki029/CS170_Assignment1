/*
    program does not account the Julian calendar; in other words anything before 1582 will be off because it was a part of the Julian calendar and not the Gregorian
*/
#include <iostream>
#include<limits>
using std::cout, std::cin, std::numeric_limits, std::streamsize;

int main()
{
    int errorCount = 0;
    int userEntry = 0;
    bool done = false;
    //m1, d1, and y1 are for the newer date
    int m1 = 0;
    int d1 = 0;
    int y1 = 0;
    //m2, d2, and y2 are for the older date
    int m2 = 0;
    int d2 = 0;
    int y2 = 0;

    while (!done)
    {
        //retrieving first Date
        if (d1 == 0)
        {
            if (errorCount == 3)
            {
                cout << "\nYou entered the day and/or month incorrectly three times.\nProgram closing...\n";
                break;
            }
            cout << "Please enter a number for d1 (e.g., 02): ";
            cin >> userEntry;
            if (cin.fail() || userEntry == 0 || userEntry > 31)
            {
                ++errorCount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry.\n";
            }
            else
            {
                d1 = userEntry;
            }
        }
        else if (m1 == 0)
        {
            if (errorCount == 3)
            {
                cout << "\nYou entered the day and/or month incorrectly three times.\nProgram closing...\n";
                break;
            }
            cout << "Please enter a number for m1 (e.g., 03): ";
            cin >> userEntry;
            if (cin.fail() || userEntry == 0 || userEntry > 12)
            {
                ++errorCount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry.\n";
            }

            //validating the correct number of days per month
            if (d1 == 31 && (userEntry == 2 || userEntry == 4 || userEntry == 6 || userEntry == 9 || userEntry == 11))
            {
                ++errorCount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry. There are not 31 days in ";
                if (userEntry == 2)
                    cout << "Feb.\n";
                else if (userEntry == 4)
                    cout << "Apr.\n";
                else if (userEntry == 6)
                    cout << "Jun.\n";
                else if (userEntry == 9)
                    cout << "Aug.\n";
                else if (userEntry == 11)
                    cout << "Nov.\n";
            }
            else if (d1 == 30 && userEntry == 2)
            {
                ++errorCount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry. There are not 30 days in Feb.\n";
            }

            else
            {
                m1 = userEntry;
            }
        }
        else if (y1 == 0)
        {
            cout << "Please enter a number for y1 (e.g., 03): ";
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
                y1 = userEntry;
            }
        }

        //retrieving second Date
        else if (d2 == 0)
        {
            if (errorCount == 3)
            {
                cout << "\nYou entered the day and/or month incorrectly three times.\nProgram closing...\n";
                break;
            }
            cout << "Please enter a number for d2 (e.g., 02): ";
            cin >> userEntry;
            if (cin.fail() || userEntry == 0 || userEntry > 31)
            {
                ++errorCount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry.\n";
            }
            else
            {
                d2 = userEntry;
            }
        }
        else if (m2 == 0)
        {
            if (errorCount == 3)
            {
                cout << "\nYou entered the day and/or month incorrectly three times.\nProgram closing...\n";
                break;
            }
            cout << "Please enter a number for m2 (e.g., 03): ";
            cin >> userEntry;
            if (cin.fail() || userEntry == 0 || userEntry > 12)
            {
                ++errorCount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry.\n";
            }
            else
            {
                m2 = userEntry;
            }
        }
        else if (y2 == 0)
        {
            cout << "Please enter a number for y2 (e.g., 03): ";
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
                y2 = userEntry;
                done = true;
            }
        }
    }


    while (errorCount < 3)
    {
        std::cout << "newerDate:\t" << m1 << "/" << d1 << "/" << y1 << "\n";
        std::cout << "olderDate:\t" << m2 << "/" << d2 << "/" << y2 << "\n";

        //the day, month and year are different
        int dayDifference = d1 - d2;

        int monthDifference = 0;
        int yearDifference = 0;
        int calculatingDays = 0;

        //days are the same, but the month and year are different
        if (m1 > m2 || m1 == m2) //e.g., newDate = 11/23/2020 and olderDate = 1/23/2020
        {
            while (m1 > m2)
            {
                --m1;
                if (m1 == 1)
                {
                    monthDifference += 31;
                }
                if (m1 == 2)
                {
                    if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
                    {
                        monthDifference += 29;
                    }
                    else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
                    {
                        monthDifference += 29;
                    }
                    else
                    {
                        monthDifference += 28;
                    }
                }
                if (m1 == 3)
                {
                    monthDifference += 31;
                }
                if (m1 == 4)
                {
                    monthDifference += 30;
                }
                if (m1 == 5)
                {
                    monthDifference += 31;
                }
                if (m1 == 6)
                {
                    monthDifference += 30;
                }
                if (m1 == 7)
                {
                    monthDifference += 31;
                }
                if (m1 == 8)
                {
                    monthDifference += 31;
                }
                if (m1 == 9)
                {
                    monthDifference += 30;
                }
                if (m1 == 10)
                {
                    monthDifference += 31;
                }
                if (m1 == 11)
                {
                    monthDifference += 30;
                }
                if (m1 == 12)
                {
                    monthDifference += 31;
                }
            }
        }
        else //e.g., newerDate = 1/23/2020 and olderDate = 8/23/2019
        {
            --y1;
            while (m1 != m2)
            {
                --m1;
                if (m1 == 1)
                {
                    monthDifference += 31;
                    m1 = 12;
                }
                if (m1 == 2)
                {
                    if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
                    {
                        monthDifference += 29;
                    }
                    else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
                    {
                        monthDifference += 29;
                    }
                    else
                    {
                        monthDifference += 28;
                    }
                }
                if (m1 == 3)
                {
                    monthDifference += 31;
                }
                if (m1 == 4)
                {
                    monthDifference += 30;
                }
                if (m1 == 5)
                {
                    monthDifference += 31;
                }
                if (m1 == 6)
                {
                    monthDifference += 30;
                }
                if (m1 == 7)
                {
                    monthDifference += 31;
                }
                if (m1 == 8)
                {
                    monthDifference += 31;
                }
                if (m1 == 9)
                {
                    monthDifference += 30;
                }
                if (m1 == 10)
                {
                    monthDifference += 31;
                }
                if (m1 == 11)
                {
                    monthDifference += 30;
                }
                if (m1 == 12)
                {
                    monthDifference += 31;
                }
            }
        }


        //days and months are the same, but the year is different
        while (y1 != y2)
        {
            if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
            {
                yearDifference += 366;
            }
            else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
            {
                yearDifference += 366;
            }
            else
            {
                yearDifference += 365;
            }
            --y1;
        }
        
        calculatingDays = dayDifference + monthDifference + yearDifference;

        std::cout << "\tdayDifference = " << dayDifference << "\n";
        std::cout << "\tmonthDifference = " << monthDifference << "\n";
        std::cout << "\tyearDifference = " << yearDifference << "\n";
        std::cout << "\tcalculatingDays = " << calculatingDays << "\n";
        errorCount = 3;
    }

        return 0;
}
