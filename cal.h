#ifndef CAL_H
#define CAL_H

#define GRAY "\033[0;37m"
#define WHITE "\033[0;97m"

#define GREEN "\033[0;32m"
#define bGREEN "\033[0;92m"

#define RESET "\033[0m"

#define LENGTH 30

#define CDGRAY "${color}"
#define CLGRAY "${color #707070}"
#define CHIGHLIGHT "${color #e04613}"

int output[6][7];

int leapYear(int);
void makeOutput(int, int, int, int);
void printOutput(char*, int);
void monthlyOutput(int, int, int, int);
#endif
