#include <stdio.h>
#include "cal.h"

void printOutput(char *colors, int wday, int day)
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

    int lines = 5;
    if(output[5][6] == 0 && output[5][0] != 0)
        lines = 6;

    int check = 0;

    for(j = 0; j < lines; j++) {
        for(i = 0; i < 7; ++i)
            if(check == 0 && output[j][i] == day) {
                printf("%s %2d %s", todayColor, output[j][i], daysColor);
                check++;
            }
            else if(output[j][i] != 0)
                printf(" %2d ",output[j][i]);
            else
                printf("    ");
        printf("\n");
    }
    printf("%s", reset);
}
