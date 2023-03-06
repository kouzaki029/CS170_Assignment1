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


    //m1, d1, and y1 are for the newer date
    int m1 = 1;
    int d1 = 24;
    int y1 = 2020;
    //m2, d2, and y2 are for the older date
    int m2 = 1;
    int d2 = 23;
    int y2 = 1899;

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
        /*DEBUG PURPOSES: std::cout << "yearDifference = " << yearDifference << " yearDifference\ty1 = " << y1 << "\n";*/
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

    return 0;
}
