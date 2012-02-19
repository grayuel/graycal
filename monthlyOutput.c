#include <stdio.h>
#include "cal.h"

void monthlyOutput(int year, int wday, int month, int day)
{
    extern int output[6][7];

    int i;
    int j = 0;

    int daymon[12] = {31,leapYear(year),31,30,31,30,31,31,30,31,30,31};

    for(i = (wday-day%7); i < 7; i++) {
        output[0][i] = j++;
    }
    for (j = 1; j < 5; j++) {
        for( i = 0; i < 7; i++)
            if(output[j-1][6] + 1 + i > daymon[month])
                ;
            else
                output[j][i] = output[j-1][6] + i + 1;
    }
}
