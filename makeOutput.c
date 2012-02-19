#include <stdio.h>
#include "cal.h"

void makeOutput(int year, int wday, int month, int day)
{
    extern int output[6][7];
    int i, j;
    int daymon[12] = {31,leapYear(year),31,30,31,30,31,31,30,31,30,31};

// first line
    for(i = 0; i < 7; i++) {
        if(day - wday + i <=0)
            if(month != 0)
                output[0][i] = daymon[month - 1] + (day - wday + i);
            else
                output[0][i] = daymon[12] + (day - wday + i);
        else
            output[0][i] = day - wday + i;
    }

// rest of lines
    for (j = 1; j < 5; j++) {
        for( i = 0; i < 7; i++)
            if(output[j-1][6] + 1 + i > daymon[month])
                output[j][i] = output[j-1][6] + 1 + i - daymon[month];
            else
                output[j][i] = output[j-1][6] + 1 + i;
    }

}
