#include <iostream>
#include <limits>
using std::cout, std::cin, std::streamsize, std::numeric_limits;

int main()
{
    long userEntry = 0;
    int sum = 0;
    int digitCount = 0;
    bool calculating = true;
    int rememberMe = 0;
    int doubleMe = 0;

    cout << "Please enter an 8-digit number (e.g., 12345678): ";
    cin >> userEntry;
    long copyEntry = userEntry;

    //verifying user entered an 8-digit number
    while(calculating)
    {
        if((copyEntry / 10) != 0)
        {
            ++digitCount;
            copyEntry = (copyEntry / 10);
        }
        else
        {
            ++digitCount; //to accommodate off by 1
            calculating = false;
            copyEntry = userEntry;
        }
    }

    //verifying and correcting if the user did NOT supply an 8-digit number
    while(cin.fail() || digitCount != 8)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Entry.\n\n";
        cout << "Please enter an 8-digit number (e.g., 12345678): ";
        cin >> userEntry;
        copyEntry = userEntry;
        calculating = true;
        digitCount = 0;

        //verifying user entered an 8-digit number
        while(calculating)
        {
            if((copyEntry / 10) != 0)
            {
                ++digitCount;
                copyEntry = (copyEntry / 10);
            }
            else
            {
                ++digitCount; //to accommodate off by 1
                calculating = false;
            }
        }
        //EXTRA CREDIT: print out where the number is invalid
    }

    //verifying the 8-digit number the user entered is a valid credit-card number
    while(copyEntry != 0)
    {
        userEntry = 43589795;
        int myNumber = 43589795;
        int base = 10;
        int exponent = digitCount;
        int result = 1;
        for(int i = 1; i < exponent; ++i)
        {
            if(i == 1)
            {
                rememberMe += (myNumber % base);
                /*DEBUG PURPOSES: cout << "rememberMe += (" << myNumber << " % " << base << ") or "<< (myNumber % base) << "\n";*/
            }
            if(i % 2 == 0)
            {
                result *= base;
                myNumber /= base;
                std::cout << userEntry << " / " << base << "^" << i << " = "<< myNumber << " :)\n";
                rememberMe += (myNumber % base);
                /*DEBUG PURPOSES: cout << "rememberMe += (" << myNumber << " % " << base << ") or "<< (myNumber % base) << "\n";*/
            }
            else
            {
                result *= base;
                myNumber /= base;
                std::cout << userEntry << " / " << base << "^" << i << " = " << myNumber << "\n";
                doubleMe += (myNumber % base);
                /*DEBUG PURPOSES:*/ cout << "doubleMe += (" << myNumber << " % " << base << ") or "<< (myNumber % base) << "\n";
                //
            }
        }
        sum = rememberMe + doubleMe;
        cout << "sum = (" << rememberMe << " + " << doubleMe << ") or " << sum << "\n";
        copyEntry = 0;
    }

    return 0;
}
