#ifndef CAL_H
#define CAL_H

#define GRAY "\033[0;37m"
#define WHITE "\033[0;97m"

#define GREEN "\033[0;32m"
#define bGREEN "\033[0;92m"

#define RESET "\033[0m"

#define LENGTH 30

#define CDGRAY "${color2}"
#define CLGRAY "${color0}"
#define CHIGHLIGHT "${color1}"

int output[6][7];

void calculateMonth(int, int, int, int);
int leapYear(int);
void makeOutput(int, int, int, int);
void printOutput(char*, int, int);
//void monthlyOutput(int, int, int, int);
#endif
