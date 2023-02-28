#include <iostream>
#include<limits>
using std::cout, std::cin, std::numeric_limits, std::streamsize;

int main()
{
    int firstDAY = 0;
    int firstMONTH = 0;
    int firstYEAR = 0;
    int secondDAY = 0;
    int secondMONTH = 0;
    int secondYEAR = 0;
    int errorCount = 0;
    int userEntry = 0;
    bool done = false;

    while(!done)
    {
        //retrieving first Date
        if(firstDAY == 0)
        {
            if(errorCount == 3)
            {
                cout << "\nYou entered the day and/or month incorrectly three times.\nProgram closing...\n";
                break;
            }
            cout << "Please enter a number for firstDAY (e.g., 02): ";
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
                firstDAY = userEntry;
                //cout << "firstDAY = " << firstDAY << "\n";
            }
        }
        else if(firstMONTH == 0)
        {
            if(errorCount == 3)
            {
                cout << "\nYou entered the day and/or month incorrectly three times.\nProgram closing...\n";
                break;
            }
            cout << "Please enter a number for firstMONTH (e.g., 03): ";
            cin >> userEntry;
            if (cin.fail() || userEntry == 0 || userEntry > 12)
            {
                ++errorCount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry.\n";
            }

            //validating the correct number of days per month
            if(firstDAY == 31 && (userEntry == 2 || userEntry == 4 || userEntry == 6 || userEntry == 9 || userEntry == 11))
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
            else if(firstDAY == 30 && userEntry == 2)
            {
                ++errorCount;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry. There are not 30 days in Feb.\n";
            }

            else
            {
                firstMONTH = userEntry;
                //cout << "firstMONTH = " << firstMONTH << "\n";
            }
        }
        else if(firstYEAR == 0)
        {
            cout << "Please enter a number for firstYEAR (e.g., 03): ";
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
                firstYEAR = userEntry;
                //cout << "firstYEAR = " << firstYEAR << "\n";
            }
        }

        //retrieving second Date
        else if(secondDAY == 0)
        {
            if(errorCount == 3)
            {
                cout << "\nYou entered the day and/or month incorrectly three times.\nProgram closing...\n";
                break;
            }
            cout << "Please enter a number for secondDAY (e.g., 02): ";
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
                secondDAY = userEntry;
                //cout << "secondDAY = " << secondDAY << "\n";
            }
        }
        else if(secondMONTH == 0)
        {
            if(errorCount == 3)
            {
                cout << "\nYou entered the day and/or month incorrectly three times.\nProgram closing...\n";
                break;
            }
            cout << "Please enter a number for secondMONTH (e.g., 03): ";
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
                secondMONTH = userEntry;
                //cout << "secondMONTH = " << secondMONTH << "\n";
            }
        }
        else if(secondYEAR == 0)
        {
            cout << "Please enter a number for secondYEAR (e.g., 03): ";
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
                secondYEAR = userEntry;
                //cout << "secondYEAR = " << secondYEAR << "\n";
            }
        }

        //calculate the difference in days
        else if(firstDAY > 0 && firstMONTH > 0 && firstYEAR > 0 && secondDAY > 0 && secondMONTH > 0 && secondYEAR > 0)
        {
            if(firstYEAR % 4 == 0 && firstYEAR % 100 == 0 && firstYEAR % 400 == 0)
            {
                //std::cout << "firstYEAR (i.e., " << firstYEAR << ") is a leap century.\n";
            }
            else if(firstYEAR % 4 == 0 && firstYEAR % 100 != 0 && firstYEAR % 400 != 0)
            {
                //std::cout << "firstYEAR (i.e., " << firstYEAR << ") is a leap year.\n";
            }
            else
            {
                //std::cout << "firstYEAR (i.e., " << firstYEAR << ") is a not leap year.\n";
            }
        }

    }

    return 0;
}
