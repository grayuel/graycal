#include <stdio.h>

int leapYear(int year)
{
    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        return 29;
    else
        return 28;
}
