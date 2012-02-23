#include <stdio.h>
#include "cal.h"

int calculateWday(int, int);

void calculateMonth(int year,int month,int day, int howMany)
{
    int wday;

    int i,j,k,count;

    int m;
    int y = year;

    int todayReached = 0;

    int num = 0;

    const char *monthNames[] = {"January", "February", "March", "April",
                                "May", "June", "July", "August",
                                "September", "October", "November", "December"};

    int daymon[12] = {31,leapYear(year),31,30,31,30,31,31,30,31,30,31};

    char *titleColor = GRAY;
    char *todayColor = GREEN;
    char *futureColor = WHITE;

    if(howMany <= 1)
        howMany = 1;

    printf("%s",titleColor);

    for(k = 1; k <= howMany; k++)
    {

        m = (month -1 + k)%12;
        if((month -1 +k) >= 12) {
            if(num == 0) {
                y++;
                num = 11;
            }
            else
                num--;
        }

        printf("      %s %d\n", monthNames[m], y);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");
        wday = calculateWday(m, y);
        for(i = 0; i < wday; i++)
            printf("    ");

        for(i = wday; i < 7; i++) {
            if(todayReached || count +1 != day)
                printf(" %2d ", ++count);
            else {
                printf("%s %2d %s", todayColor, ++count, futureColor);
                todayReached = 1;
            }
        }
        printf("\n");

        for(j = 1; count < daymon[m]; j++) {
            for(i = 0; i < 7 && count < daymon[m]; i++)
                if(todayReached || count +1 != day)
                    printf(" %2d ", ++count);
                else {
                    printf("%s %2d %s", todayColor, ++count, futureColor);
                    todayReached = 1;
                }
            printf("\n");
            j++;
        }
    count = 0;
    printf("\n");
    }
}

int calculateWday(int month, int year)
{
        //Tomohiko Sakamoto's algorithm for finding the day of week
        const int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
        year -= (month + 1) < 3;
        return (year + year/4 - year/100 + year/400 + t[month] + 1) % 7;
}
