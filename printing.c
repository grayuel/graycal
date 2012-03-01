#include <stdio.h>

#define CGRAY "${color2}"
#define CWHITE "${color0}"
#define CGREEN "${color1}"
#define CRESET "${color0}"

#define GRAY "\033[0;37m"
#define WHITE "\033[0;97m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

void printHeading(char *titleColor)
{
    printf("%sSun Mon Tue Wed Thu Fri Sat\n", titleColor);
}

void printWeeks(int count, int initDay, char *todayColor, char *futureColor, char *reset)
{
    int i;
    int todayReached = 0;

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
    printf("%s", reset);
}

void print(int count, int initDay, int outType)
{
    char *todayColor = GREEN;
    char *titleColor = GRAY;
    char *futureColor = WHITE;
    char *reset = RESET;
    printHeading(titleColor);
    printWeeks(count, initDay, todayColor, futureColor, reset);
}
