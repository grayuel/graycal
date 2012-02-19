#include <stdio.h>
#include "cal.h"

void printOutput(char *colors, int wday)
{
    int i,j;
    extern int output[6][7];

    char dayw[7][7] = {"Sun", "Mon", "Tue",
                "Wed", "Thu", "Fri", "Sat"};

    char *titleColor = colors;
    char *daysColor = colors + LENGTH;
    char *todayColor = colors + 2*LENGTH;
    char *reset = colors + 3*LENGTH;

    printf("%s",titleColor);
    for(i = 0; i < 7; i++)
        printf("%s ",dayw[i]);
    printf("\n");

    for(j = 0; j < 5; j++) {
        for(i = 0; i < 7; ++i)
            if(j == 0 && i == wday)
                printf("%s %2d %s", todayColor, output[j][i], daysColor);
            else if(output[j][i] != 0)
                printf(" %2d ",output[j][i]);
            else
                printf("    ");
        printf("\n");
    }
    printf("%s", reset);
}
