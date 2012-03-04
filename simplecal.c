#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

//Convert a date into the number of days from Jan 1 1980.
int num(int year, int month, int day)
{
    year += month/12;
    month = month % 12;

    int i,n;

    int dayMon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    n = (year - 1980)*365
        + (year - 1977)/4
        - (year - 2001)/100
        + (year - 2001)/400;

    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        dayMon[1]++;

    for(i = 0; i < month; i++)
        n += dayMon[i];

    return n + day;
}






//Determine the day of the week. The 1 is there because it needs to be.
int dow(int num)
{
    return (num + 1) % 7;
}




//Convert a the number of days from Jan 1 1980 to the day number
int num2day(int num)
{
    int n;

    int dayMon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

//  (y-1980) * 365 + (y-1977)/4 - (y-2001)/100 + (y-2001)/400 < num
//  solve for y:
    int y = 100*(4*num + 2892717) / 146097;


    num -= ((y - 1980) * 365 + (y-1977)/4 - (y-2001)/100 + (y-2001)/400);

    if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
       dayMon[1]++;


    n = 0;

    while(num > 0)
        num -= dayMon[n++];
    num +=dayMon[--n];

    return num;
}





//default date, todays date
int todaysDate(void)
{
    struct tm *t;
    time_t now;
    time(&now);
    t=localtime(&now);

    return num(t->tm_year + 1900, t->tm_mon, t->tm_mday);
}






int print(int, int, char**);

int main(int argc, char **argv)
{
    int initDay;
    if(argc == 4)
        initDay = num(atoi(argv[1]), atoi(argv[2]) - 1, atoi(argv[3]));
    else
        initDay = todaysDate();

    print(initDay, argc, argv);

    return 0;
}
