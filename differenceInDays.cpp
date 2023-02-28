#include <iostream>

int main()
{
    int d1 = 23;
    int m1 = 10;
    int y1 = 2020;
    int d2 = 23;
    int m2 = 01;
    int y2 = 1899;

    // 01/23/2020 - 01/23/1899 = 44194 days
    // 01/23/2021 - 01/23/1899 = 44560 days
    // 02/23/2020 - 01/23/1899 =                23 + 8 + 44194
    // 03/23/2020 - 01/23/1899 =           23 + 29 + 8 + 44194
    // 04/23/2020 - 01/23/1899 =      23 + 31 + 29 + 8 + 44194
    // 05/23/2020 - 01/23/1899 = 23 + 30 + 31 + 29 + 8 + 44194
    //step 1: subtract the difference between days (e.g., 1/23 - 1/23 = 0)
    //step 2: determine if (YEAR - 1) is a leap year, add 366 to 0.
    //                  if (YEAR - 1) is NOT a leap year, add 365 to 0.
    //step 3: keep repeating step 2 until YEAR = secondYear

    int remainingDay = 0;
    int leapDays = 0;
    int calculatingDays = 0;

    //days are the same, but the month and year are different
    if(m1 == 2)
    {
        remainingDay = ( (d1) + (31-d1) );
    }
    if (m1 == 3)
    {
        remainingDay = ( (d1) + 29 + (31-d1) );
    }
    if (m1 == 4)
    {
        remainingDay = ( (d1) + 31 + 29 + (31-d1) );
    }
    if (m1 == 5)
    {
        remainingDay = ( (d1) + 30 + 31 + 29 + (31-d1) );
    }
    if (m1 == 6)
    {
        remainingDay = ( (d1) + 31 + 30 + 31 + 29 + (31-d1) );
    }
    if (m1 == 7)
    {
        remainingDay = ( (d1) + 30 + 31 + 30 + 31 + 29 + (31-d1) );
    }
    if (m1 == 8)
    {
        remainingDay = ( (d1) + 31 + 30 + 31 + 30 + 31 + 29 + (31-d1) );
    }
    if (m1 == 9)
    {
        remainingDay = ( (d1) + 31 + 31 + 30 + 31 + 30 + 31 + 29 + (31-d1) );
    }
    if (m1 == 10)
    {
        remainingDay = ( (d1) + 30 + 31 + 31 + 30 + 31 + 30 + 31 + 29 + (31-d1) );
    }
    if (m1 == 11)
    {
        remainingDay = ( (d1) + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + 29 + (31-d1) );
    }
    if (m1 == 12)
    {
        remainingDay = ( (d1) + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + 29 + (31-d1) );
    }

    //days and months are the same, but the year is different
    while(y1 != y2 )
    {
        --y1;
        //std::cout << "calculatingDays = " << calculatingDays << " calculatingDays\ty1 = " << y1 << "\n";
        if(y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
            leapDays += 366;
        else if(y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
            leapDays += 366;
        else
            leapDays += 365;
    }
    calculatingDays = remainingDay + leapDays;

    std::cout << "\tremainingDay = " << remainingDay << "\n";
    std::cout << "\tleapDays = " << leapDays << "\n";
    std::cout << "\tcalculatingDays = " << calculatingDays << "\n";

    return 0;
}
