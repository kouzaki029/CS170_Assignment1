#include <iostream>

int main()
{
    /*int dayRange = 28 - 1 + 1;
    int monthRange = 12 - 1 + 1;
    int yearRange = 900 - 3000 + 1;*/

    /*int d1 = rand() % dayRange + 1;
    int m1 = rand() % monthRange + 1;
    int y1 = rand() % yearRange + 1;
    int d2 = rand() % dayRange + 1;
    int m2 = rand() % monthRange + 1;
    int y2 = rand() % yearRange + 1;


    while (y2 > y1)
    {
        y2 = rand() % yearRange + 1;
    }*/


    int m1 = 11;
    int d1 = 23;
    int y1 = 2009;
    int m2 = 2;
    int d2 = 8;
    int y2 = 2006;

    std::cout << "newerDate:\t" << d1 << "-" << m1 << "-" << y1 << "\n";
    std::cout << "olderDate:\t" << d2 << "-" << m2 << "-" << y2 << "\n";

    /* 01/23/2020 - 01/23/1899 = 44194 days
     01/23/2021 - 01/23/1899 = 44560 days
     02/23/2020 - 01/23/1899 =                23 + 8 + 44194
     03/23/2020 - 01/23/1899 =           23 + 29 + 8 + 44194
     04/23/2020 - 01/23/1899 =      23 + 31 + 29 + 8 + 44194
     05/23/2020 - 01/23/1899 = 23 + 30 + 31 + 29 + 8 + 44194
     01/24/2020 - 01/23/1899 =
    step 1: subtract the difference between days (e.g., 1/23 - 1/23 = 0)
    step 2: determine if (YEAR - 1) is a leap year, add 366 to 0.
                      if (YEAR - 1) is NOT a leap year, add 365 to 0.
    step 3: keep repeating step 2 until YEAR = secondYear*/

    //the day, month and year are different
    int dayDifference = d1 - d2;

    int remainingDay = 0;
    int leapDays = 0;
    int calculatingDays = 0;

    //days are the same, but the month and year are different
    if (m1 == 2)
    {
        remainingDay = 0;
    }
    if (m1 == 3)
    {
        if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
        {
            remainingDay = (29);
        }
        else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
        {
            remainingDay = (29);
        }
        else
        {
            remainingDay = (28);
        }
    }
    if (m1 == 4)
    {
        if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
        {
            remainingDay = (31 + 29);
        }
        else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
        {
            remainingDay = (31 + 29);
        }
        else
        {
            remainingDay = (31 + 28);
        }
    }
    if (m1 == 5)
    {
        if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
        {
            remainingDay = (30 + 31 + 29);
        }
        else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
        {
            remainingDay = (30 + 31 + 29);
        }
        else
        {
            remainingDay = (30 + 31 + 28);
        }
    }
    if (m1 == 6)
    {
        if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
        {
            remainingDay = (31 + 30 + 31 + 29);
        }
        else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
        {
            remainingDay = (31 + 30 + 31 + 29);
        }
        else
        {
            remainingDay = (31 + 30 + 31 + 28);
        }
    }
    if (m1 == 7)
    {
        if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
        {
            remainingDay = (30 + 31 + 30 + 31 + 29);
        }
        else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
        {
            remainingDay = (30 + 31 + 30 + 31 + 29);
        }
        else
        {
            remainingDay = (30 + 31 + 30 + 31 + 28);
        }
    }
    if (m1 == 8)
    {
        if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
        {
            remainingDay = (31 + 30 + 31 + 30 + 31 + 29);
        }
        else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
        {
            remainingDay = (31 + 30 + 31 + 30 + 31 + 29);
        }
        else
        {
            remainingDay = (31 + 30 + 31 + 30 + 31 + 28);
        }
    }
    if (m1 == 9)
    {
        if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
        {
            remainingDay = (31 + 31 + 30 + 31 + 30 + 31 + 29);
        }
        else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
        {
            remainingDay = (31 + 31 + 30 + 31 + 30 + 31 + 29);
        }
        else
        {
            remainingDay = (31 + 31 + 30 + 31 + 30 + 31 + 28);
        }
    }
    if (m1 == 10)
    {
        if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
        {
            remainingDay = (30 + 31 + 31 + 30 + 31 + 30 + 31 + 29);
        }
        else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
        {
            remainingDay = (30 + 31 + 31 + 30 + 31 + 30 + 31 + 29);
        }
        else
        {
            remainingDay = (30 + 31 + 31 + 30 + 31 + 30 + 31 + 28);
        }
    }
    if (m1 == 11)
    {
        if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
        {
            remainingDay = (31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + 29);
        }
        else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
        {
            remainingDay = (31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + 29);
        }
        else
        {
            remainingDay = (31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + 28);
        }
    }
    if (m1 == 12)
    {
        if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
        {
            remainingDay = (30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + 29);
        }
        else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
        {
            remainingDay = (30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + 29);
        }
        else
        {
            remainingDay = (30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + 28);
        }
    }

    //days and months are the same, but the year is different
    while (y1 != y2)
    {
        --y1;
        /*DEBUG PURPOSES: std::cout << "leapDays = " << leapDays << " leapDays\ty1 = " << y1 << "\n";*/
        if (y1 % 4 == 0 && y1 % 100 == 0 && y1 % 400 == 0)
            leapDays += 366;
        else if (y1 % 4 == 0 && y1 % 100 != 0 && y1 % 400 != 0)
            leapDays += 366;
        else
            leapDays += 365;
    }
    calculatingDays = remainingDay + leapDays;

    std::cout << "\tdayDifference = " << dayDifference << "\n";
    std::cout << "\tremainingDay = " << remainingDay << "\n";
    std::cout << "\tleapDays = " << leapDays << "\n";
    std::cout << "\tcalculatingDays = " << calculatingDays << "\n";

    return 0;
}
