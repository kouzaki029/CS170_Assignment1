#include <iostream>
#include <limits>
using std::cout, std::cin, std::streamsize, std::numeric_limits;

int main()
{
    long userEntry = 0;
    int sum = 0;
    int digitCount = 0;
    bool calculating = true;
    int evenPlace = 0;
    int oddPlace = 0;

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
    calculating = true;

    //verifying the 8-digit number the user entered is a valid credit-card number
    while(calculating)
    {
        int userNumber = userEntry;
        int base = 10;
        int exponent = digitCount;
        int result = 1;
        int doubleMe = 0; //call me doubleMe
        int extractDigit = 0;
        int verifyOdd = 0;
        for(int i = 1; i < exponent; ++i)
        {
            //base-case
            if(i == 1)
            {
                evenPlace += (userNumber % base);
                /*DEBUG PURPOSES: cout << "evenPlace += (" << userNumber << " % " << base << ") or "<< (userNumber % base) << "\n";*/
            }
            //even-exponent
            if(i % 2 == 0)
            {
                result *= base;
                userNumber /= base;
                /*DEBUG PURPOSES: std::cout << userEntry << " / " << base << "^" << i << " = " << userNumber << "\n";*/
                evenPlace += (userNumber % base);
                /*DEBUG PURPOSES: cout << "evenPlace += (" << userNumber << " % " << base << ") or "<< (userNumber % base) << "\n";*/
            }
            //odd-exponent
            else
            {
                result *= base;
                userNumber /= base;
                /*DEBUG PURPOSES: std::cout << userEntry << " / " << base << "^" << i << " = " << userNumber << "\n";*/
                oddPlace += (userNumber % base);
                /*DEBUG PURPOSES: cout << "oddPlace += (" << userNumber << " % " << base << ") or "<< (userNumber % base) << "\n";*/
                doubleMe = (userNumber % base) * 2;
                /*DEBUG PURPOSES:cout << "idk1 = " << idk1 << "\n";*/
                while(doubleMe != 0)
                {
                    extractDigit = (doubleMe % base);
                    /*DEBUG PURPOSES: cout << "extractDigit = (" << idk1 << " % " << base << ") or " << extractDigit << "\n";*/
                    doubleMe /= base;
                    /*DEBUG PURPOSES: cout << "idk1 /= " << base << ") or " << idk1 << "\n";*/
                    verifyOdd += extractDigit;
                }
            }
        }
        /*DEBUG PURPOSES: cout << "verifyOdd = " << verifyOdd << "\n";*/
        sum = evenPlace + oddPlace;
        /*DEBUG PURPOSES: cout << "sum = (" << evenPlace << " + " << oddPlace << ") or " << sum << "\n";*/

        if(sum % base == 0)
        {
            cout << userEntry << " is a valid credit-card number.\n";
        }
        else
        {
            cout << userEntry << " is NOT a valid credit-card number.\n";
        }
        calculating = false;
    }

    return 0;
}
