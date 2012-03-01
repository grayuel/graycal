#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define GRAY "${color2}"
#define WHITE "${color0}"
#define GREEN "${color1}"

//#define GRAY "\033[0;37m"
//#define WHITE "\033[0;97m"
//#define GREEN "\033[0;32m"
#define RESET "\033[0m"

//Convert a date into the number of days from Jan 1 1980.
int num(int year, int month, int day)
{
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
    int y = 1980;
    while((y-1980) * 365 + (y-1977)/4 - (y-2000)/100 + (y-2000)/400 < num)
        y++;
    y--;

    num -= ((y - 1980) * 365 + (y-1977)/4 - (y-2000)/100 + (y-2000)/400);

     if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
        dayMon[1]++;


    n = 0;

    while(num > 0)
        num -= dayMon[n++];
    num +=dayMon[--n];

    return num;
}


void print(int count, int initDay)
{
    int i;
    int todayReached = 0;

    char *todayColor = GREEN;
    char *titleColor = GRAY;
    char *futureColor = WHITE;
    char *reset = RESET;


    printf("%sSun Mon Tue Wed Thu Fri Sat\n", titleColor);

    for(i = 0; i < 35; i++) {
        if(!todayReached && dow(initDay) == dow(count)) {
            printf("%s %2d %s", todayColor, num2day(count), futureColor);
            todayReached = 1;
        }
        else
            printf(" %2d ", num2day(count));

        if(dow(count++) == 6)
            printf("\n");
    }
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

int main(int argc, char *argv[])
{
    int initDay;

    if(argc == 4 && isdigit(argv[1][0]) 
                    && isdigit(argv[2][0]) 
                        && isdigit(argv[3][0]))
        initDay = num(atoi(argv[1]), atoi(argv[2])-1, atoi(argv[3]));
    else {
        initDay = todaysDate(); 
    }

    int count = initDay - dow(initDay);

    print(count, initDay);

    return 0;
}
