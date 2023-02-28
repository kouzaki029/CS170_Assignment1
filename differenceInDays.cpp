//if the days and month are the same between two dates

#include <iostream>

int main()
{
    int d1 = 01;
    int m1 = 23;
    int y1 = 2020;
    int d2 = 01;
    int m2 = 23;
    int y2 = 1899;

    // 01/23/2020 - 01/23/1899 = 44194 days
    // 01/23/2021 - 01/23/1899 = 44560 days
    // 02/23/2020 - 01/23/1899 = 44225 days (44194 + 8 + 23)
    // 03/23/2020 - 01/23/1899 = 23 + 29 + 8 + 44194
    // 04/23/2020 - 01/23/1899 = 23 + 31 + 29 + 8 + 44194
    // 05/23/2020 - 01/23/1899 = 23 + 30 + 31 + 29 + 8 + 44194
    //step 1: subtract the difference between days (e.g., 1/23 - 1/23 = 0)
    //step 2: determine if (YEAR - 1) is a leap year, add 366 to 0.
    //                  if (YEAR - 1) is NOT a leap year, add 365 to 0.
    //step 3: keep repeating step 2 until YEAR = secondYear

    int remainingDay = 0;
    int calculatingDays = 0;

    while(y1 != y2)
    {
        --y1;
        //std::cout << "calculatingDays = " << calculatingDays << " calculatingDays\ty1 = " << y1 << "\n";
        if(y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
            calculatingDays += 366;
        else if(y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
            calculatingDays += 366;
        else
            calculatingDays += 365;
    }

    std::cout << "\tcalculatingDays = " << calculatingDays << " calculatingDays\n";

    return 0;
}
